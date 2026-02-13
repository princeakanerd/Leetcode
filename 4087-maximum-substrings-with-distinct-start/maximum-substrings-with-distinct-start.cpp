class Solution {
public:
    int maxDistinct(string s) {
        set<char> st;

        for(int i = 0; i < s.length(); i++ ){
            st.insert(s[i]) ;
        }
        return (int)st.size() ;
    }
};