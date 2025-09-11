class Solution {
public:
    string sortVowels(string s) {
        int n = s.length() ;
        vector<char> res;
        set<char> st = {'a', 'e', 'i', 'o', 'u'} ;
        for(auto it : s){
            char ch = tolower(it) ;
            if(st.find(ch) != st.end()) res.push_back(it) ;
        }

        sort(res.begin(), res.end(), [&](char a, char b){
            return (int)a < (int)b ;
        });          

        int j = 0 ;
        for(int i = 0 ; i < n ; i++ ){
            if(st.find(tolower(s[i])) != st.end()){
                s[i] = res[j++] ;
            }
        }

        return s ;


    }
};