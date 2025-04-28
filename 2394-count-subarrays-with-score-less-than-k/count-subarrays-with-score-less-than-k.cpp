class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0 , ans = 0 ;
        int n = nums.size() ;
        int i = 0 ;
        
        for(int j = 0 ;j < n ; j++ ) {
            sum += nums[j] ;

            while(i <= j && sum * (j - i + 1) >= k) {
                sum -= nums[i] ;
                i ++ ;
            }
            ans += j - i + 1 ;
        }
        
        return ans ;



    }
};