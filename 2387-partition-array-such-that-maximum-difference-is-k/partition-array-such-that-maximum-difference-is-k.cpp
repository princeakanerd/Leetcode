class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end()) ;
        int n = nums.size() ;
        int num = nums[0] ;
        int cnt = 1 ;
        for(int i = 0 ; i < n ; i++ ) {
            if(nums[i] - num > k){
                num = nums[i] ;
                cnt ++ ;
            }
        }
        return cnt ;
    }
};