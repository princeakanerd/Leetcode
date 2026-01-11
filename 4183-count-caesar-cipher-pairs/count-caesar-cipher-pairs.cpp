class Solution {
public:
    long long countPairs(vector<string>& words) {
        map<string, int> mpp ;

        int n = words.size() ;
        long long res = 0 ;
        for(int i = 0 ; i < n ;i++ ){
            if(i == 0){
                mpp[words[i]] ++ ;
                continue ;
            }
            string s = words[i]; 
            bool flag = true ;
            for(int times = 0 ; times < 26 ; times++ ){
                if(mpp[s]){
                    res += mpp[s] ;
                    mpp[s] ++ ;
                    flag = false ;
                    break ;
                } else{
                    for(int j = 0 ; j < s.length(); j++ ){
                        s[j] = (s[j] == 'z' ? 'a' : s[j] + 1) ;
                    }
                }
            }
            if(flag)mpp[s]++ ;
        }
        return res;
    }
};