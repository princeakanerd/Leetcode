class Solution {
public:
    bool isGood(vector<int>& nums) {
        if(nums.size() < 2) return false ;
        sort(nums.begin(), nums.end()) ;
        int n =nums.size() ;
        for(int i= 0 ;i + 1 < nums.size(); i++ ){
            if(nums[i] != i + 1) return false ;
        }

        if(nums.back() != nums[n - 2]) return false ;

        return true ;
    }
};