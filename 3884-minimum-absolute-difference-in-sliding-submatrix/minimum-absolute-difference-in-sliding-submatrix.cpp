class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size() ;
        vector<vector<int>> res(n - k + 1, vector<int>(m - k + 1, -1)) ;
        for(int i = 0 ; i <= n - k ; i++ ){
            for(int j = 0 ; j <= m - k ; j++ ){
                vector<int> temp ;
                for(int ii = i ; ii < i + k ; ii ++ ){
                    for(int jj = j ; jj < j + k ; jj ++ ){
                        temp.push_back(grid[ii][jj]) ;
                    }
                }

                sort(temp.begin(), temp.end()) ;
                int mini = INT_MAX ;
                for(int t = 1; t < temp.size(); t++ ){
                    if(temp[t] != temp[t - 1])
                         mini = min(mini, temp[t] - temp[t - 1]) ;
                }

                res[i][j] = (mini == INT_MAX ? 0 : mini) ;

            }
        }

        return res;
    }
};