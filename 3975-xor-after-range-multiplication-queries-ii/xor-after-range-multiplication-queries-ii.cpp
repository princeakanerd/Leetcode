class Solution {
    using ll = long long ;
    const int mod = 1e9 + 7 ;
public:

    ll binexp(ll a, ll b){
        ll res = 1 ;
        while(b){
            if(b & 1) res = res * a % mod ;
            a = a * a % mod ;
            b >>= 1;
        }
        return res;
    }
    ll invmod(ll a){
        return binexp(a, mod -2) ;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size() ;
        int rootn = sqrt(n) ;

        vector<vector<vector<int>>> a(rootn) ;
        for(auto it : queries){
            int l = it[0], r = it[1], k = it[2], v = it[3] ;
            if(k >= rootn){
                for(int i = l ; i <= r ; i += k){
                    nums[i] = 1ll * nums[i] * v % mod ;
                }
            } else {
                a[k].push_back({l, r, v}) ;
            }
        }


        for(int k = 1 ; k < rootn ; k++ ){
            if(a[k].empty()) continue ;

            vector<int> diff(2 * n, 1) ;
            for(auto it : a[k]){
                int l = it[0], r = it[1], v = it[2] ;
                diff[l] = 1ll * diff[l] * v % mod ;
                int steps = (r - l)/ k ;
                int end = l + (steps + 1) * k ;
                diff[end] = 1ll * diff[end] * invmod(v) % mod ;
            }
            for(int i = 0 ; i < n ; i++ ){
                if(i - k >= 0 ) diff[i] = 1ll * diff[i] * diff[i - k] % mod ;
                nums[i] = 1ll * nums[i] * diff[i] % mod ;
            }
        }
        int res = 0 ;

        for(auto it : nums) res ^= it ;
        return res ;
    }
};