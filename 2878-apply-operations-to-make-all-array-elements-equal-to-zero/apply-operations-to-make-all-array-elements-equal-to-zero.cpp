class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<int> diff(n + k + 1, 0) ;
        int curr = 0 ;
        for(int i = 0 ;i < n ;i++ ){
            curr += diff[i] ;
            int num = nums[i] + curr ;
            if(num < 0 || (i > n - k && num > 0) ) return false ;
            curr -= num ;
            diff[min(i + k ,n)] += num ;    
        }

        return true ;
    }
};