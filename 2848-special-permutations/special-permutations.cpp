class Solution {
    const int mod = 1e9 + 7 ;
public:
    int f(int prev, int mask, vector<int>& nums, int count, vector<vector<int>> &dp){
        int n = nums.size() ;
        if(count == n) return 1;
        if(dp[prev][mask] != -1) return dp[prev][mask] ;
        int ways = 0 ;
        for(int i = 0 ;i < n ;i++ ){
            if(mask & (1 << i)) continue ;

            if(mask != 0 && nums[i] % nums[prev] !=0 && nums[prev] % nums[i] != 0) continue ;
            ways = (ways + f(i, mask | (1 << i), nums, count + 1, dp)) % mod  ;
        }
        return dp[prev][mask] = ways ;
    }
    int specialPerm(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>> dp(n , vector<int>((1<<n), -1)) ;
        return f(0,0, nums , 0, dp ) ;
    }
};