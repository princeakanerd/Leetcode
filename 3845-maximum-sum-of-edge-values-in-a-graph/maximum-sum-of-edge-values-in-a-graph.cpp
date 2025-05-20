class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
        long long val = 0 ;
        if(n == 1) return 1 ;

        for(long long i = 1 ; i + 2 <= n ; i+= 2) {
            val += i * (i + 2) ;
        }
        for(long long i = 2 ; i + 2 <= n ; i+= 2){
            val += i * (i + 2) ;
        }
        val += 1LL * n * (n - 1)  ;

        if(edges.size() == n) val += 2LL ;

        return val ;
    }
};