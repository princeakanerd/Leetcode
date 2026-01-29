class Solution {
public:
    void f(int s, vector<vector<pair<int,int>>> &adj, vector<vector<int>> &distance){

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq ;
        distance[s][s] = 0 ;
        pq.push({0, s}) ;

        while(!pq.empty()) {
            auto [dist, node] = pq.top() ;
            pq.pop() ;
            if(dist > distance[s][node]) continue ;
            for(auto it : adj[node]){
                if(distance[s][it.first] > distance[s][node] + it.second) {
                    distance[s][it.first] = distance[s][node] + it.second ;
                    pq.push({distance[s][it.first], it.first}) ;
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>> adj(26) ;
        int n = original.size() ;
        for(int i = 0 ; i < n ; i++ ){
            adj[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]}) ;
        }

        vector<vector<int>> distance(26, vector<int>(26, INT_MAX)) ;

        for(int i = 0 ; i < 26 ; i++ ){
            f(i, adj, distance) ;
        }

        long long res = 0 ;
        for(int i = 0 ; i < target.size(); i++ ){
            if(distance[source[i] - 'a'][target[i] - 'a'] == INT_MAX) return -1 ; 
            res += distance[source[i] - 'a'][target[i] - 'a'] ;
        }
        return res;



    }
};