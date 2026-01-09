class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        map<string, bool> mpp;
        for(int i = 0 ;i < forbidden.size(); i++ ){
            reverse(forbidden[i].begin(), forbidden[i].end()) ;
            mpp[forbidden[i]] = true ;
        }

        int j = 0 ;
        int n = word.size() ;
        int ans = 0 ;
        for(int i = 0 ; i < n ;i++ ){
            string temp ;
            // bool flag = false ;
            for(int k = i; k >= max(i - 10, j) ; k-- ){
                temp.push_back(word[k]) ;
                // cout << temp << endl;
                if(mpp[temp]) {
                    // flag = true ;
                    j = i - temp.size() + 2;
                    break ;
                }
            }
            if(ans< i - j + 1){
               
                ans = i - j + 1;
            }
            ans = max(i - j + 1, ans) ;
        }
        return ans;
    }
};