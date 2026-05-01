class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int i = 0 ;

        int n= nums.size() ;

        long long sum1 = nums[0], sum2 = 0 ;
        int idx = -1 ;
        for(int i = 1 ;i < n ;i++ ){
            if(nums[i] > nums[i - 1]) sum1 += nums[i] ;
            else{
                idx = i ;
                sum2 = nums[i - 1] ;
                break ;
            }
        }

        for(int i = idx ; i < n ;i++ ){
            sum2 += nums[i] ;
        }

        if(sum1 == sum2) return -1 ;

        if(sum1 > sum2) return 0 ;
        return 1;

        
    }
};