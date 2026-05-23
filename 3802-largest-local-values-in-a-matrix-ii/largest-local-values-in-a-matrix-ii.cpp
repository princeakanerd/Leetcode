class Solution {
public:
    int pfx[202][202][202] ;
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        int ans = 0;
        for(int v = 1 ; v <= 200 ; v ++ ){
            for(int i = 1 ;i <= n ; i++ ){
                for(int j = 1 ; j <= m ; j++ ){
                    pfx[v][i][j] = pfx[v][i - 1][j] + pfx[v][i][j - 1] - pfx[v][i - 1][j - 1] + (matrix[i - 1][j - 1] > v) ;
                }
            }
        }


        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ;j < m ;j++ ){
            
                int v = matrix[i][j] ;
                if(v == 0) continue ;
                int iup = min(i + v, n - 1) , jup = min(j + v, m - 1) , idown = max(i - v, 0), jdown= max(j - v,0) ;
                int cnt = pfx[v][iup + 1][jup + 1] + pfx[v][idown][jdown] - pfx[v][idown][jup + 1] - pfx[v][iup + 1][jdown] ;

                if(i + v < n && j + v < m && matrix[iup][jup] > v)cnt--;
                if(i + v < n && j - v >= 0 && matrix[iup][jdown] > v)cnt-- ;
                if(i - v >= 0 && j + v < m && matrix[idown][jup] > v) cnt-- ;
                if(i - v >= 0 && j - v >= 0 && matrix[idown][jdown] > v) cnt -- ;
                
                if(cnt == 0) {
                    ans ++ ;
                }

            }
        }

        return ans;
    }
};