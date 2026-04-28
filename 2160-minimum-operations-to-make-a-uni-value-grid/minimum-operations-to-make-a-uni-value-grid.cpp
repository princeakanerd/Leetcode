class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        long long sum = 0 , n = grid.size() , m = grid[0].size();
        vector<int> a ;
        for(int i = 0 ; i < grid.size() ; i++ ) {
            for(int j = 0 ; j < grid[0].size() ; j++) {
                a.push_back(grid[i][j]) ;
            }
        }

        sort(a.begin() , a.end()) ;
        long long mid = a[(n * m) / 2] ;

        int count = 0 ;
        for(int i = 0 ; i < a.size() ; i++ ) {
            int num = abs(mid - a[i]) ;
            if(num % x != 0) return -1 ;
            count += num / x ;
        }

        return count ;


        
    }
};