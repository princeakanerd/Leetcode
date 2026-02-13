class Solution {
    using ll = long long ;
public:
    int longestBalanced(string s) {
        int n = s.length() ;
        int res = 1 ;

       
            int cnt = 1 ;
            for(int i = 1 ; i < n ; i++ ){
                if(s[i] == s[i - 1]){
                    cnt ++ ;
                    res = max(res, cnt) ;
                } else cnt = 1;
            }

            string temp = "abca" ;
            for(int c = 1 ; c < temp.length() ; c++ ){
                char a = temp[c], b = temp[c - 1] ;
                map<int,int> mpp ;
                mpp[0] = -1 ;
                int cnt = 0 ;

                for(int i = 0 ; i < n ;i++ ){
                    if(s[i] != a && s[i] != b) {
                        cnt = 0 ;
                        mpp.clear() ;
                        mpp[0] = i ;
                        continue ;
                    }
                   
                    if(s[i] == a) cnt ++ ;
                    else cnt -- ;

                    // cout << cnt << endl;
                    
                    if(mpp.count(cnt)){
                        res = max(res, i - mpp[cnt]) ;
                    } else mpp[cnt] = i ;
                    
                }
                // cout << endl;

            }


            map<pair<int,int>, int> mpp ;
            int cnta = 0 , cntb = 0 , cntc = 0 ;
            mpp[make_pair(0, 0)] = -1;
            for(int i = 0 ;i < n; i++ ){
                if(s[i] == 'a') cnta++ ;
                else if(s[i] == 'b') cntb ++ ;
                else cntc++ ;


                if(mpp.count(make_pair(cnta - cntb, cnta - cntc)) > 0){
                    res = max(res, i - mpp[make_pair(cnta - cntb, cnta - cntc)]) ;
                } else mpp[make_pair(cnta - cntb, cnta - cntc)] = i ;
            }


    return res ;
        
    }
};