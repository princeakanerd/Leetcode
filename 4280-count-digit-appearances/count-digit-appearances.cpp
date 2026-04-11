class Solution {
public:
    int f(int num, int digit){
        int cnt = 0 ;

        while(num){
            if(digit == num % 10) cnt ++ ;
            num /= 10 ;
        }
        return cnt ;
    }
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size() ;
        int cnt = 0 ;
        for(int i = 0 ; i < n ;i++ ){
             cnt += f(nums[i], digit) ;
        }

        return cnt ;
    }
};