class Solution {
    using ll = long long ;
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll cnt = 0 ;
        ll n = matrix.size(), mini = INT_MAX , sum = 0 ;
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < n ;j++ ){
                mini = min(mini,1LL *  abs(matrix[i][j])) ;
                sum += abs(matrix[i][j]) ;
            if(matrix[i][j] < 0) cnt ++ ;
            }
        }

        if(cnt % 2) sum -= 2 * mini ;
        return sum ;
    }
};