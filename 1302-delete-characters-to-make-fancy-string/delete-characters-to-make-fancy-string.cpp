class Solution {
public:
    string makeFancyString(string s) {
        int cnt = 1 ;
        string res;
        res.push_back(s[0]) ;

        for(int i = 1 ; i < s.length(); i++ ){
            if(s[i] == s[i - 1]) cnt ++ ;
            else cnt = 1 ;

            if(cnt < 3){
                res.push_back(s[i]) ;
            }
        }
        return res ;
    }
};