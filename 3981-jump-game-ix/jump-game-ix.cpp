class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size() ;

        vector<int> pfxmax(n , nums[0]), sufmin(n ,nums.back()), ans(n) ;
        for(int i = 1 ; i < n ; i++ ){
            pfxmax[i] = max(pfxmax[i - 1] , nums[i]) ;
        }

        for(int i = n - 2; i >= 0 ; i-- ){
            sufmin[i] = min(sufmin[i + 1] , nums[i]) ;
        }   

        ans[n - 1] = pfxmax[n - 1] ;

        for(int i = n - 2 ; i >= 0 ; i-- ){
            ans[i] = pfxmax[i] ;
            if(pfxmax[i] > sufmin[i + 1]) {
                ans[i] = max(ans[i], ans[i + 1]) ;
            }
        }
        return ans ;
        
    }
};