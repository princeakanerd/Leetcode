class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long res = 0 ;

        long long maxi = INT_MIN, mini = INT_MAX ;

        for(auto it : nums) {
            maxi = max(1ll * it, maxi) ;
            mini = min(1ll * it, mini);
        }
        return k * (maxi - mini) ;
    }
};