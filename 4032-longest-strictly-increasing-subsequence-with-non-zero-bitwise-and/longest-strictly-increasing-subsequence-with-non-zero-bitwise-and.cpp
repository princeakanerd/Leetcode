class Solution {
    using ll = long long ;
public:
    int f(vector<int>& nums){

        vector<int> tails ;
        for(int i = 0 ; i < nums.size(); i++ ){
            auto it = lower_bound(tails.begin(), tails.end(), nums[i]) ;
            if(it == tails.end()) tails.push_back(nums[i]) ;
            else *it = nums[i] ;
        }

        return (int)tails.size() ;
    }
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size() ;
        int res = 0 ;
        for(int i = 0 ; i <= 31 ;i++ ){
            vector<int> temp ;
            ll num = (1LL << i) ;
            for(int j = 0 ; j < n ;j++ ){
                if(nums[j] & num) temp.push_back(nums[j]) ;
            }
            res = max(res, f(temp)) ;
        }
        return res;
    }
};