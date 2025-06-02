class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string , int> mpp ;
        int len1 = 0 , len2 = 0 ;
        bool flag = false ;


        for(auto it : words) {
                mpp[it] ++ ;
        }
        for(auto it : mpp){
            if(it.first[0] == it.first[1] ){
                if (it.second % 2 == 1) flag = true ;
                len2 += (it.second / 2) * 4 ;
            } else {
                string temp = it.first ;
                reverse(temp.begin() , temp.end()) ;
                len1 += min(mpp[temp] , mpp[it.first]) * 4 ;
            }
            
        }
        int ans = len1 / 2 + len2 ;

        return flag ? ans + 2 : ans  ;
    }
};