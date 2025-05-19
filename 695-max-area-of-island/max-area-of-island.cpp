class Solution {
public:

    bool isvalid(int i , int j , int m , int n){
        return i >= 0 && j >= 0 && j < n && i < m ;
    }
    int dfs(int i , int j , vector<vector<int>>& grid ,vector<vector<int>>& visited){
        int m = grid.size() ,  n = grid[0].size() ;
        if(!isvalid(i , j , m , n) || visited[i][j] || grid[i][j] == 0 ) return 0 ;
        visited[i][j] = 1 ;
        
        vector<pair<int ,int>> dir = {{-1 , 0}, {0 , -1} , {1 , 0} , {0 , 1}} ;
        int ans = 0;
        for(auto it : dir) {
            int newi = i + it.first , newj = j + it.second ;
            ans += dfs(newi , newj , grid , visited) ;
        }
        return ans + 1 ;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size() ,n = grid[0].size() ;

        vector<vector<int>> visited(m , vector<int>(n , 0)) ;
        int ans = 0 ;
        for(int i = 0 ; i < m ; i++ ) {
            for(int j = 0 ; j < n ; j++ ) {
                if(grid[i][j] && !visited[i][j]){
                   ans = max(ans ,dfs(i , j , grid , visited) )  ;
                }
            }
        }
        return ans ;
    }
};