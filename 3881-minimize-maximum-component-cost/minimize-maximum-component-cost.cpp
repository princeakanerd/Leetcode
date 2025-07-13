class Solution {
public:
    void f(int i , vector<vector<pair<int ,int>>> &adj , int mid, vector<bool> &visited){
        
        for(auto it : adj[i]){
            if(!visited[it.first] && it.second <= mid ){
                visited[it.first] = true ;
                f(it.first , adj , mid , visited) ;
            }
        }
        
    }

    bool check(int mid , vector<vector<pair<int ,int>>> &adj , int k){
        int n = adj.size() ;
        vector<bool> visited(n , 0) ;

        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                cnt ++ ;
                visited[i] = true ;
                f(i ,adj , mid, visited) ;
            }
        }
        return cnt <= k ;
    }
    int minCost(int n, vector<vector<int>>& edges, int k) {

        vector<vector<pair<int ,int>>> adj(n) ;

        for(auto it : edges){
            adj[it[0]].push_back({it[1] , it[2]}) ;
            adj[it[1]].push_back({it[0] , it[2]}) ;
        }
        
        int ans = 0 , low = 0 , high = 1e6 ;

        while(low <= high){
            int mid = low + (high - low) / 2 ;

            if(check(mid , adj ,k)){
                ans = mid ;
                high = mid - 1;
            } else low = mid + 1 ;
        }

        return ans ;
    }
};