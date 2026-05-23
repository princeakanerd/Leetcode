class Solution {
    using ll = long long ;
    const ll p = 1e5 + 3;
    const ll mod = 1e12 + 39 ;
    
public:

    ll binexp(ll a, ll b) {
    ll res = 1;
    
    a %= mod; 
    
    while (b) {
        if (b & 1) {
            res = (ll)((__int128_t)res * a % mod);
        }
                a = (ll)((__int128_t)a * a % mod);
        b >>= 1;
    }
    return res;
}
    bool check(ll k, vector<int> &nums){
        int n =nums.size() ;
        unordered_map<ll,ll> mpp ;
        ll val = 0 ;
        for(int i = 0 ;i < k; i++ ){
            val = (val + nums[i] * binexp(p, k - 1 - i) % mod) % mod ;
        }

        mpp[val] = 1;

        for(int i = k ; i < n ;i++ ){
            val = (val - nums[i - k] * binexp(p, k - 1) % mod + mod) % mod ;
            val = val * p % mod ;
            val = (val + nums[i] ) % mod ;
            mpp[val] ++ ;
        }
        for(auto it : mpp){
            if(it.second == 1) return true ;
        }
        return false;


    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size() ;

        ll low = 1 ,high = n, ans = -1 ;

        while(low <= high){
            ll mid = low + (high -low)/ 2;

            if(check(mid, nums)){
                ans = mid ;
                high = mid - 1 ;
            } else low = mid + 1;
        }

        return ans ;
        
    }
};