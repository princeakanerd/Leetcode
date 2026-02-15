class Solution {
public:
    string addBinary(string a, string b) {
        string temp ;
        int n = a.length() , m = b.length() ;

        int i = n - 1, j = m - 1 ;
        int rem = 0 ;
        while(i >= 0 && j >= 0){
            int curr = a[i] - '0' + b[j] - '0' + rem ;
            rem = curr / 2;
            temp.push_back('0' + curr % 2) ;
            i-- , j-- ;
        }

        while(i >= 0){
            int curr = a[i] - '0' + rem ;
            rem = curr / 2;
            temp.push_back('0' + curr % 2);
            i-- ;
        }

        while(j >= 0){
            int curr = b[j] - '0' + rem ;
            rem = curr / 2;
            temp.push_back('0' + curr % 2) ;
            j-- ;
        }
        if(rem){
            temp.push_back('1') ;
        }

        reverse(temp.begin(), temp.end()) ;
        return temp ;


        
    }
};