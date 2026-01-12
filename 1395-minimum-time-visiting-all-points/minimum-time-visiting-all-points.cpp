class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size() ;
        int res = 0 ;
        for(int i = 1 ; i < n ; i++ ){
            int x = points[i][0] - points[i - 1][0] , y = points[i][1] - points[i - 1][1] ;
            if(abs(x) < abs(y)){
                res += abs(x) ;
                res += abs(points[i - 1][1] - points[i][1]) - abs(x)  ;
            } else{
                res += abs(y) ;
                res += abs(points[i - 1][0] - points[i][0]) - abs(y) ;
            }
            
        }
        return res;
    }
};