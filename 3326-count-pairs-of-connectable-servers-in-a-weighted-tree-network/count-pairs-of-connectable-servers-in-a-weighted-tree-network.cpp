class Solution {
public:
    long long dfs(int node , int par , long long dist , vector<vector<pair<int , int>>> &adj , int signalSpeed){
        
        int cnt = 0 ;
        for(auto it : adj[node]){
            if(it.first != par){
                cnt += dfs(it.first , node, dist + it.second , adj ,signalSpeed) ;
            }
        }
        return cnt + (dist % signalSpeed == 0) ;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = 0 ;
        for(auto it : edges){
            n = max(it[0] , n) ;
            n = max(it[1] , n) ;
        }
        n++ ;
        vector<int> res(n) ;
        vector<vector<pair<int ,int>>> adj(n) ;
        for(auto it : edges){
            adj[it[0]].push_back(make_pair(it[1] , it[2])) ;
            adj[it[1]].push_back(make_pair(it[0] , it[2])) ;
        }

        for(int i = 0 ; i < n ;i++ ){
            long long count = 0, tempres = 0 ;

            for(auto it : adj[i]){
                long long currcnt = dfs(it.first , i , it.second ,adj , signalSpeed) ;
                tempres += count * currcnt ;
                count += currcnt ;
            }
        res[i] = tempres ;
        }
        return res ;
    }
};