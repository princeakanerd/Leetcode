class Solution {
public:
    char kthCharacter(int k) {
        string a = "a" ;

        while(a.length() < k) {
            int n = a.length() ;
            for(int i = 0 ; i < n ;i++ ){
                a.push_back((a[i] - 'a' + 1) % 26 + 'a') ;
            }
        }
        return a[k - 1] ;
    }
};