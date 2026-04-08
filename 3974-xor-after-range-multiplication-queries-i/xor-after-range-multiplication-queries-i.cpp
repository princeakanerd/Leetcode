class Solution {
    using ll = long long ;
     const int mod = 1e9 + 7 ;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size() ;

        for(int i = 0 ; i < q ; i++ ){
            int l = queries[i][0], r = queries[i][1], k = queries[i][2], v = queries[i][3] ;

            while(l <= r){
                nums[l] = 1ll * nums[l] * v % mod ;
                l += k ;
            }
        }

        int x = 0 ;

        for(auto it : nums) x ^= it ;

        return x ;
    }
};