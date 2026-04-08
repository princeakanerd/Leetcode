class Solution {
public:
    int mirrorFrequency(string s) {
        int n = s.length() ;
        map<char,int> mpp ;

        for(auto it : s) mpp[it] ++ ;
        int res = 0 ;
        for(char c = 'a' ; c <= 'z'; c++ ){
            res += abs(mpp[c] - mpp[static_cast<char>('a' + 'z' - c)]) ;
        }

        for(char c = '0' ; c <= '9'; c++ ){
            res += abs(mpp[c] - mpp[static_cast<char>('0' + '9' - c)]) ;
        }

        return res / 2 ;
    }
};