class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0 ;
        int cnt = 0 , ans = 0 ;
        int n = nums.size() ;
        
        for(int j = 0 ;j < n ; j++ ){   
            cnt += (nums[j] == 0) ;
            while(cnt > 1) {
                cnt -= (nums[i] == 0) ;
                i ++ ;
            }
            ans = max(j - i + 1 , ans) ;
        }
        return ans - 1 ;
    }
};