class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size() ;
        vector<int> mpp(7) ;
        for(int i = 0 ; i < n ; i++ ) {
            if(tops[i] == bottoms[i]) mpp[tops[i]] ++ ;
            else {
                mpp[tops[i]] ++ , mpp[bottoms[i]] ++ ;
            }
        }
        int num = -1 ;
        for(int i = 1 ; i <= 6 ; i++ ) {
            if(mpp[i] == n) num = i ;
        }
        if(num == -1) return -1 ;
        int cnt = 0 , cnt2 = 0 ;
        for(int i = 0 ; i < n ; i++ ) {
            if(tops[i] != num) cnt ++ ;
            if(bottoms[i] != num) cnt2 ++ ;
        }

       
        return min(cnt2 , cnt) ;
    }
};