class Solution {
    using ll = long long ;
    const int mod = 1e9 + 7 ;
public:
    int f(int i , int n ,int preva, int prevb, int prevc, vector<vector<vector<vector<int>>>> &dp){
        if(i == n) return 1 ;
        if(dp[i][preva][prevb][prevc] != -1) return dp[i][preva][prevb][prevc] ;
        
        int ways = 0 ;
        for(int a = 1 ; a <= 3 ;a++){
            for(int b = 1 ; b <= 3 ; b++ ){
                for(int c = 1 ; c <= 3 ; c++ ){
                    if(a == b || b == c ) continue ;
                    if(i > 0 && (a == preva || b == prevb || c == prevc)) continue ;
                    ways = (ways +  f(i + 1,n, a, b, c, dp)) % mod ;
                }
            }
        }

        return dp[i][preva][prevb][prevc] = ways ;
        
    }
    int numOfWays(int n) {
     vector<vector<vector<vector<int>>>> dp (n, vector<vector<vector<int>>>(4, vector<vector<int>>(4, vector<int>(4, -1)))) ;
     return f(0, n, 0, 0 , 0, dp) ;

    }
};