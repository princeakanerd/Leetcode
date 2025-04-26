class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        
        map<string , int> mpp ;
        int maxi = -1 ;
        for(auto resp : responses) {
            set<string> st ;
            for(auto it : resp) {
                st.insert(it) ;
            }

            for(auto it : st) {
                mpp[it] ++ ;
                maxi = max(mpp[it] , maxi) ;
            }
        }

        for(auto it : mpp) {
            if(it.second == maxi) return it.first ;
        }
        return "" ;
    }
};