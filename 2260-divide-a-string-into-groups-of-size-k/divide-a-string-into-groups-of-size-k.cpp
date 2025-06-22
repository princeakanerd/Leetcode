class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans ;
        int n = s.length() ;
        string temp ;
        for(int i = 0 ; i < n ; i++ ) {
            if(temp.size() && i % k == 0){
                ans.push_back(temp);
                temp.clear() ;
            } 
             temp.push_back(s[i]) ;
        }

        if(temp.size()){
            while(temp.size() < k) temp.push_back(fill) ;
            ans.push_back(temp) ;
        }

        return ans ;
        
    }
};