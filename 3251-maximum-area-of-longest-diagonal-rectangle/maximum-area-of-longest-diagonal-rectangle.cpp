class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxdiagonal = 0 , maxarea = 0 ;
        
        for(auto it :dimensions){
            int currdiagonal =it[0] * it[0] + it[1] * it[1] ;
            if(currdiagonal > maxdiagonal){
                maxarea = it[0] * it[1] ;
                maxdiagonal = currdiagonal ;
            } else if(currdiagonal == maxdiagonal) {
                maxarea = max(it[0] * it[1] , (int)maxarea) ;
            }
        }
        return maxarea ;
    }
};