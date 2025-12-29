class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size() ;
        vector<long long> suff(n) ;

        suff[n - 1] = nums[n - 1] ;

        for(int i = n - 2 ; i >= 0 ;i -- ){
            suff[i] = min(suff[i + 1], 1LL * nums[i]) ;
        }

        long long sum = 0 , res = LLONG_MIN ;
        
        for(int i = 0 ;i < n - 1 ;i++ ){
            sum += nums[i] ;
            res = max(res, sum - suff[i +1]) ;
        }
        return res; 
    }
};