class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long maxdev = 0, mindev = 0 ;
        int diff = upper - lower ;
        long long sum = 0 ;
        for(auto it : differences ) {
            sum += it ;
            maxdev = max(maxdev , sum) ;
            mindev = min(mindev , sum) ;
        }
        return max(0LL ,diff + 1 - (maxdev - mindev)) ;


    }
};