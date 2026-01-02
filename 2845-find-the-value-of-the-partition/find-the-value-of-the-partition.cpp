class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int mini = INT_MAX ;
        sort(nums.begin(), nums.end()) ;
        for(int i = 1 ;i < nums.size(); i++ ){
            mini = min(mini,nums[i] - nums[i - 1] ) ;
        }
        return mini ;
    }
};