class Solution {
public:
    int reverseBits(int n) {
        vector<int> temp ;

        int num = n ;
        while(num){
            temp.push_back(num % 2) ; 
            num /= 2;
        }
        while(temp.size() < 32) temp.push_back(0) ;

        // for(auto it : temp) cout << it << " " ;
        int res = 0 ;
        for(int i = 0 ; i < temp.size(); i++ ){
            res *= 2;
            res += temp[i] ;
        }

        return res;

    }
};