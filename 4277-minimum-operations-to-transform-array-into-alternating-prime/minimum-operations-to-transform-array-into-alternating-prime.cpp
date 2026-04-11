class Solution {
public:
    void sieve(vector<int> &primes, vector<bool> &isprime){
        
        int n = 1e5 + 7 ;
        isprime[0] = isprime[1] = false ;

        for(long long i = 2 ; i <= n ;i++ ){
            if(isprime[i]){
                primes.push_back(i) ;

                for(long long j = i * i ; j <= n ; j += i){
                    isprime[j] = false ;
                }
            }
        }
        
    }
    int minOperations(vector<int>& nums) {
        vector<int> primes ;
        int n = nums.size() ;
        int lim = 1e6 ;
        vector<bool> isprime(lim + 1, true);

        sieve(primes, isprime) ;
        int res = 0 ;
        for(int i = 0 ;i < n ;i++ ){
            if(i % 2){
                if(isprime[nums[i]]){
                    if(nums[i] == 2) res += 2;
                    else res ++ ;
                }
            } else {
                if(!isprime[nums[i]]){
                    int next = *upper_bound(primes.begin(), primes.end(), nums[i]) ;
                    res += next - nums[i] ;
                }
            }
        }

        return res ;


    }
};