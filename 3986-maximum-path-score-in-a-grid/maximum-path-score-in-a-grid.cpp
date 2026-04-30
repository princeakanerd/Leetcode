class Solution {
public:
    bool isvalid(int i , int j , int n , int m){
        return i >= 0 && j >= 0 && i < n && j < m ;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        // vector<vector<vector<int>>> scores(n, vector<vector<int>>(m, vector<int>(k + 1, -1))) ;
        // scores[0][0][0] = 0 ;
        // queue<pair<pair<int,int>, pair<int,int>>> q ;
        // q.push({{0,0}, {0, 0}}) ;
        // vector<vector<int>> dir = {{0, 1}, {1, 0}};
        // int res = -1 ;
        // while(q.size()){
        //     auto p = q.front() ;
        //     q.pop() ;
        //     int score = p.first.first ;
        //     int pen = p.first.second ;
        //     int i = p.second.first , j = p.second.second ;
        //     if(i == n - 1 && j == m - 1 && pen <= k) res = max(score, res) ;

        //     for(auto it : dir){
        //         int newi = i + it[0], newj = j + it[1] ;

        //         if(isvalid(newi, newj, n , m)){
        //             if(grid[newi][newj]) {
        //                 if(pen == k || scores[newi][newj][pen + 1] >= score + grid[newi][newj]) continue ;

        //                 scores[newi][newj][pen + 1] = score + grid[newi][newj] ;
        //                 q.push({{score + grid[newi][newj], pen + 1}, {newi, newj}}) ;
        //         } else {
        //                 if(scores[newi][newj][pen] < score + grid[newi][newj]){
        //                     scores[newi][newj][pen] = score + grid[newi][newj] ;
        //                     q.push({{score + grid[newi][newj], pen}, {newi, newj}}) ;
        //                 }
        //         }
        //     }
        // } 
        // }
        //   return res ;



        ////////////////////

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, -1))) ;
        dp[0][0][0] = 0 ;
        int res = -1 ;
        for(int i = 0 ; i < n ;i++ ){
            for(int j = 0 ; j < m ; j++ ){
                for(int x = 0 ; x <= k ; x++ ){
                    if(grid[i][j] && x > 0){
                        if(i > 0 && dp[i - 1][j][x - 1] != -1) dp[i][j][x] = max(dp[i][j][x], dp[i - 1][j][x - 1] + grid[i][j]) ;
                        if(j > 0 && dp[i][j - 1][x - 1] != -1) dp[i][j][x] = max(dp[i][j][x], dp[i][j - 1][x - 1] + grid[i][j]) ;
                    } else if(grid[i][j] == 0){
                        if(i > 0) dp[i][j][x] = max(dp[i - 1][j][x], dp[i][j][x]) ;
                        if(j > 0) dp[i][j][x] = max(dp[i][j - 1][x], dp[i][j][x]) ;
                        
                    }

                    if(i == n - 1 && j == m - 1) res = max(dp[i][j][x], res) ;
                    
                }
            }
        }
        return res ;

        
    }
};