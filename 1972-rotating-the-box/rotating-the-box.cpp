class Solution {
public:
    void rotate(vector<vector<char>> &grid){
        

        int n = grid.size(), m = grid[0].size() ;
        vector<vector<char>> mat(m, vector<char> (n)) ;
        for(int i = 0 ; i < n ;i++ ){
            for(int j = 0 ; j < m ;j++ ){
                mat[j][n - 1 - i] = grid[i][j] ;
            }
        }

        grid = mat ;
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size() ;

        for(int i = 0 ;i < n ;i++ ){
            int cnt = 0 ;
            for(int j = 0; j < m ;j++ ){
                if(grid[i][j] == '#') {
                    cnt ++ ;
                    grid[i][j] = '.' ;
                }
                else if(grid[i][j] == '*'){
                   
                    for(int idx = j - 1; idx >= j - cnt   ; idx-- ){
                        grid[i][idx] = '#';
                    }
                     cnt = 0 ;
                }
            }

            for(int idx = m - 1; idx >= m - cnt ; idx-- ){
                        grid[i][idx] = '#';
            }
        }

            for(int i = 0 ;i < n ;i++ ){
                for(int j = 0 ;j < m ; j++ ){
                    cout << grid[i][j] << " " ;
                    
                }
                cout << endl; 
            }

            rotate(grid) ;
            return grid ;
    }
};