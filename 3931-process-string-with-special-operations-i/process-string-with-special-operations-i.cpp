class Solution {
public:
    string processStr(string s) {
        string res = "" ;
        for(int i = 0 ; i < s.length() ; i++ ){
            
            if(s[i] == '*' && res.length()){
                res.pop_back() ;
            } else if(s[i] == '#' && res.length()){
                res = res + res ;
            } else if(s[i] == '%' && res.length()){
                reverse(res.begin() , res.end()) ;
            } else if(s[i] >= 'a' && s[i] <= 'z'){
                res.push_back(s[i]) ;
            }
        }

        return res ;
    }
};