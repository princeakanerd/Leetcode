class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size() ;
        vector<vector<int>> ans(m - k + 1) ;
        for(int i = 0 ; i < m - k + 1  ; i++ ) {
            for(int j = 0 ;j < n - k + 1 ; j++ ) {
                set<int> st ;
                for(int curri = i ; curri < i + k ; curri ++ ){
                    for(int currj = j ; currj < j + k ; currj ++ ) {
                        st.insert(grid[curri][currj]) ;
                    }
                }
                vector<int> temp (st.begin() , st.end()) ;

                sort(temp.begin() , temp.end()) ;
                int res = INT_MAX ;
                for(auto it : temp) cout << it << " " ;

                for(int i = 1 ; i < temp.size() ; i++ ) {
                    res = min(abs(temp[i] - temp[i - 1]) , res) ;
                }
                if(res == INT_MAX) ans[i].push_back(0) ;
                else ans[i].push_back(res) ;
            }
        }
        return ans;
    }
};