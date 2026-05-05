class Solution {
    using ll = long long ;
public:
    long long minOperations(vector<int>& a) {
        int n = a.size() ;
        ll sum = 0 ;
        for(int i = 1 ;i < n ;i++ ){
            sum += max(0, a[i - 1] - a[i]) ;
        }

        return sum ;
    }
};