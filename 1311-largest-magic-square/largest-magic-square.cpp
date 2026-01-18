class Solution {
public:
    bool check(int i , int j, int k,vector<vector<int>>& grid,vector<vector<int>> &rowpfx, vector<vector<int>> &colpfx){
        int sum = -1 ;
        for(int col = j ; col <  j + k  ; col++ ){
            int currsum = colpfx[i + k - 1][col] ;
            if(i - 1 >= 0) currsum -= colpfx[i - 1][col] ;
            if(sum == -1) sum = currsum ;
            else {
                if(sum != currsum) return false ;
            }
        }
        // cout << sum << " " << currsum << endl;
        for(int row = i ; row < i + k ; row ++ ){
            int currsum = rowpfx[row][j + k - 1] ;
            if(j - 1 >= 0) currsum -= rowpfx[row][j -1] ;
            if(sum != currsum) return false ;
        }
        int currsum = 0 ;
        for(int row = i, col = j ; row < i + k && col < j + k ; row ++, col ++ ){
            currsum += grid[row][col] ; 
        }
        if(currsum != sum) return false ;
        currsum = 0 ;
        for(int row = i , col = j + k - 1 ; row < i + k && col >= j ; col --, row ++ ){
            currsum += grid[row][col] ;
        }

        if(currsum != sum) return false ;
        
        return true ;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size() ;

        vector<vector<int>> rowpfx(n , vector<int>(m, 0)), colpfx(n, vector<int>(m , 0)) ;
        for(int i = 0 ; i < n ;i++ ){
            for(int j = 0 ; j < m ;j++ ){
                if(j == 0) rowpfx[i][j] = grid[i][j] ;
                else rowpfx[i][j] = rowpfx[i][j - 1] + grid[i][j] ;
            }
        }

        for(int j = 0 ; j < m ; j++ ){
            for(int i = 0 ; i < n ;i++ ){
                if(i == 0) colpfx[i][j] = grid[i][j] ;
                else colpfx[i][j] = colpfx[i - 1][j] + grid[i][j] ;
            }
        }

        int res = 1 ;
        for(int k = min(m, n) ; k >= 2; k-- ){
            bool flag = false ;
            for(int i = 0 ; i <= n - k; i++){
                for(int j = 0 ; j <= m - k ;j++ ){
                    if(check(i, j ,k, grid, rowpfx, colpfx)) return k ;
                }
            }
        }
        return 1;
    }
};