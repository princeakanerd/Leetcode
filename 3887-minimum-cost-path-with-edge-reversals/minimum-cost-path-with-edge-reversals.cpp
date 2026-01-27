class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n), revadj(n) ;

        for(auto &it : edges){
            adj[it[0]].push_back({it[2], it[1]}) ;
            revadj[it[1]].push_back({it[2], it[0]}) ;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq ;
        vector<int> distance(n, INT_MAX) ;
        distance[0] = 0 ;
        pq.push({0, 0}) ;

        while(!pq.empty()) {
            auto [dist, node] = pq.top() ;
            pq.pop() ;

            for(auto &it : adj[node]){
                if(distance[it.second] > dist + it.first){
                    distance[it.second] = dist + it.first;
                    pq.push({distance[it.second], it.second}) ;
                }
            }

            for(auto &it : revadj[node]){
                if(distance[it.second] > dist + it.first * 2){
                    distance[it.second] = dist + it.first * 2;
                    pq.push({distance[it.second], it.second}) ;
                }
            }
        }

        return (distance[n - 1] == INT_MAX ? -1 : distance[n - 1]) ;


    }
};