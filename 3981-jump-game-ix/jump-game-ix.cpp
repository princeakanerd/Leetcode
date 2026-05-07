class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size() ;
        int maxi = 0 ;
        vector<int> minarr(n) ;
        int mini = INT_MAX ;

        for(int i = n - 1 ;i >= 0; i-- ){
            mini = min(mini, nums[i]) ;
            minarr[i] = mini ;
        }
        int idx = 0 ;
        vector<int> res(n) ;
        for(int i = 0 ;i < n ;i++ ){
            maxi = max(maxi, nums[i]) ;

            if(i < n - 1 && maxi <= minarr[i + 1]){
                for(int j = i ; j >= idx ; j--){
                    res[j] = maxi ;
                }
                idx = i + 1 ;
            }
        }

        for(int j = n - 1 ; j >= idx ; j--){
                    res[j] = maxi ;
                }

        return res;
        
    }
};