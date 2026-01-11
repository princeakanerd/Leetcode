class Solution {
public:
    int residuePrefixes(string s) {
        map<char,int> mpp ;
        int n = s.length() ;
        int res = 0 ;
        for(int i = 0 ; i < n ;i++ ){
            mpp[s[i]] ++ ;
            if(mpp.size() == (i + 1) % 3) res ++ ;
        }
        return res;
    }
};