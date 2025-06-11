class Solution {
public:
    
    int maxFrequency(vector<int>& nums, int k) {
        vector<long long> pfx(1 , 0);
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;
        for(int i = 0 ; i < n ; i++ ) {
            pfx.push_back(nums[i] + pfx.back()) ;
        }

        int ans = 0 , i = 0 ;

        for(int j = 0 ; j < n ; j++ ){
            
            while(1LL * (j - i + 1) * nums[j] - (pfx[j + 1] - pfx[i]) > k)i ++ ;
            ans = max(ans , j - i + 1) ;
        }
        return ans;

    }
};