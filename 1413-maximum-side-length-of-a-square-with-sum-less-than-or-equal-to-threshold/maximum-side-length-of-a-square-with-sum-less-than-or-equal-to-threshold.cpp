class Solution {
public:

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size() ;
        vector<vector<int>> pfx(n, vector<int>(m, 0));
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m ;j++ ){
                pfx[i][j] = mat[i][j] ;
                if(i > 0) pfx[i][j] += pfx[i - 1][j] ;
                if(j > 0) pfx[i][j] += pfx[i][j - 1] ;
                if(i > 0 && j > 0 ) pfx[i][j] -= pfx[i - 1][j - 1] ;
            }
        }

        // for(int i = 0 ; i < n ;i++ ){
        //     for(int j = 0 ; j < m ; j++ ){
        //         cout << pfx[i][j] << " " ;
        //     }
        //     cout << endl;
        // }
        
        for(int k = min(m, n) ; k >= 1 ; k-- ){
            for(int i = 0 ; i <= n - k ; i++ ){
                for(int j = 0 ; j <= m - k ; j++ ){
                    int sum = pfx[i + k - 1][j + k - 1] ;   
                    if(i > 0) sum -= pfx[i - 1][j + k - 1] ;
                    if(j > 0) sum -= pfx[i + k - 1][j - 1] ;
                    if(i > 0 && j > 0) sum += pfx[i - 1][j - 1] ;
                    if(sum <= threshold) return k ; 
                }
            }
        }
        return 0;
    }
};