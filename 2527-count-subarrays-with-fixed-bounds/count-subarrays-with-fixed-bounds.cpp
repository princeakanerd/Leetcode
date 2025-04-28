class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0 ;
        multiset<int> st ;

        int n = nums.size() ;
        int i = 0 ;
        int lastmin = -1, lastmax = -1 , start = -1;

        for(int j = 0 ; j < n ; j ++ ) {
            if(nums[j] < minK || nums[j] > maxK) {
                lastmin = - 1, lastmax = -1 , start = -1 ;
            } else {
                if(start == -1) start = j ;
                if(nums[j] == minK) lastmin = j ;
                if(nums[j] == maxK) lastmax = j ;
            }

            if(lastmin != -1 && lastmax != -1){
                ans += min(lastmin ,lastmax) - start + 1 ;
            }
            // ans += max(0 , min(lastmin , lastmax) - start + 1) ;
            
        }
        return ans ;
        
    }
};