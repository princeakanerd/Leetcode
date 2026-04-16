class Solution {
public:
    bool canJump(vector<int>& nums) {
        // dp[i] = true states it is possible to jump uptil that position
        int n = nums.size() ;
        vector<bool> dp(n, false) ;
        dp[0] = true ;

        for(int i = 0; i < n ;i ++ ){
            if(dp[i]){
                for(int j = i + 1; j <= min(i + nums[i], n - 1); j++){
                    dp[j] = true ;
                }
            }
            
        }

        return dp[n - 1] ;
    }
};