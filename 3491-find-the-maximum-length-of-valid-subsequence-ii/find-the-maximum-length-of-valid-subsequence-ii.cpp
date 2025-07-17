class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<vector<int>> dp(k , vector<int> (k , 0)) ;

        for(auto &it : nums) it %= k ;
        int ans = 0 ;
        for(auto it : nums){

            for(int i = 0 ; i < k ; i++){
                dp[it][i] = dp[i][it] + 1;
                ans = max(ans , dp[it][i]) ;
            }
        }

        return ans ;

       

    }
};