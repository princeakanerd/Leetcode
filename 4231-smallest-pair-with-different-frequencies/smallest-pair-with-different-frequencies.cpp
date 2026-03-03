class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        sort(nums.begin(), nums.end()) ;
        int n = nums.size() ;
        map<int,int> mpp ;
        for(int i = 0 ; i < n ;i++ ){
            mpp[nums[i]] ++ ;
        }

        vector<int> res ;
        res.push_back(nums[0]) ;

        for(int i = 0 ;i < n ;i++){
            if(mpp[nums[i]] != mpp[nums[0]]){
                res.push_back(nums[i]) ;
                return res ;
            }
        }
        return {-1, -1} ;
    }
};