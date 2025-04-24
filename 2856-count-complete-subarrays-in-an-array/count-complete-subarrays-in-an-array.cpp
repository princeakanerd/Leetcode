class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> st ;
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i++ ) {
            st.insert(nums[i]) ;
        }
        int ans = 0 ;
        map<int ,int> mpp ;
        int j = 0 ;
        for(int i = 0 ; i < n ; i++){
            mpp[nums[i]] ++ ;
            while(j <= i && mpp.size() == st.size()) {
                mpp[nums[j]] -- ;
                if(mpp[nums[j]] == 0) mpp.erase(nums[j]) ;
                j ++ ;
            }

            ans += j ;
            
        }

        return ans ;

        
    }
};