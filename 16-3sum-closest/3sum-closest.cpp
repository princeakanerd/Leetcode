class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size() ;
        int res = 0 ;
        int dist = INT_MAX ;
        sort(nums.begin(), nums.end()) ;
        for(int i = 0 ; i < n ; i++ ){
            int j = i + 1, k = n - 1; 

            while(j < k){
                int num = nums[i] + nums[j] + nums[k] ;
                if(num == target) return target ;
                else if(num < target){
                    if(target - num < dist){
                        dist = target - num ;
                        res = num ;
                    }
                    j++ ;
                } else {
                    if(num - target < dist){
                        dist = num - target ;
                        res = num ;
                    }
                    k-- ;
                }
            }
        }
        return res ;
    }
};