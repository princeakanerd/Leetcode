class Solution {
public:
    set<int> st ;

    void f(vector<int>& digits, vector<int> &digitspicked, long long res){

        if(res >= 1000) return  ;
        if(res >= 100 && res < 1000 && res % 2 == 0){
            st.insert(res) ;
            return ;
        }
        for(int i = 0 ;i < digits.size() ;i++ ){
            if(!digitspicked[i]){
                if(digits[i] == 0 && res == 0) continue ;
                digitspicked[i] =true ;
                f(digits , digitspicked , res* 10 + digits[i]) ;
                digitspicked[i] = false ;
            }
        }
    }
    int totalNumbers(vector<int>& digits) {
            int n = digits.size() ;
            vector<int> digitspicked(n, 0) ;
             f(digits , digitspicked, 0) ;

            return st.size() ;
    }
};