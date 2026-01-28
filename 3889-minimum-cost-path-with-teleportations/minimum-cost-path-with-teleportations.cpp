class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size() ;

        vector<pair<int,int>> points ;
        vector<vector<int>> cost(n, vector<int>(m, INT_MAX)) ;
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m ;j++ ){
                points.push_back({i, j}) ;
            }
        }
        sort(points.begin(), points.end(),
             [&](const auto& p1, const auto& p2) -> bool {
                 return grid[p1.first][p1.second] < grid[p2.first][p2.second];
             });


        

        for(int t = 0 ; t <= k ;t++ ){
            int mincost = INT_MAX ;
            for(int i = 0, j = 0 ; i < points.size() ;i++ ){
                mincost = min(mincost, cost[points[i].first][points[i].second]) ;
                if(i + 1 < points.size() && grid[points[i].first][points[i].second] == grid[points[i + 1].first][points[i + 1].second]) continue ;

                for(int r = j ; r <= i ;r++ ){
                    cost[points[r].first][points[r].second] = mincost ;
                }
                j = i + 1 ;
            }

            for(int i = n - 1 ; i >= 0 ; i-- ){
                for(int j = m - 1 ;j >= 0 ;j-- ){
                    if(i == n - 1 && j == m - 1){
                        cost[i][j] = 0 ;
                        continue ;
                    }

                    if(i != n - 1){
                        cost[i][j] = min(cost[i][j], cost[i + 1][j] + grid[i + 1][j]) ;
                    }

                    if(j!= m - 1 ){
                        cost[i][j] = min(cost[i][j], cost[i][j + 1] + grid[i][j + 1]) ;
                    }
                }
            }
        }

        return cost[0][0] ;
    }
};

