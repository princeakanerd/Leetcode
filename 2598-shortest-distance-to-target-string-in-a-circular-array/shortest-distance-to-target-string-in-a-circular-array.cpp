class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size() ;
        int res = INT_MAX ;
        for(int i= 0 ;i < n ;i++){
            if(words[i] == target){
                if(i > startIndex){
                    res = min(res, i - startIndex) ;
                    res = min(res, n - i + startIndex) ;
                } else {
                    res = min(res, startIndex - i ) ;
                    res = min(res, i + n - startIndex) ;
                }
            }
        }

        return (res == INT_MAX ? -1 : res) ;
    }
};