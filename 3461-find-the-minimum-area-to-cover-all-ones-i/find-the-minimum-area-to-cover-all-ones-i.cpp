class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int i1 = -1 , i2 = -1 , j1 = -1 , j2 = -1 ;
        int m = grid.size() , n = grid[0].size() ;

        for(int i = 0 ; i < m ; i++ ){
            bool found = false ;
            for(int j = 0 ; j < n ;j++ ){
                if(grid[i][j]){
                    i1 = i ;
                    found = true ;
                    break ;
                }
            }
            if(found) break ;
        }

        for(int i = m - 1; i >= 0 ; i-- ){
            bool found = false ;
            for(int j = 0 ; j < n ; j++ ){
                if(grid[i][j]){
                    i2 = i ;
                    found = true ;
                    break ;
                }
            }
            if(found) break ;
        }

        for(int j = 0 ; j < n ; j++ ){
            bool found = false ;

            for(int i = 0 ; i < m ; i++ ){
                if(grid[i][j]){
                    j1 = j ;
                    found = true ;
                    break ;
                }
                
            }
            if(found) break ;
        }

        for(int j = n - 1 ; j >= 0 ; j-- ){
            bool found = false ;
            for(int i = 0 ; i < m ; i++ ){
                if(grid[i][j]){
                    j2 = j ;
                    found = true ;
                    break ;
                }
            }
            if(found) break ;
        }

        return (i2 - i1 + 1) * (j2 - j1 + 1) ;
    }
};