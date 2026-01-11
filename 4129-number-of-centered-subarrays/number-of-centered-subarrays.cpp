class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size() ;
        int res= 0 ;
        for(int i = 0 ; i < n ;i++ ){
            map<int,int> mpp ;
            int sum = 0 ;

            for(int j = i ; j < n ;j++ ){
                sum += nums[j] ;
                mpp[nums[j]]++ ;
                if(mpp[sum])res ++ ;
            }
        }
        return res;
    }
};