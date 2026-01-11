class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() ;
        int res = 0 ;
        for(int i = 0 ;i < n ;i++ ){
            for(int j = 0 ; j < m ; j++){
                
                int col = m ;
                for(int newi = i ; newi < n ; newi ++){
                    if(matrix[newi][j] == '0') break ;
                    for(int newj = j ; newj < col ; newj ++ ){
                        if(matrix[newi][newj] == '0') {
                            col = newj ;
                            break ;
                        } else {
                            res = max(res, (newi - i + 1) * (newj - j + 1)) ;
                        }
                        
                    }
                }
            }
        }
        return res ;
    }
};