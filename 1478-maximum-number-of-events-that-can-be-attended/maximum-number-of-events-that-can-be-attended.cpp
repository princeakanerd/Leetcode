class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin() , events.end()) ;
        int ans = 0 ;
        int lastmarked = -1 ;
        int j = 0 ;

        int maxd = 0 ;
        for(auto it : events) maxd = max(maxd ,it[1]) ;
        int n = events.size() ;
        priority_queue<int , vector<int> ,greater<int>> pq ;

        for(int i = 1 ; i <= maxd ; i++ ) {
            while(j < n && events[j][0] <= i) {
                pq.push(events[j][1]) ;
                j++ ;
            }

            while(pq.size() && pq.top() < i) pq.pop() ;
            if(pq.size()) {
                ans ++ ;
                pq.pop() ;
            }
        }
        return ans ;
    }
};