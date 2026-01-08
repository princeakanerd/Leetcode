class Solution {
    using ll = long long ;
public:

    int f(int i1, int i2 , vector<int>&nums1, vector<int>&nums2, int picked, vector<vector<vector<ll>>> &dp){
        if(i1 == nums1.size() || i2 == nums2.size()){
            if(picked) return 0 ;
            return INT_MIN ;
        }
        if(dp[i1][i2][picked] != INT_MIN) return dp[i1][i2][picked];
        ll a = 1LL * nums1[i1] * nums2[i2] + f(i1 + 1, i2 + 1, nums1, nums2, 1, dp) ;
        ll b = f(i1 + 1, i2, nums1, nums2, picked, dp) ;
        ll c = f(i1, i2 + 1, nums1,nums2, picked, dp);

        return dp[i1][i2][picked] = max({a, b, c}) ;
        
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , n2 = nums2.size() ;
        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n2 + 1, vector<ll>(2, INT_MIN))) ;
        return f(0, 0, nums1, nums2, 0, dp) ;
    }
};