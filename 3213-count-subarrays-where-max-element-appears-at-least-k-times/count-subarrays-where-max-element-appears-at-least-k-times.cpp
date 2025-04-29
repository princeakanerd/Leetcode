class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0 ;

        int maxi = *max_element(nums.begin() , nums.end()) ;
        int i = 0 , n = nums.size(), count = 0 ;
        for(int j = 0 ; j < n ; j++ ) {
            count += (nums[j] == maxi) ;

            while(i <= j && count >= k) {
                count -= (nums[i] == maxi) ;
                i ++ ;
            }
            ans += i ;
        }
        return ans ;
    }
};