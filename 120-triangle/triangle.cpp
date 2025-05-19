class Solution {
public:
    int f(int i , int j , vector<vector<int>>& triangle,vector<vector<int>>& dp ) {
        if(i == triangle.size()) return 0 ;
        if(dp[i][j] != -1) return dp[i][j] ;

        return dp[i][j] =  triangle[i][j] +  min(f(i + 1, j , triangle , dp) , f(i + 1 , j + 1 , triangle , dp)) ;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp (200 , vector<int> (200 , -1));
        return f(0 , 0 , triangle , dp);
    }
};