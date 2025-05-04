class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> mpp(100 , 0) ;
        for(auto it : dominoes ) {
            mpp[min(it[0] , it[1]) * 10 + max(it[0], it[1])]++ ;
        }
        int ans = 0 ;
        for(auto it : mpp){
            if(it) ans += it * (it - 1) / 2 ;
           
        }
        return ans ;
    }
};