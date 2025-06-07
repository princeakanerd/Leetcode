class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> mpp(26) ;
        int n = s.length() ;
        vector<int> notpick(n , 0) ;
        for(int i = 0 ;i < s.length() ; i++ ) {
            if(s[i] != '*')mpp[s[i] - 'a'].push_back(i) ;
            else {
                notpick[i] = 1 ;
                for(int j = 0 ; j < 26 ; j++ ) {
                    if(mpp[j].size() > 0){
                        notpick[mpp[j].back()] = 1 ;
                        mpp[j].pop_back() ;
                        break ;
                    }
                }
            }
            
        }

        string res ;


        for(int i = 0 ; i < n ; i++ ) {
            if(!notpick[i]) res.push_back(s[i]) ;
        }
        return res ;


    }
};