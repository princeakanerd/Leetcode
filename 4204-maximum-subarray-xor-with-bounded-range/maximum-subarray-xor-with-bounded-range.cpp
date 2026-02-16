struct TrieNode {
    TrieNode* children[2];

    // Metadata to track the end of a value or the frequency of a prefix
    bool isEndOfValue; 
    int count; // Optional: Useful if you need to count occurrences or delete

    // Constructor to initialize pointers to nullptr
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
        isEndOfValue = false;
        count = 0;
    }
};

class Trie {
    TrieNode* root ;
    using ll = long long ;
public:
    Trie(){
        root = new TrieNode() ;
    }

    void insert(ll num){
        TrieNode* temp = root ;

            //need to traverse from msb to lsb so
            for(int i = 30 ; i >= 0 ;i-- ){
                ll bit = (num >> i) & 1;
                
                if(temp -> children[bit] == nullptr){
                    TrieNode* node = new TrieNode() ;
                    temp -> children[bit] = node ;
                }

                temp = temp -> children[bit] ;
                temp -> count ++ ;
            }

        
    }
    // assuming that the num alrady exists
    void remove(ll num){
        TrieNode* temp = root ;
        for(int i = 30 ; i >= 0 ;i-- ){
            ll bit = (num >> i) & 1;
            temp = temp -> children[bit] ;
            temp -> count -- ;
        }
    }
    
    ll query(ll num){
        ll res = 0 ;
        TrieNode *temp = root ;
        for(int i = 30 ; i >= 0 ;i-- ){
            ll bit = (num >> i) & 1;
            if(temp -> children[bit] != nullptr && temp -> children[bit] ->count > 0){
                res <<= 1;
                res += bit ;
                temp = temp -> children[bit] ;
            } else if(temp -> children[1 - bit] != nullptr && temp -> children[1 - bit] -> count > 0) {
                res <<= 1;
                res += 1 - bit ;
                temp = temp -> children[1 - bit] ;
            } else return -1 ;
        }
        return res;
        
    }


};
class Solution {
    using ll = long long ;
public:
    int maxXor(vector<int>& nums, int k) {
        Trie t;
        t.insert(0) ;

        int n = nums.size() ;
        ll pfxxor = 0, pfxxorj = 0 ; ;
        int j = 0 ;
        multiset<int> st;
        ll res = 0 ;
        for(int i = 0 ; i < n ;i++ ){
            st.insert(nums[i]) ;
            pfxxor ^= nums[i] ;
            ll maxnum = (1ll << 31) - 1;

            while(*st.rbegin() - *st.begin() > k){
                st.erase(st.find(nums[j])) ;
                t.remove(pfxxorj) ;
                pfxxorj ^= nums[j] ;
                j++ ;
            }
            ll target = pfxxor ^ maxnum ;
            ll qres = t.query(target) ;
            if(qres != -1)
            res = max(pfxxor ^ qres, res) ;
            t.insert(pfxxor) ;
        }
        return res;
    }
};