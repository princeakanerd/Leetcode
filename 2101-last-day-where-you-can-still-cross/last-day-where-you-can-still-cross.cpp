class Solution {
    using ll = long long ;
public:
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}} ;
    bool isvalid(ll i , ll j , ll n , ll m){
        return i >= 0 && j >= 0 && i < n & j < m  ;
    }
    bool check(ll mid, vector<vector<int>> &cells, vector<vector<ll>> grid){
        ll n = grid.size(), m = grid[0].size() ;
        for(int i = 0 ; i < mid ; i++ ){
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1 ;
        }

        
        queue<pair<ll, ll>> q;
        vector<vector<ll>> visited(n , vector<ll> (m, 0)) ;

        for(int j = 0 ; j < grid[0].size() ; j++ ){
            if(!grid[0][j]) q.push(make_pair(0, j)) ;
        }
        

        while(!q.empty()){
            auto [i, j] = q.front() ;
            if(i == n - 1) return true ;
            q.pop() ;
            
            for(auto it : dir){
                ll newi = i + it[0], newj = j + it[1] ;
                if(isvalid(newi, newj, n ,m ) && !visited[newi][newj] && !grid[newi][newj]){
                    q.push(make_pair(newi, newj)) ;
                    visited[newi][newj] = true ;
                }
            }

            
        }

        return false ;


    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ll n = cells.size() ;
        ll low = 1, high = n , ans = 0 ;
        vector<vector<ll>> grid(row, vector<ll> (col, 0)) ;
        while(low <= high ){
            ll mid = low + (high - low) / 2;

            if(check(mid, cells, grid)){
                ans = mid ;
                low = mid + 1 ;
            } else high = mid - 1;
        }

        return ans;
    }
};