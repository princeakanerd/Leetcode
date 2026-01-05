class Solution {
    using ll = long long ;
    const int mod = 1e9 + 7;
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int i = 0 ;
        int n = nums.size() ;

        while(i < n && nums[i] == 0) i++ ;
        if(i == n) return 0 ;
        i++ ;
        ll res = 1 ;
        ll cnt = 0 ;
        for(; i < n ; i++ ){
            if(nums[i] == 0) cnt ++ ;
            else {res = res * (cnt + 1) % mod ; cnt = 0 ;}
        }
        return res ;
        
    }
};