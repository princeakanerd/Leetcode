class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int curr = -1 ;
        vector<string> ans ;
        for(int i = 0 ; i < words.size() ; i++ ) {
            if(groups[i] != curr) {
                ans.push_back(words[i]) ;
                curr = groups[i] ;
            }
        }

        return ans ;
    }
};