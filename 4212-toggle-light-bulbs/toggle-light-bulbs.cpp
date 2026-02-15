class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,int> mpp ;

        for(auto it : bulbs){
            mpp[it] ++ ;
        }
        vector<int> res;
        for(auto it : mpp){
            if(it.second % 2) res.push_back(it.first) ;
        }

        return res;
    }
};