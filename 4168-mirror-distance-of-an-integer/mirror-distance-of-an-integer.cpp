class Solution {
    using ll = long long;
public:
    int mirrorDistance(int n) {
        vector<int> temp ;
        ll og = n;
        while(n){
            temp.push_back(n % 10) ;
            n/= 10 ;
        }
        ll mul = 1 , res = 0;
        for(int i = temp.size() - 1 ; i>= 0 ; i-- ){
            res += mul * temp[i] ;
            mul *= 10 ;
        }

        return abs(og - res);
    }
};