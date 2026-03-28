class Solution {
public:
    string findTheString(vector<vector<int>>& a) {
        int n = a.size() ;

        // for(int i = 0 ; i <n ;i++ ){
        //     for(int j = 0 ; j < n ;j++ ){
        //         if(a[i][j] != a[j][i]) return "-1" ;
        //     }
        // }

        // for(int i = 0 ; i < n;i++ ){
        //     if(a[i][j] != n - i) return "-1" ;
        // }

        int num = 1 ;
        vector<int> res(n, -1) ;
        for(int j = n - 1; j >= 0; j-- ){
            if(res[j] == -1) {
                res[j] = num ;
                if(num == 27) return "" ;
                num ++ ;
            }
            
            for(int i = j - 1 ; i >= 0 ; i-- ){
                if(a[i][j] > 0) {
                    if(res[i] == -1) res[i] = res[j] ;
                    else if(res[i] != res[j]) return "" ;
                }
            }
        }

        // for(auto it : res) {
        //     cout << it << " " ;
        // }



        // forming lcp 

        vector<vector<int>> dp(n, vector<int>(n, -1)) ;

        for(int i = 0 ; i < n ; i++ ){
            if(res[i] == res[n - 1]) {
                dp[i][n - 1] = 1 ;
                dp[n - 1][i] = 1 ;
            }
            else {
                dp[i][n - 1] = 0 ;
                dp[n - 1][i] = 0 ;
            }
        }

        // populate the dp table 

        for(int i = n - 2 ; i >= 0 ; i-- ){
            for(int j = n - 2 ; j >= 0 ;j-- ){
                if(res[i] == res[j]) dp[i][j] = dp[i + 1][j + 1] + 1 ;
                else dp[i][j] = 0 ;
            }
        }

        // for(int i = 0 ; i <n ;i++ ){
        //     for(int j = 0 ;j < n ;j++ ){
        //         cout << dp[i][j] << " " ;
        //     }

        //     cout<< endl;
        // }

        if(dp != a) return "" ;

        // Forming the final string ;

        map<int,char> mpp ;
        string ans ;
        char c = 'a' ;
        for(int i = 0 ; i < n ;i++ ){
            if(mpp.count(res[i])){
                ans.push_back(mpp[res[i]]) ;
            } else {
                mpp[res[i]] = c++ ;
                ans.push_back(mpp[res[i]]) ;
            }
        }

        return ans ;
           


    }
};