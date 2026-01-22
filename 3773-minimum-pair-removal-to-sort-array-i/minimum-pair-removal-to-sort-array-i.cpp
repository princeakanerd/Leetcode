class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        
        
        bool flag = true ;
        int cnt = 0 ;
        while(!is_sorted(nums.begin(), nums.end())){
            cnt ++ ;
            int n = nums.size() ;
            vector<int> temp ;
            int idx = -1 ;
            int minsum = INT_MAX ;
            for(int i = 1 ;i < n ;i++ ){
                if(nums[i - 1] + nums[i] < minsum){
                    idx = i ;
                    minsum = nums[i - 1] + nums[i] ;
                }
            }

            for(int i = 0 ; i < n ;i++ ){
                if(i == idx - 1) continue ;
                else if(i == idx) temp.push_back(minsum) ;
                else temp.push_back(nums[i]);
            }
            nums = temp ;

        }
        return cnt ;
    }
};