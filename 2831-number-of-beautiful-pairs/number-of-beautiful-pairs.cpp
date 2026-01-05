class Solution {
public:
    int gcd(int a , int b){
        while(b){
            a %= b ;
            swap(a, b) ;
        }

        return a;
    }
    bool check(int a , int b){
        while(a >= 10){
            a /= 10;
        }

        b = b % 10 ;
        return gcd(a , b) == 1;
    }
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size() ;
        int cnt = 0 ;
        for(int i = 0 ;i < n ;i++ ){
            for(int j = i + 1 ; j < n ;j++ ){
                if(check(nums[i], nums[j])) cnt ++ ;
            }
        }
        return cnt ;
    }
};