class Solution {
public:
    using ll = long long ;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m= grid[0].size() ;
        long long sum = 0 ;
    
        for(int i = 0 ; i < n;i++ ){
            for(int j = 0 ; j < m ; j++ ){
                sum += grid[i][j] ;
            }
        }

        if(n == 1){
            ll l = 0 ;
            for(int j = 0 ;j < m - 1;j++ ){
                l += grid[0][j] ;
                ll r = sum - l ;
                
                if((l - grid[0][j] == r) || (l - grid[0][0] == r) || (l == r - grid[0][j + 1]) || (l == r - grid[0][m - 1]) || (l == r)) return true ;
            }
            return false ;
        }

        if(m == 1){
            ll u = 0 ;
            for(int i = 0 ; i < n - 1 ; i++ ){
                u += grid[i][0] ;
                ll d = sum - u ;

                if((u - grid[i][0] == d) || (u - grid[0][0] == d) || (u == d - grid[i + 1][0]) || (u == d - grid[n - 1][0]) || (u == d)) return true ;
            }
            return false ;
        }

        unordered_map<ll,ll> mpp ;
        ll curr = 0 ;
        // horizontal cuts but removing element from upper half
        for(int i = 0 ; i < n - 1; i++ ){
            for(int j = 0; j < m;j++ ){
                curr += grid[i][j] ;
                mpp[grid[i][j]] ++ ;
            }
            if(curr == sum - curr) return true ;
            ll u = curr , d = sum - curr ;
            if(i == 0){
                if((u - grid[i][0] == d) || (u - grid[i][m - 1] == d)) return true ;
            } else {
                if(mpp.count(u - d) > 0) return true ;
            }
        }
        mpp.clear() ;
        curr = 0 ;
        // horizontal cuts but removing element from down 
        for(int i = n - 1 ; i > 0 ; i-- ){
            for(int j = 0; j < m;j++ ){
                curr += grid[i][j] ;
                mpp[grid[i][j]] ++ ;
            }
            if(curr == sum - curr) return true ;
            ll d = curr , u = sum - curr ;
            if(i == n - 1){
                if((u == d - grid[i][0]) || (u == d - grid[i][m - 1])) return true ;
            } else {
                if(mpp.count(d - u) > 0) return true ;
            }
        }
        mpp.clear() ;

        // vertical cuts but removing element from left 
        curr = 0 ;
        for(int j = 0 ; j < m - 1 ; j++ ){

            for(int i = 0;i < n ;i++ ){
                curr += grid[i][j] ;
                mpp[grid[i][j]] ++ ;
            }

            ll l = curr , r = sum - curr ;
            // cout << l << " " << r << endl;
            if(l == r) return true ;
            
            if(j == 0){
                if((l - grid[0][0] == r) || (l - grid[n -1][0]) == r) return true ;
            } else{
                if(mpp.count(l - r) > 0) return true ;
            }
        }

        mpp.clear() ;
        curr = 0 ;
        // vertical cut but removing from the right ;
        for(int j = m - 1; j > 0 ;j-- ){
            for(int i = 0 ; i < n ;i++ ){
                 curr += grid[i][j] ;
                 mpp[grid[i][j]] ++ ;
            }
            ll r = curr, l = sum - curr ;

            if(j == m - 1){
                if((l == r - grid[0][m - 1]) || (l == r - grid[n - 1][m - 1]))return true ;
            } else {
                if(mpp.count(r - l) > 0 ) return true ;
            }
        }

        return false ;
    }
};