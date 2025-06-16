class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi = -1  , mini = INT_MAX;
        for(int i = 0 ; i < (int)nums.size() ; ++i) {
            if(nums[i] > mini)maxi = max(maxi ,nums[i] - mini) ;
            else mini = nums[i] ;
        }
        return maxi ;
    }
};