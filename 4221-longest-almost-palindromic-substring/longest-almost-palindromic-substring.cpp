class Solution {
public:
    void f(int idx, int jdx, string &s, int& res){

        int n = s.length();
        while(idx >= 0 && jdx <= n -1 && s[idx] == s[jdx]){
            res = max(res, jdx - idx + 1) ;
            idx --; jdx ++ ;
        }

        if(idx >= 0 || jdx < n) res = max(res, jdx - idx) ;
        int ogidx = idx , ogjdx = jdx ;
        idx -- ;
        
        
        while(idx >= 0 && jdx <= n -1 && s[idx] == s[jdx]){
            res = max(jdx - idx + 1, res) ;
            idx --; jdx ++ ;
        }
        idx = ogidx , jdx = ogjdx ;
        if(idx >= 0 || jdx < n) res = max(res, jdx - idx) ;

        
        jdx ++ ;
        

        while(idx >= 0 && jdx <= n -1 && s[idx] == s[jdx]){
            res = max(jdx - idx + 1, res) ;
            idx --; jdx ++ ;
        }

    }

    int almostPalindromic(string s) {
        int n = s.length() ;
        int res = -1 ;
        //odd
        for(int i = 0; i < n ;i++ ){
            f(i,i, s, res) ;
            if(i > 0 && s[i] == s[i - 1]) f(i - 1, i, s, res) ;
        }

        return res;
        
    }
};