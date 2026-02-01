class Solution {
    using ll = long long ;
public:
    bool check(ll mid, vector<int>&nums){
        ll cnt = 0 ;
        for(int i = 0 ; i < nums.size(); i++ ){
            cnt += (nums[i] + mid - 1)/ mid ;
        }

        return cnt <= mid * mid ;
    }
    int minimumK(vector<int>& nums) {
        int n = nums.size() ;

        ll low = 1, high = 1e5 , ans = -1 ;

        while(low <= high){
            ll mid = low + (high - low)/ 2;
            if(check(mid, nums)){
                ans = mid ;
                high = mid - 1;
            } else low = mid + 1 ;
        }
        return ans;
    }
};