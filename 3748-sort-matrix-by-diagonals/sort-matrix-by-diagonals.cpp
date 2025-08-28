class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        for(int i = n - 1 ; i>= 0 ;  i--) {
            vector<int> arr ;
            int j = 0 ;
            int tempi = i ;
            while(tempi < n && j < m) {
                arr.push_back(grid[tempi][j]) ;
                tempi++ , j++ ;
            }

            sort(arr.rbegin() , arr.rend()) ;

            for(int idx = i ; idx < n ; idx ++) {
                int jdx = 0 ;
                int arridx = 0 ;
                while(idx < n && jdx < m && arridx < arr.size()) {
                    grid[idx][jdx] = arr[arridx] ;
                    idx ++ , jdx ++ , arridx ++ ;
                }
            }
        }

        for(int j = 1 ; j < m ; j++) {
            int i = 0 ;
            vector<int> arr ;
            int tempj = j;
            while(i < n && tempj < m) {
                arr.push_back(grid[i][tempj]) ;
                i ++ , tempj ++ ;
            }
            sort(arr.begin() , arr.end()) ;

            for(int jdx = j ; jdx < m ;jdx ++) {
                int idx = 0 , arridx = 0 ;
                while(idx < n && jdx < m && arridx < arr.size()){
                    grid[idx][jdx] = arr[arridx] ;
                    idx ++ , jdx ++ , arridx ++ ;
                }
            }
        }
        return grid ;
    } 
};