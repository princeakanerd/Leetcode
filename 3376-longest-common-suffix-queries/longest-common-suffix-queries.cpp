class Solution {
public:
    const unsigned long long p = 313 ;
    unsigned long long parr[5005];
    
    // Struct to hold hash data temporarily for sorting
    struct HashEntry {
        unsigned long long hash;
        int rank; // Determines which string is 'better' based on prior sorting
        int orig_idx;
        
        bool operator<(const HashEntry& other) const {
            if (hash != other.hash) return hash < other.hash;
            return rank < other.rank; // If hashes collide, the better rank wins
        }
    };

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        
        int c_size = wordsContainer.size();
        int q_size = wordsQuery.size();
        
        for(int i = 0 ;i < c_size; i++ ){
            reverse(wordsContainer[i].begin(), wordsContainer[i].end()) ;
        }
        for(int i = 0 ; i < q_size; i++ ){
            reverse(wordsQuery[i].begin(), wordsQuery[i].end()) ;
        }
        
        unsigned long long val = 1 ;
        for(int i = 0 ;i < 5005 ; i++ ){
            parr[i] = val ;
            val = val * p ; 
        }

        vector<pair<string,int>> v ;
        v.reserve(c_size);
        for(int i = 0 ;i < c_size; i++ ){
            v.push_back({wordsContainer[i], i}) ;
        }
        
        // Sorting guarantees smaller length and earlier original index come first
        sort(v.begin(), v.end(), [](const pair<string,int> &s1, const pair<string,int> &s2){
            if(s1.first.length() != s2.first.length() ) return s1.first.length() < s2.first.length() ;
            return s1.second < s2.second ;
        });

        // 1. Generate all prefix hashes into a contiguous array
        vector<HashEntry> flat_map;
        flat_map.reserve(500005); 
        
        for(int m = 0 ; m < c_size ; m++ ){
            const string& s = v[m].first ;
            int n = s.length() ;
            unsigned long long current_hash = 0 ;
            
            for(int i = 0 ; i < n ; i++ ){
                current_hash = current_hash + (s[i] - 'a' + 1) * parr[i] ;
                flat_map.push_back({current_hash, m, v[m].second});
            }
        }
        
        // 2. Sort the array. All identical hashes will be grouped together.
        sort(flat_map.begin(), flat_map.end());
        
        // 3. Compress into a fast dictionary, keeping only the best match per hash
        vector<pair<unsigned long long, int>> fast_dict;
        fast_dict.reserve(flat_map.size());
        
        for(int i = 0; i < flat_map.size(); i++) {
            // Because we sorted by rank, the first time we see a hash, it is the optimal one
            if(i == 0 || flat_map[i].hash != flat_map[i - 1].hash) {
                fast_dict.push_back({flat_map[i].hash, flat_map[i].orig_idx});
            }
        }

        // 4. Query Resolution
        vector<int> res(q_size, -1) ;
        unsigned long long queryhash[5005]; 
        queryhash[0] = 0;

        for(int j = 0 ; j < q_size; j++){
            const string& s = wordsQuery[j] ;
            int n = s.length() ;
            
            for(int i = 0 ; i < n ; i++ ){
                queryhash[i + 1] = queryhash[i] + (s[i] - 'a' + 1) * parr[i] ;
            }
            
            int ans = v[0].second; // Default fallback if no prefix matches
            
            // Loop from longest prefix down to 1
            for(int i = n ; i >= 1; i-- ){ 
                unsigned long long target = queryhash[i];
                
                // Binary search lookup in O(log N) utilizing contiguous cache
                auto it = lower_bound(fast_dict.begin(), fast_dict.end(), target,
                    [](const pair<unsigned long long, int>& a, unsigned long long val) {
                        return a.first < val;
                    });
                    
                if(it != fast_dict.end() && it->first == target){
                    ans = it->second ;
                    break ;
                }
            }
            res[j] = ans ;
        }

        return res ;
    }
};