class Solution {
public:
    bool check(int idx , string &s , int k) {
        int n = s.length() ;
        long long mul = 1 ;
        long long num = 0 ;
        for(int i = n - 1 ;i >= idx ; i--) {
                if(s[i] == '1'){
                    num += mul ;
                }
                if(num > k || mul > k) return false ;
                mul *= 2;
        }
        return true ;
    }
    int longestSubsequence(string s, int k) {
        int cnt = s.length() ;
        int n = s.length() ;
        for(int i = 0 ;i < n ; i++ ){
            if(s[i] == '1') {
                if(!check(i ,s ,k)) cnt -- ;
                else return cnt;
            }
        }    
        return cnt ;
    }
};