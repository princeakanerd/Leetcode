class Solution {
public:
    bool isprime(int num){
        int cnt = 0 ;
        while(num){
            cnt += num % 2;
            num /= 2;
        }
        set<int> st;
        st = {2, 3, 5, 7, 11, 13, 17,19, 23, 29, 31} ;

        return st.find(cnt) != st.end() ;
    }
    int countPrimeSetBits(int left, int right) {
        int res = 0 ;
        for(int i = left ; i <= right ;i++ ){
            res += isprime(i) ;
        }
        return res;
    }
};