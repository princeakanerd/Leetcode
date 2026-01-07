class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size() ;
        int res = 0 ;
        for(int i = 0 ;i < n ; i++ ){
            unordered_map<int,int> mpp ;
            int curr = 0 ;
            for(int j = i ; j < n ;j++ ){
                mpp[nums[j]] ++ ;
                if(j == i) continue ;
                if(mpp[nums[j]] > 1) {
                    res += curr ;
                    continue ;
                }

                if((mpp[nums[j] - 1] && mpp[nums[j] + 1] && mpp[nums[j]] == 1 )) curr -- ;
                if(mpp[nums[j] - 1] == 0 && mpp[nums[j] + 1] == 0) curr ++ ;
                res += curr ;
            }
            


        }
        return res;
    }
};