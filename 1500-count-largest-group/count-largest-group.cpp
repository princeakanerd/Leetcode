class Solution {
public:
    int digsum (int n ) {
        int res = 0 ;
        while(n) {
            res += n % 10 ;
            n /= 10 ;
        }
        return res ;
    }
    int maxsize = 0 ;
    int countLargestGroup(int n) {
        map<int , int> mpp ;

        for(int i = 1 ; i <= n ; i++ ) {
            mpp[digsum(i)] ++ ;
            maxsize = max(mpp[digsum(i)] , maxsize) ;
        }
        int ans = 0;
        for(auto it : mpp) {
            if(it.second == maxsize) ans ++ ;
        }
        return ans ;
    }

    
};