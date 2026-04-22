class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {

        vector<string> res;
        for(auto s : queries){
            
            for(auto it : dictionary){
                if(it.length() != s.length()) continue ;
                int n = s.length() ;
                int cnt = 0 ;
                for(int i = 0 ;i < n ;i++ ){
                    if(s[i] != it[i]) cnt ++ ;
                }    

                if(cnt <= 2) {res.push_back(s) ; break ;}
            }
        }

        return res;
    }
};