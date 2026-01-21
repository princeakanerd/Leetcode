class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> ans(n, -1) ;

        for(int i = 0 ; i < n ;i++ ){
            if(nums[i] == 2) ans[i] = -1 ;
            else {
                int num = nums[i] ;
                int cnt = 0 ;
                while(num && num % 2){
                    num /= 2;
                    cnt ++ ;
                }

                ans[i] = nums[i] - (1<<(cnt -1)) ;
            }
        }
        return ans;
    }
};