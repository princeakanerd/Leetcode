class Solution {
public:
    string f(string s){
        vector<string> sp ;
        int cnt = 0 ;
        int start = 0 ;
        int n = s.length() ;
        for(int i = 0 ;i < n ;i++ ){
            cnt += (s[i] == '1'? 1 : -1 ) ;
            if(cnt == 0){
                sp.push_back("1" + f(s.substr(start + 1, i - start - 1 )) + "0") ;
                start = i + 1;
            }
        }

        sort(sp.rbegin(), sp.rend()) ;

        string res;
        for(auto &it :sp){
            res += it;
        }

        return res ;
    }
    string makeLargestSpecial(string s) {
        int n = s.length() ;
        return f(s) ;
        
    }
};