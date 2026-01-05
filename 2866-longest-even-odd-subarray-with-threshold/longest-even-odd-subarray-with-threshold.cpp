class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size() ;
        int cnt = 0 , ans = 0 ;
        for(int i = 0; i < nums.size(); i++ ){
            if(nums[i] > threshold){
                cnt = 0 ;
                continue ;
            }
            if(nums[i] % 2 == 0) {
                if(cnt == 0 || (i > 0 && nums[i - 1] % 2 == 1))cnt ++ ;
                else cnt = 1 ;
            } else {
                if(cnt == 0) continue ;
                if(i > 0 && nums[i - 1] % 2 == 0) cnt ++ ;
                else cnt = 0 ;
            }
            ans = max(cnt , ans );
        }
        return ans;
    }
};