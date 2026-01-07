class Solution {
public:
    int f(int i , vector<int> &nums, int target, int previdx, vector<vector<int>> &dp){

        if(i + 1 == nums.size() && abs(nums[i] - nums[previdx]) <= target ) return 1;
        if(i == nums.size()) return INT_MIN ;
        if(dp[i][previdx] != -1) return dp[i][previdx] ;
        int l = INT_MIN, r = INT_MIN;
        if(abs(nums[previdx] - nums[i]) <= target){
            l = 1 + f(i + 1, nums, target, i, dp) ;
        }
        r = f(i + 1, nums, target, previdx, dp) ;
        return dp[i][previdx] = max(l, r) ;
    }

    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size() ;
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1)) ;
        int res = f(1, nums, target, 0, dp) ;
        if(res < 0) return -1 ;
        return res ;
    }
};