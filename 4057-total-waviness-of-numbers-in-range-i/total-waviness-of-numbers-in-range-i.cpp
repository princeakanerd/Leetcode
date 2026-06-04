class Solution {
public:
    int f(int n){
        int cnt = 0 ;
        vector<int> digs ;
        while(n){
            digs.push_back(n % 10) ;
            n /= 10 ;
        }

        for(int i = 1 ; i < digs.size() - 1 ; i++ ){
            if((digs[i] > digs[i - 1] && digs[i] > digs[i + 1]) || (digs[i] < digs[i - 1] && digs[i] < digs[i + 1])) cnt ++ ;
        }
        return cnt ;
    }

    int totalWaviness(int num1, int num2) {
        int res = 0 ;
        for(int i = num1 ; i <= num2 ;i++ ){
            res += f(i) ;
        }
        return res;
    }
};