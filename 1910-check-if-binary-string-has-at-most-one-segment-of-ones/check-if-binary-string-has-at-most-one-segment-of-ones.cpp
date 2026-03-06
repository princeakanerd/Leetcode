class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0 ;
        int curr = 0 ;
        for(int i = 0 ;i < s.length() ;i++ ){
            if(s[i] == '0'){
                if(curr) cnt ++ ;
                curr = 0 ;
            } else curr ++ ;
        }   
        if(curr) cnt ++ ;
        return cnt <= 1 ;
    }
};