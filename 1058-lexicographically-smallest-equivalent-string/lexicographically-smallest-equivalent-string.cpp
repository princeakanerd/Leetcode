class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string temp ;
        for(char ch = 'a' ; ch <= 'z' ; ch ++ ) {
            temp.push_back(ch) ;
        }
        int n = s1.size() ;
        for(int i = 0 ; i < n ; i++ ) {
            char mini = min(temp[s1[i] - 'a'] , temp[s2[i] - 'a']) ;
            int store1 = temp[s1[i] - 'a'] , store2 = temp[s2[i] - 'a'] ;
                for(int j = 0 ;j < 26 ; j++ ) {
                    if(temp[j] == store1 || temp[j] == store2) temp[j] = min(mini , temp[j]) ;
                    cout << temp[j] << " " ;
                }
                cout << endl;
        }

        for(int i = 0 ;i < baseStr.length() ; i++ ) {
            baseStr[i] = temp[baseStr[i] - 'a'] ;
        }
        return baseStr ;
    }
};