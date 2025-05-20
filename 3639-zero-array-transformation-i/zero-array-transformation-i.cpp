class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size() ;
        vector<int> diff(n + 1) ;

        for(auto it : queries) {
            diff[it[0]] -- , diff[it[1] + 1] ++ ;
        }
        int sum = 0 ;
        for(int i = 0 ; i < n ;i++ ) {
            sum += diff[i] ;
            if(sum + nums[i] > 0) return false ;
        }
        return true ;

    }
};