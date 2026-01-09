class Solution {
    using ll = long long ;
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size() ;
        ll maxi = nums.back() ;
        ll val = nums.back() ;
        for(int i = n - 1 ; i > 0 ; i-- ){
            if(nums[i - 1] <= val) val += nums[i - 1] ;
            else val = nums[i - 1] ;
            maxi = max(maxi, 1LL * val) ;
        }

        return maxi ;
    }
};