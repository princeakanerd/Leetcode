class Solution {
    using ll = long long ;
public:
    ll comp(int li, int lj, int ri, int rj, vector<int>&nums) {
        long long mini = 0 ;

        cout << li << " " << lj << " " << ri << " " << rj << endl;
        ll sum = 0 ;
       
        for(int i = li ; i <= lj - 2; i++ ){
            sum += nums[i] ;
            mini = min(sum, mini) ;
        }
      
        for(int i = lj - 1 ; i <= ri; i++ ){
            sum += nums[i] ;
        }
        ll res = -1e15 ;
        for(int i = ri + 1 ; i <= rj ;i++ ){
            sum += nums[i] ;
            res = max(res, sum - mini) ;
        }
        return res;
    }

    ll f(vector<pair<ll,ll>> &u, vector<int> &nums){
        ll res = -1e15  ;
        int usize = u.size() ;
        for(int i = 1 ; i < u.size(); i++){
            res = max(res, comp(u[i - 1].first, u[i - 1].second, u[i].first, u[i].second, nums)) ;
        }
        return res;
    }
    long long maxSumTrionic(vector<int>& nums) {
        ll n = nums.size() ;
        vector<pair<ll,ll>> u ;
        ll start = -1 ;
        bool up = false ;
        vector<ll>pfx(1, 0) ;
        ll ans = -1e15 ;
        for(int i = 0 ;i < n ;i++ ){
            pfx.push_back(nums[i] + pfx.back()) ;
        }
        for(int i = 1 ; i < n ;i++ ){
            if(nums[i] == nums[i - 1]){
                if(up){
                    u.push_back(make_pair(start, i - 1)) ;
                    up = false ;
                }
                ans = max(ans, 1LL * f(u, nums)) ;
                u.clear() ;
                start = -1 ;
                continue ;
            }

            if(nums[i] > nums[i - 1] && !up ){
                start = i - 1 ;
                up = true ;
            } else if(nums[i] < nums[i - 1] && up){
                u.push_back(make_pair(start, i - 1)) ;
                up = false ;
                start = -1 ;
            }
        }

        if(up){
            u.push_back({start, n - 1}) ;
        }

       
        ans = max(ans, 1LL * f(u , nums)) ;
        return ans;
    }
};