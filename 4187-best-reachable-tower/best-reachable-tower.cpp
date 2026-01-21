class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector<int> res = {-1, -1} ;
        int cx = center[0], cy = center[1] ;
        int val = -1 ;
        for(auto it : towers){
             vector<int> temp = {it[0], it[1]} ;
            int dist = abs(it[0] - cx) + abs(it[1] - cy) ;
            if(dist <= radius){
                if(it[2] > val){
                    res = temp ;
                    val = it[2] ;
                } else if(it[2] == val){
                    if(res > temp) res = temp ;
                }
            }
        }

        return res;
    }
};