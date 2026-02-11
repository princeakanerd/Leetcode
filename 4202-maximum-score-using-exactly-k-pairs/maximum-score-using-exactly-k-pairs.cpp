class Solution {
    using ll = long long ;
public:
    ll dp[101][101][101];

    ll f(int i , int j , vector<int> &nums1, vector<int> &nums2, int k){
        if(k == 0) return 0 ;
        if(i == nums1.size() || j == nums2.size()) return -1e15 ;
        if(dp[i][j][k] != -2e15) return dp[i][j][k] ;

        ll l = f(i + 1, j,nums1, nums2, k) ;
        ll r = f(i, j + 1, nums1, nums2, k) ;
        ll p = f(i + 1, j + 1, nums1, nums2, k - 1) ;
        if(p != -1e15){
            p += 1LL * nums1[i] * nums2[j] ;
        }
        return dp[i][j][k] = max({l, r, p}) ;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size() ;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                for (int p = 0; p <= k; p++)
                    dp[i][j][p] = -2e15;
        return f(0, 0, nums1, nums2, k) ;
    }
};