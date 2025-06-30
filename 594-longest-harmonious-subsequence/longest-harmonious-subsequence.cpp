class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0 ;

        int i = 0 ;
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;
        for(int j = 0 ; j < n ; j++ ) {
            while(nums[j] - nums[i] > 1) i ++ ;
            if(nums[j] - nums[i] == 1) ans = max(j - i + 1 , ans) ;
        }
        return ans ;
    }
};