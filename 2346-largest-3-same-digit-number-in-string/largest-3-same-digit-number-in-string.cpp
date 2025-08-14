class Solution {
public:
    string largestGoodInteger(string s) {
        int ans = -1 ;
        for(int i = 2 ; i < s.size() ; i++ ){
            if(s[i] == s[i - 1] && s[i] == s[i - 2]){
                ans = max(ans , s[i] - '0') ;
            }
        }

        if(ans == -1) return "" ;

        string res ;
        for(int i = 0 ; i < 3 ; i++ ) res.push_back('0' + ans) ;

        return res ;
    }
};