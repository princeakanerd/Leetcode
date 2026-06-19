class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0 ;
        int n =gain.size() ;
        int res = 0 ;
        for(int i = 0 ;i < n;i++ ){
            sum += gain[i] ;
            res = max(res, sum) ;
        }

        return res;
    }
};