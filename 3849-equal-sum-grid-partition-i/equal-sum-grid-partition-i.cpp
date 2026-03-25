class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size()  , m = grid[0].size() ;
        long long sum = 0 ;
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m ;j++ ){
                sum += grid[i][j] ;
            }
        }
        long long curr = 0 ;
        for(int i = 0 ; i < n ;i++ ){
            for(int j = 0 ; j < m ;j++ ){
                curr += grid[i][j] ;
            }

            if(curr == sum - curr) return true ;
        }
        curr = 0 ;
        for(int j = 0 ; j < m ; j++ ){
            for(int i = 0; i < n ; i++ ){
                curr += grid[i][j] ;
            }

            if(curr == sum - curr) return true ;
        }
        return false ;
    }
};