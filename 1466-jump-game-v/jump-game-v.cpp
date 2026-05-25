class Solution {
public:
    int dp[1001] ;
    int maxJumps(vector<int>& arr, int d) {
        // let dp[i] represent the maximum number of steps required to reach tower i

        vector<pair<int,int>> temp ;
        int n = arr.size() ;

        for(int i = 0 ;i < n ;i++ ){
            temp.push_back(make_pair(arr[i], i)) ;
            dp[i] = 1 ;
        }

        sort(temp.rbegin(), temp.rend()) ;
        
        for(int i = 0 ; i < n ;i++ ){
            int idx = temp[i].second , val = temp[i].first ;
            int maxi = val ;

            for(int j = idx - 1 ; j >= max(0, idx - d) ; j-- ){
                if(arr[j] > maxi){
                    dp[idx] = max(dp[idx], dp[j] + 1) ;
                    maxi = arr[j] ;
                }
            } 
            

            maxi = val ;

            for(int j = idx + 1 ; j <= min(idx + d, n - 1) ; j++ ){
                if(arr[j] > maxi){
                    dp[idx] = max(dp[idx], dp[j] + 1) ;
                    maxi = arr[j] ;
                }
            }     
        }

        int res = 0 ;
        for(int i = 0 ;i < n ;i++ ){
            // cout << dp[i] << " " ;
            res = max(res, dp[i]) ;
        }

        return res;
    }
};