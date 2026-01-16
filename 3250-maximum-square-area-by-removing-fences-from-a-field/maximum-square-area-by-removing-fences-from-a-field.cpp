class Solution {
    const int mod = 1e9 + 7 ;
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        if(m == n) return (m - 1) * (n -1) ;
        long long res = -1 ;
        h.push_back(m) ;
        h.push_back(1) ;
        v.push_back(1) ;
        v.push_back(n) ;
        
        sort(h.begin(), h.end()) ;
        sort(v.begin(), v.end()) ;
        unordered_map<int,int> mpp1, mpp2 ;
        for(int i = 0 ; i < h.size(); i++ ){
            for(int j = i + 1 ;j < h.size(); j++){
                mpp1[h[j] - h[i]] ++ ;
            }
        }
        for(int i = 0 ; i < v.size(); i++ ){
            for(int j = i + 1 ;j < v.size(); j++){
                mpp2[v[j] - v[i]] ++ ;
            }
        }

        for(auto it : mpp1){
            if(mpp2[it.first]) res = max(res, 1LL * it.first * it.first) ;
        }

        if(res <= 0) return -1 ;
        return res % mod ;

    }
};