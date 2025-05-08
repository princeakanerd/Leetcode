class Solution {
public:
    bool isvalid(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        priority_queue<pair<pair<int, int>, pair<int, int>>,
                       vector<pair<pair<int, int>, pair<int, int>>>,
                       greater<pair<pair<int, int>, pair<int, int>>>>
            pq;

        pq.push({{0 , 2}, {0, 0}});
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        distance[0][0] = 0;
        while (!pq.empty()) {
            int currdist = pq.top().first.first;
            int currinc = pq.top().first.second ;
            int i = pq.top().second.first, j = pq.top().second.second;
            pq.pop() ;
            for (auto it : dir) {
                int newi = i + it[0], newj = j + it[1];
                if (isvalid(newi, newj, m, n) && distance[newi][newj] >currdist + max(0, moveTime[newi][newj] - currdist) + 1) {
                    distance[newi][newj] = currdist + max(0, moveTime[newi][newj] - currdist) + ((currinc == 2) ? 1 : 2) ;
                    pq.push({{distance[newi][newj] , ((currinc == 2) ? 1 : 2) } , {newi , newj}}) ;
                }
            }
        }

        return distance[m-1][n - 1] ;
    }
};