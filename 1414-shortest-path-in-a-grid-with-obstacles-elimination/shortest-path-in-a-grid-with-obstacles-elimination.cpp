class Solution {
public:
    bool isvalid(int i , int j , int m , int n) {
        return i >= 0 && j >= 0 && i < m && j < n ;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size() ; 

        vector<vector<vector<int>>> distance(m ,vector<vector<int>>(n , vector<int>(k + 1, INT_MAX)) ) ;

        priority_queue<tuple<int , int , int , int> , vector<tuple<int , int , int , int>> , greater<tuple<int , int , int , int>>> pq ;

        pq.push({0 , 0 , 0 , k}) ;
        distance[0][0][k] = 0 ;
        vector<pair< int , int>> dir = {{-1 , 0} , {0 , -1}, {1 , 0} , {0 ,1}};
        int ans = INT_MAX ;
        while(!pq.empty()) {
            auto [dist , i , j , rem] = pq.top() ;
            pq.pop() ;
            if(i == m - 1 && j == n - 1){
                ans = min(dist , ans) ;
            }
            for(auto it : dir) {
                int newi = i + it.first , newj = j + it.second ;
                if(isvalid(newi , newj, m , n)) {
                    if(grid[newi][newj] == 0 && distance[newi][newj][rem] > dist + 1){
                        distance[newi][newj][rem] = dist + 1 ;
                        pq.push({dist + 1 , newi , newj , rem}) ;
                    } else if(grid[newi][newj] == 1 && rem && distance[newi][newj][rem - 1] > dist + 1) {
                        distance[newi][newj][rem - 1] = dist + 1 ;
                        pq.push({dist + 1 , newi , newj , rem - 1}) ;
                    }
                }
            }
        }
        if(ans == INT_MAX) return -1 ;
        return ans ;
    }
};