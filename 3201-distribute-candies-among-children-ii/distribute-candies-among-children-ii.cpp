class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0 ;
        for(int i = 0 ; i <= min(n , limit) ; i++ ) {
            int rem = n - i ;
            if(rem > 2 * limit){
                continue ;
            }

            ans += min(limit , n - i) - max(0 , n - i - limit) + 1 ;
        }
        return ans ;
    }
};