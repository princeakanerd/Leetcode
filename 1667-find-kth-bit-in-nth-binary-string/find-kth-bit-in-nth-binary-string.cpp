class Solution {
public:
    string f(string s){
        string temp = s; 
        s.push_back('1') ;
        for(int i = 0 ; i < temp.size(); i++ ){
            if(temp[i] == '1') temp[i] = '0' ;
            else temp[i] = '1' ;
        }
        reverse(temp.begin(), temp.end()) ;

        s += temp ;
        return s;
    }
    char findKthBit(int n, int k) {
        string s = "0" ;
        for(int i = 0 ; i < n ;i++ ){
            s = f(s) ;
        }

        return s[k - 1] ;
    }
};