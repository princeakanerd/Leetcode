class Solution {
public:
    int minFlips(string s) {
        int n = s.length() ;

       
            int cnt1 = 0, cnt2 = 0 ;

            for(int i = 0 ; i < n ;i++ ){
                if((i % 2 && s[i] != '0') || (i % 2 == 0 && s[i] != '1')) cnt1++ ;
                if((i % 2 && s[i] != '1') || (i % 2 == 0 && s[i] != '0')) cnt2 ++ ;
            }

            int res = min(cnt1, cnt2) ;
        if(n % 2 == 0) return res;

        vector<int> pfx1(n, 0), pfx2(n, 0) ;
        int cost = 0 ;
        //...1010
        for(int i = n - 1 ; i >= 0 ;i-- ){
            if(i % 2 && s[i] == '1') cost++ ;
            else if(i % 2 == 0 && s[i] == '0') cost ++ ;

            pfx1[i] = cost ;
        }
        
        cost = 0 ;
        //,,,0101 
        for(int i = n - 1 ; i >= 0 ;i-- ){
            if(i % 2 && s[i] == '0') cost++ ;
            else if(i % 2 == 0 && s[i] == '1') cost ++ ;

            pfx2[i] = cost ;
        }

        cost = 0 ;
        //test start 1 end 0
        for(int i = 0 ; i < n - 1 ;i++ ){
            if(i % 2 == 0 && s[i] != '0') cost ++ ;
            else if(i % 2 && s[i] != '1') cost ++ ;

            res = min(res, cost + pfx1[i + 1]) ;
        }
        cost = 0 ;
        for(int i = 0 ; i < n - 1 ; i++) {
            if(i % 2 == 0 && s[i] != '1') cost ++ ;
            else if(i % 2 && s[i] != '0') cost ++ ;

            res = min(res, cost + pfx2[i + 1]) ;
        }


        return res;


    }
};