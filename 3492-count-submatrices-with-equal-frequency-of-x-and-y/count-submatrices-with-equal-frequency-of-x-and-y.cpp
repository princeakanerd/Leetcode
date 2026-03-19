class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size() ;
        vector<vector<int>> x(n, vector<int> (m, 0)), y(n, vector<int>(m, 0)) ;
        for(int i = 0 ; i < n ;i++ ){
            for(int j = 0 ; j < m ;j++ ){
                if(grid[i][j] == 'X') x[i][j] = 1;
                else if(grid[i][j] == 'Y') y[i][j] = 1;

                
                if(i > 0) {
                    x[i][j] += x[i - 1][j] ;
                    y[i][j] += y[i - 1][j] ;
                }


                if(j > 0) {
                    x[i][j] += x[i][j - 1] ;
                    y[i][j] += y[i][j - 1] ;
                }

                if(i > 0 && j > 0) {
                    x[i][j] -= x[i - 1][j - 1] ;
                    y[i][j] -= y[i - 1][j - 1] ;
                }
            }
        }
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m ;j++ ){
                if(x[i][j] > 0 && x[i][j] == y[i][j]){
                    cnt ++ ;
                }
            }
        }
        return cnt;
    }
};