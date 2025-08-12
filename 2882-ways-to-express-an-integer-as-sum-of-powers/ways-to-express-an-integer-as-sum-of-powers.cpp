class Solution {
public: 
    int MOD = 1e9 + 7;
    int numberOfWays(int n, int x) {
        vector<long long> a;
        for (int i = 1; i <= n; i++) {
            long long val = pow(i, x);
            if (val > n) break; 
            a.push_back(val);
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < a.size(); i++) {
            for (int sum = n; sum >= a[i]; sum--) {
                dp[sum] = (dp[sum] + dp[sum - a[i]]) % MOD;
            }
        }
        return dp[n];
    }
};