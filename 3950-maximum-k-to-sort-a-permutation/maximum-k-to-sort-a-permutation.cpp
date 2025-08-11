class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1 ;

        if(is_sorted(nums.begin() , nums.end())) return 0 ;

        for(int i = 0 ; i < nums.size() ; i++ ){
            if(nums[i] != i){
                k = (k == -1 ? nums[i] : nums[i] & k) ;
            }
        }

        return k;
    }
};