class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length() ;

        unordered_map<int,int> pfx, mpp0, mpp1 ;
        pfx[0] = -1 ;
        int sum = 0 ;
        int total1 = 0 , total0 = 0, curr0 = 0,curr1 = 0 ;
        for(int i = 0 ; i < n ;i++){
            if(s[i] == '0') total0++ ;
            else total1++ ;
        }

        int ans = 0 ;

        for(int i = 0; i < n ; i++ ){
            if(s[i] == '1') {   
                sum ++ ;
                curr1++ ;
            } else {
                sum-- ;
                curr0++ ;
            }

            if(pfx.find(sum) != pfx.end()) ans = max(ans, i - pfx[sum]) ;

            int s1 = sum + 2; // replace 0 with 1 ;
            if(pfx.find(s1) != pfx.end()){
                if(total1 > curr1) {
                    // found on rightside
                    ans = max(ans, i - pfx[s1]) ;
                } else if(mpp1.find(s1) != mpp1.end()){
                    ans = max(ans, i - mpp1[s1]) ;
                }
            }

            int s2 = sum - 2 ; // replace 1 with 0 

            if(pfx.find(s2) != pfx.end()){
                if(total0 > curr0) ans = max(ans, i - pfx[s2]) ;
                else if(mpp0.find(s2) != mpp0.end()){
                    ans = max(ans, i - mpp0[s2]) ;
                }
            }

            if(pfx.find(sum) == pfx.end()) pfx[sum] = i ;

            if(curr1 > 0 && mpp1.find(sum) == mpp1.end()) mpp1[sum] = i ;
            if(curr0 > 0 && mpp0.find(sum) == mpp0.end()) mpp0[sum] = i ;
            // cout << ans << endl;
        }

        return ans ;
    }
};