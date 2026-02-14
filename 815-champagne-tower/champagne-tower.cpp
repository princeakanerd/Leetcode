class Solution {
public:

    double champagneTower(int poured, int query_row, int query_glass) {
        double rem[101][101] , amount[101][101] ;
        // vector<vector<double>> rem, amount(100, vector<double>(100, 0)) ;

        if(poured > 1){
            amount[0][0] = 1 ;
            rem[0][0] = poured - 1;
        } else {
            amount[0][0] = poured ;
            rem[0][0] = 0 ;
        }

        for(int i = 1 ; i < 100 ; i++ ){
            for(int j = 0 ; j <= i ;j++ ){
                double totalhere = 0 ;
                if(j > 0) totalhere += rem[i - 1][j - 1] ;
                totalhere += rem[i - 1][j] ;
                totalhere /= 2.0 ;

                if(totalhere > 1){
                    amount[i][j] = 1 ;
                    rem[i][j] = totalhere - 1;
                } else {
                    amount[i][j] = totalhere ;
                    rem[i][j] = 0 ;
                }
            }
        }

        return amount[query_row][query_glass] ;
    }
};