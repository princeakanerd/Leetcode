class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {


        int n = nums.size() ;
        if(n % k != 0) return false ;
        int group = n / k ;
        vector<int> mpp(1e5 + 1 , 0) ;
        for(auto it : nums){
            mpp[it] ++ ;
        }

        for(int i = 0 ; i <= 1e5 ; i++ ){
            if(mpp[i] > group ) return false ;
        }
        return true ;
    }
};