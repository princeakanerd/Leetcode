class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool allnine = true ;
        int n = digits.size();

        for(int i = n - 1 ; i >= 0 ;i-- ){
            if(digits[i] == 9) digits[i] = 0;
            else {
                allnine = false ;
                digits[i] ++ ;
                break ;
            }
        } 
        if(allnine){
            digits.insert(digits.begin(), 1) ;
        }
        return digits ;
    }
};