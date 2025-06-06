class Solution {
public:
    string robotWithString(string s) {
        vector<int> mpp(26, 0) ;

        for(auto it : s) mpp[it - 'a'] ++ ;

        string temp ;
        string ans ;
        int n = s.length() ;
        int j = 0 ;
        while(j < 26 && mpp[j] == 0)j++ ;

        for(int i = 0 ; i < n && j < 26  ; i++ ) {
            char c = j + 'a' ;
            while(!temp.empty() && temp.back() <= c){
                ans.push_back(temp.back());
                temp.pop_back() ;
            }
            
            if(s[i] == c){
                ans.push_back(s[i]) ;
            } else temp.push_back(s[i]) ;
            mpp[s[i] - 'a'] -- ;
            while(j < 26 && mpp[j] == 0)j++ ;
        }
        if(temp.size()){
            reverse(temp.begin() ,temp.end()) ;
        ans = ans + temp ;
        }
        
        return ans ;
    }
};