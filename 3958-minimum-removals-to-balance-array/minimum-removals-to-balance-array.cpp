class Solution {
    using ll = long long ;
public:
    bool check(ll mid, vector<int> &nums, int k){
        int n = nums.size() ;
        int len = n - mid ;
        for(int i = len - 1 ; i < n ;i++ ){
            if(1LL * nums[i] <= 1LL *  k * nums[i - len + 1]) return true;
        }

        return false ;
    }
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size() ;
        sort(nums.begin(), nums.end()) ;
        ll low = 0, high = n - 1 , ans = -1 ;
        
        while(low <= high){
            ll mid = low + (high - low) / 2;
            // cout << high << " " << low << " " << mid << endl;
            if(check(mid, nums,k)){
                high = mid - 1 ;
                ans = mid ;
            } else low = mid + 1;

        }
        
        return ans;
    }
};