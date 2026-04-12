class Solution {
public:
    int dist(int a, int b) {
        if (a == 26) return 0;
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }
    int minimumDistance(string word) {
        // dp[i][f][s] represents minimum distance to type first i letters using 2 fingers such that at the end the first finger is at f and second is at s
        int n = word.size() ;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(26, vector<int>(26, INT_MAX))) ;

        for(int i = 0 ; i < 26 ; i++ ){
            for(int j = 0 ; j < 26 ; j++ ){
                dp[0][i][j] = 0 ;
            }
        }
        for(int i = 1 ; i <= n ; i++ ){
            int curr = word[i - 1] - 'A' ;
            for(int x = 0 ; x < 26 ; x++ ){
                if(curr == x) continue ;
                for(int j = 0 ; j < 26 ; j++ ){
                    //first finger is on the current letter and second is wherever it was
                    if(dp[i - 1][j][x] != INT_MAX)
                        dp[i][curr][x] = min( dp[i][curr][x], dp[i - 1][j][x] + dist(curr, j)) ;
                    //first finger is wherever it was and second one is on current letter
                    if(dp[i - 1][x][j] != INT_MAX)
                        dp[i][x][curr] = min(dp[i][x][curr], dp[i - 1][x][j] + dist(curr, j)) ;
                }
            }
        }

        int res = INT_MAX ;
        int last = word.back() - 'A' ;
        for(int i = 0 ; i < 26 ; i++ ){
                res = min({res, dp[n][last][i], dp[n][i][last]}) ;
        }

        return res;


    }
};