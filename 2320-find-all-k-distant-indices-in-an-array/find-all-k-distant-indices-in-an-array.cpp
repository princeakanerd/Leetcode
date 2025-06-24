class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size() ;
        vector<int> diff(n + 1 , 0) ;

        for(int i = 0 ; i < n ; i++ ) {
            if(nums[i] == key) {
                diff[max(0 , i - k)] ++ ;
                diff[min(n , i + k + 1)] -- ;
            }
        }
        vector<int> ans ;
        int sum = 0 ;
        for(int i = 0 ; i < diff.size() ; i++ ) {
            sum += diff[i] ;

            if(sum > 0) ans.push_back(i) ;
        }
        return ans;
    }
};