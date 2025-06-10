class Solution {
public:
    int maxDifference(string s) {
        vector<int> mpp(26 , 0) ;

        for(auto it :s){
            mpp[it - 'a'] ++ ;
        }
        int mini = INT_MAX , maxi = INT_MIN ;
        for(auto it : mpp) {
            if(it % 2){
                maxi = max(it ,maxi) ;
            }else if(it && it % 2 == 0) mini = min(it , mini) ;
        }


        return maxi - mini ;

    }
};