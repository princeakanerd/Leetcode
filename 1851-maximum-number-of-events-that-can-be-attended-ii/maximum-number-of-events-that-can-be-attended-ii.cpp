class Solution {
public:
    long long helper(int i ,vector<vector<int>> &events , long long remk , long long lastday , vector<vector<long long>> &dp , vector<int> &next){
        if(i >= events.size() || remk == 0) return 0 ;
        if(dp[i][remk] != -1) return dp[i][remk];
        long long a = 0 , b = 0 ;


        a = events[i][2] + helper(next[i], events , remk - 1 , events[i][1] ,dp ,next) ;
        b = helper(i + 1 , events , remk, lastday, dp , next) ;

        return dp[i][remk] = max(a , b) ;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin() ,events.end()) ;
        int n = events.size() ;
        vector<vector<long long>> dp(n , vector<long long> (k + 1 , -1)) ;

        vector<int> next(n , -1) ;

        for(int i = 0 ; i < n ; i++ ){
            next[i] = upper_bound(events.begin() + 1, events.end() , vector<int>{events[i][1] + 1, 0 , 0}) - events.begin() ;
        }
        return helper(0 , events , k , -1 , dp , next) ;
    }
};