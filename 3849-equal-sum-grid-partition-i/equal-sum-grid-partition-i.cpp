class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() ;
        vector<long long> rowsum(m) ,colsum(n) ;
        long long totalsum = 0 ;
        for(int i = 0 ;i < m ; i++ ) {
            long long sum = 0 ;
            for(int j = 0 ; j < n ; j++ ) {
                sum += grid[i][j] ;
                totalsum += grid[i][j] ;
            }
            rowsum[i] = sum ;
        }

        

        for(int j = 0 ;j < n ; j++ ) {
            long long sum = 0 ;
            for(int i = 0 ; i < m ; i++ ) {
                sum += grid[i][j] ;
            }
            colsum[j] = sum ;
        }

        long long currsum = 0;
        for(int i = 0 ;i < m ; i++ ) {
            if(currsum == totalsum - currsum) return true ;
            currsum += rowsum[i] ;
        }

        currsum = 0 ;
        for(int i = 0 ; i < n ; i++ ) {
            if(currsum == totalsum - currsum) return true ;
            currsum += colsum[i] ;
        }
        return false ;
    }
};