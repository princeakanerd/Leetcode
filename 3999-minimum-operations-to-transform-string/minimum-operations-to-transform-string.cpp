class Solution {
public:
    int minOperations(string s) {
        vector<int> mpp(26, 0) ;

        for(auto it : s) mpp[it - 'a'] ++ ;
        int cnt = 0 ;
        for(int i = 1; i < 26 ; i++ ){
            if(mpp[i]) return 26 - i ;
        }
        return 0 ;
    }
};