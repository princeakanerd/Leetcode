class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0} ;
        vector<int> degree(n) ;
        for(auto it : edges) {
            degree[it[0]] ++ ;
            degree[it[1]] ++ ;
        }

        vector<vector<int>>  adj(n) ;
        for(auto it : edges){
            adj[it[0]].push_back(it[1]) ;
            adj[it[1]].push_back(it[0]) ;
        }
        
        vector<int> distance(n , -1);
        queue<pair<int,int>> q ;
        for(int i = 0 ; i < n ; i++){
            if(degree[i] == 1){
                q.push(make_pair(i , 0)) ;
                distance[i] = 0 ;
            }
        }        
        int maxd = 0 ;

        while(q.size()){
            auto [node,dist] = q.front() ;
            q.pop() ;
            for(auto it : adj[node]){
                degree[it]-- ;
                if(distance[it] == -1 && degree[it] == 1){
                    distance[it] = dist + 1 ;
                    maxd = max(maxd, distance[it]) ;
                    q.push(make_pair(it , distance[it])) ;
                }
            }
            
        }
        vector<int> res ;
        for(int i = 0 ;i < n ;i++ ){
            if(distance[i] == maxd) res.push_back(i) ;
        }
        return res ;





        
    }
};