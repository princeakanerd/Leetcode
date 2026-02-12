class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length() ;
        int res = 0 ;
        for(int i = 0 ; i < n ; i++ ){
            multiset<int> st;
            vector<int> mpp(26, 0) ;
            for(int j = i ; j < n ;j++ ){
                mpp[s[j] - 'a'] ++ ;
                if(mpp[s[j] - 'a'] > 1){
                    st.erase(st.find(mpp[s[j] - 'a'] - 1)) ;
                }
                st.insert(mpp[s[j] - 'a']) ;

                if(*st.begin() == *st.rbegin()){
                    res = max(res, j - i + 1) ;
                }
            }

        }

        return res;
    }
};