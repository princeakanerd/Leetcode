class Solution {
public:
    int fetch(int a , int b) {
        return (a % 2 ) * 2 + b % 2 ;
    }
    int maxDifference(string s, int k) {
        int n = s.length() ;
        int ans = INT_MIN ;
        
        
        for(char a = '0' ; a <= '4' ; a++ ) {
            for(char b = '0' ; b <= '4' ; b++ ) {
                if(a == b) continue ;
                int cnta = 0, cntb = 0 , preva = 0 , prevb = 0;
                vector<int> best(4 , INT_MAX) ;
                int i = 0 ;
                for(int j = 0 ; j < n ; j++ ) {
                    cnta += (s[j] == a);
                    cntb += (s[j] == b) ;

                    while(j - i + 1 >= k && cntb - prevb>= 2) {
                        int leftstatus = fetch(preva , prevb) ;
                        best[leftstatus] = min(preva - prevb , best[leftstatus]) ;
                        preva += (s[i] == a) ;
                        prevb += (s[i] == b) ;
                        i++ ;
                    }
                    int rightstatus = fetch(cnta , cntb) ;
                    if(best[rightstatus ^ 2] != INT_MAX) {ans = max(ans ,cnta - cntb - best[rightstatus ^ 2]) ; }
                }

                
                
            }
        }
        return ans ;
    }
};