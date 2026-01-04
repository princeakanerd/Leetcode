class Solution {
    using ll = long long ;
public:

    int f(int num){
        long long cnt = 0, sum = 0 ;

        for(long long i = 1 ;i * i <= num ;i++ ){
            if(num % i == 0) {
                cnt ++ ;
                sum += i ;
                if(num / i != i) {
                    cnt ++ ;
                    sum += num / i ;
                }
            }
        }
        if(cnt == 4) return sum ;
        return 0 ;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size() ;   
        int res = 0 ;

        for(int i = 0 ; i < n ;i++ ){
            res += f(nums[i]) ;
        }

        return res ;
    }
};