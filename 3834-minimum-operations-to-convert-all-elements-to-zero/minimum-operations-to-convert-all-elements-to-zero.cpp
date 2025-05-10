class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size() ;
        set<int> st ;
        vector<vector<int>> mpp(100001) ;
        for(int i = 0 ; i < n ; i++ ) {
            mpp[nums[i]].push_back(i) ;
        }
        int ans = 0 ;

        for(int i = 0 ; i <= 1e5 ; i++ ) {
            if(mpp[i].size()) {
                st.insert(mpp[i][0]) ;
                if(i > 0) ans ++ ;
                for(int j = 1 ; j < mpp[i].size() ; j++ ) {
                    auto it = next(st.find(mpp[i][j - 1]));
                    if(it != st.end() && *it < mpp[i][j]) {
                        ans ++ ;
                    }
                    st.insert(mpp[i][j]) ;
                }

            }
        }
        return ans ;
    }
};