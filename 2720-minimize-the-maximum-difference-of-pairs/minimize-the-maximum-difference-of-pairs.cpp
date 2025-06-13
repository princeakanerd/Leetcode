class Solution {
public:
    bool check(int mid , vector<int> & nums , int p) {
        int cnt = 0 ;
        int n = nums.size() ;
        

        for(int i = 0 ;i + 1< n ; i++ ) {
          
            if(nums[i + 1] - nums[i] <= mid){ cnt ++ ; i ++ ;}
                
        
        }

        return cnt >= p ;
    }
    int minimizeMax(vector<int>& nums, int p) {
        
        int low = 0 , high = 1e9, ans = 0 ;
        sort(nums.begin() , nums.end()) ;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(mid , nums ,p)) {
                ans = mid ;
                high = mid - 1 ;
            } else low = mid + 1;
        }

        return ans ;
    }
};