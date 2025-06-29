class Solution {
public:
    const int MOD = 1e9 + 7 ;
    long long binexp(long long a , long long b) {
        long long res = 1 ;

        while(b) {
            if(b & 1) {
                res = res * a % MOD ;
            }
            a = a * a % MOD ;
            b >>= 1 ;
        }
        return res ;
    }
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size() ;
        int i = 0 , j = n -1 ;
        long long res = 0 ;
        sort(nums.begin() , nums.end()) ;
        while(i <= j) {
            while(i <= j && nums[i] + nums[j] >target) j-- ;

            if(i <= j)  res = (res +  binexp(2 , j - i)) % MOD ;
            i++ ;
        }
        return res ;
    }
};