class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> mpp(100 , 0) ;
        int ans = 0 ;
        for(auto it : dominoes ) {
            ans += mpp[min(it[0] , it[1]) * 10 + max(it[0], it[1])] ;
            mpp[min(it[0] , it[1]) * 10 + max(it[0], it[1])]++ ;
        }
        
       
        return ans ;
    }
};