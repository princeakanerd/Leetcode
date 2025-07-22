class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int , int> mpp ;
        int n = nums.size() ;
        int ans = 0 , sum = 0 ;
        int i = 0 ;
        for(int j = 0 ; j < n ; j++ ){
            mpp[nums[j]] ++ ;
            sum += nums[j] ;
            while(mpp.size() < j - i + 1){
                mpp[nums[i]]-- ;
                sum -= nums[i] ;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]) ;
                i++ ;
            }

            ans = max(sum , ans) ;

        }
        return ans ;
    }
};