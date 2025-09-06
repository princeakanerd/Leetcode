class Solution {
public:
    long long log4(long long num){
        long long cnt = 0 ;

        while(num) {
            num /= 4 ;
            cnt ++ ;
        }
        return cnt ;
    }
    long long minOperations(vector<vector<int>>& queries) {
        int n = queries.size() ;
        long long res = 0 ;
        for(auto it : queries){
                long long temp = 0 ;
                vector<long long> a ;
                a.push_back(it[0]) ;

                long long num = 1 ;
                while(num <= it[0]) num *= 4 ;
                while(num <= it[1]){
                    temp += (log4(a.back())) * (num - a.back()) ;
                    a.push_back(num) ;
                    num *= 4 ; 
                }

                temp += log4(a.back()) * (it[1] - a.back() + 1) ;


                res += (temp + 1) / 2 ;
                cout << temp << endl;

        }
        return res ;
    }
};