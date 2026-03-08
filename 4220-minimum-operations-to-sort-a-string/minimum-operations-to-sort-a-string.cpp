class Solution {
public:
    int minOperations(string s) {
        int n = s.length() ;
        if(n == 2 && s[0] > s[1]) return -1 ;
        int mini = 25, maxi = 0 ;

        for(int i = 0 ;i < n ;i++ ){
            mini = min(mini, s[i] - 'a') ;
            maxi = max(maxi, s[i] - 'a') ;
        }

        if(is_sorted(s.begin(), s.end())) return 0 ;
        int l = s[0] - 'a', r = s.back() - 'a' ;
        if(l == mini || r == maxi) return 1;
        for(int i = 1 ;i < n - 1 ;i++ ){
            if((s[i] - 'a') == mini || (s[i] - 'a') == maxi) return 2;
        }
        return 3;


    }
};