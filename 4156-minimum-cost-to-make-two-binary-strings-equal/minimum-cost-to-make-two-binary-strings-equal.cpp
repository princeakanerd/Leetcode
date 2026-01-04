class Solution {
    using ll = long long ;
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        int n = s.length() ;
        int interchange = min(2 * flipCost, swapCost) ;

        int t0 = 0 , t1 = 0 ;

        for(int i = 0 ; i < n ;i++ ){
            if(s[i] == '0' && t[i] == '1') t0 ++ ;
            if(s[i] == '1' && t[i] == '0') t1 ++ ;
        }

        ll totalcost = 1LL * min(t0, t1) * interchange ;
        ll rem = abs(t0 - t1) ;
        if(rem % 2){ totalcost += flipCost ; rem-- ;}
        

        ll tempcost = min(flipCost * rem, (crossCost + interchange) * rem /2) ;
        return totalcost + tempcost ;
    }
};