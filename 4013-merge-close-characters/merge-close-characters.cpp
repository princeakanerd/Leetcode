class Solution {
public:
    string mergeCharacters(string s, int k) {
        string res; 

        vector<int> mpp(26, -300) ;

        for(int i = 0 ; i < s.length(); i++ ){
            if((int)res.size() > mpp[s[i] - 'a'] + k) {mpp[s[i] - 'a'] = (int)res.size() ; res.push_back(s[i]) ; }
        }

        return res;
    }
};