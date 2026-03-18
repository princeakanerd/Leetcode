class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size() ;
        vector<vector<int>> pfx(n, vector<int> (m, 0)) ;
        for(int i = 0; i < n ; i++ ){
            for(int j = 0 ;j < m ;j++ ){
                pfx[i][j] = grid[i][j] ;

                if(i > 0) pfx[i][j] += pfx[i - 1][j] ;
                if(j > 0) pfx[i][j] += pfx[i][j - 1] ;

                if(i > 0 && j > 0) pfx[i][j] -= pfx[i - 1][j - 1] ;
            }
        }
        int cnt = 0 ;


        for(int i = 0; i < n ;i++ ){
            for(int j = 0 ; j < m ; j++){
                if(pfx[i][j] <= k) cnt ++ ;
            }
        }

        return cnt ;
    }
};