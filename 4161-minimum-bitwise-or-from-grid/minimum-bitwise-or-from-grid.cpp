class Solution {
public:
    void f(vector<vector<bool>> &mark,vector<vector<int>> &grid,  int b){
        int n = mark.size(), m = mark[0].size() ;

        for(int i = 0 ;i < n ; i++ ){
            for(int j = 0 ; j < m ; j++ ){
                if(b & grid[i][j]) mark[i][j] = true ;
            }
        }
    }
    int minimumOR(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size() ;
        vector<vector<bool>> mark(n, vector<bool>(m, false) ) ;
        int res = 0 ;
        for(int bit = 30 ; bit >= 0 ; bit-- ){
            
            int val = 0 ;
            for(int i = 0 ; i < n ;i++ ){
                int b = (1 << bit) ;
                for(int j = 0 ; j < m ;j++ ){
                    if(!mark[i][j]) b &= grid[i][j] ;
                }
                
                val |= b;
           }

            res <<= 1;
           if(val == 0){
                f(mark,grid, (1 << bit)) ;
           } else {
                res ++ ;
           }
        }

        return res;
       
    }
};