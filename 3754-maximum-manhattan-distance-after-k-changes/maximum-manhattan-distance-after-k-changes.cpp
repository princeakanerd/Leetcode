class Solution {
public:
    
    int maxDistance(string s, int k) {
        int n = 0, e = 0 ,so = 0, w = 0 ;
    int ans = 0 ;


        for(int i = 0 ; i < s.size() ; i++ ) {
            if(s[i] == 'N') n++ ;
            else if( s[i] == 'W') w++ ;
            else if(s[i] == 'E') e++ ;
            else so++ ;
            int temp = abs(n - so) + abs(e - w) ;
             int rem = k ;
             if(rem < min(n , so)) {
                temp += 2 * rem ;
                rem = 0 ;
             } else {
                temp += 2 * min(n , so) ;
                rem -= min(n ,so) ;
             }

             if(rem < min(e , w)){
                temp += 2 * rem ;
             } else {
                temp += 2 * min(e , w) ;
             }

             ans = max(temp , ans) ;
        }
        
        return ans;



    }   
};