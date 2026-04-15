class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size() ;

        // dp[i] states the minimum number of jumps to reach index i from 0

        vector<int> dp(n, 1e8) ;
        dp[0] = 0 ;
        for(int i = 1 ; i < n ;i++ ){
            for(int j = 0; j < i ; j ++ ){
                if(j + nums[j] >= i) dp[i] = min(dp[i], dp[j] + 1) ;
            }
        }
        return dp[n - 1] ;
    }
};