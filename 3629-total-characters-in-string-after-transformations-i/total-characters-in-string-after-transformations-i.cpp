class Solution {
public:
    int MOD = 1e9 + 7 ;
    int lengthAfterTransformations(string s, int t) {
        vector<int> nums(26 , 0) ;
        for(auto it : s) nums[it - 'a'] ++ ;

        while(t--) {
            vector<int> temp (26 , 0) ;
            for(int i = 0 ;i < 26 ; i++ ) {
                
                if(i == 25) {
                    temp[0] = (temp[0] + nums[i]) % MOD  , temp[1] = (temp[1] + nums[i]) % MOD ;
                } else {
                    temp[i + 1] = (temp[i + 1] + nums[i]) % MOD ;
                }
            }
            nums = temp ;
        }
        long long ans = 0 ;
        for(int i = 0 ; i < 26 ; i++ ) {
            ans = (ans + nums[i]) % MOD ;
        }   
        return ans ;
    }
};