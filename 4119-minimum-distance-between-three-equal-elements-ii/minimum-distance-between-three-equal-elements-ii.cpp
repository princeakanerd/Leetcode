class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>> mpp ;
        int n = nums.size() ;

        for(int i = 0 ; i < n ; i++  ){
            mpp[nums[i]].push_back(i) ;
        }
        int ans = INT_MAX ;
        for(auto it : mpp){
            vector<int> temp = it.second ;
            for(int i = 0 ; i < temp.size() ;i++ ){
                if(i >= 2) ans = min(ans, abs(temp[i] - temp[i -1]) + abs(temp[i - 1] - temp[i - 2]) + abs(temp[i - 2] - temp[i]));
            }
        }
        if(ans == INT_MAX) return -1 ;
        return ans  ;
    }
};