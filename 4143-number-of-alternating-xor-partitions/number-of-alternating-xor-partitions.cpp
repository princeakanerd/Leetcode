class Solution {
    int MOD = 1e9 + 7 ;
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        int n = nums.size() ;
        map<int,int> cnt1, cnt2 ;
        cnt2[0] = 1 ;
        int xorval = 0 ;
        int ways1 = 0 , ways2 = 0 ;
        for(int i = 0 ; i < n ;i++){
            xorval ^= nums[i] ;
            
            ways1 = cnt2[target1 ^ xorval], ways2 = cnt1[target2 ^ xorval];
            // cout << ways1 << " " << ways2 << endl;
            cnt1[xorval] = (cnt1[xorval] + ways1) % MOD ;
            cnt2[xorval] = (cnt2[xorval] + ways2) % MOD ;

            
        }

        return (ways1 + ways2) % MOD ;

    
    }
};