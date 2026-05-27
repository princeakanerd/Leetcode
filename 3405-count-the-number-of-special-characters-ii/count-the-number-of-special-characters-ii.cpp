class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size() ;

        map<char,int> mpp ;
        int res = 0 ;
        vector<bool> pos(26, true) ;
        for(int i = 0 ;i < n ;i++ ){
            if(word[i] >= 'a' && word[i] <='z'){
                if(mpp[toupper(word[i])] > 0) pos[word[i] - 'a'] = false ;
            } 
            mpp[word[i]] ++ ;
        }
        cout << mpp['e'] << " " << mpp['E'] ;
        for(int i = 0 ;i < 26 ;i++ ){
            if(pos[i] && mpp['a' + i] > 0&& mpp['A' + i] > 0) res ++ ;
        }

        return res;
    }
};