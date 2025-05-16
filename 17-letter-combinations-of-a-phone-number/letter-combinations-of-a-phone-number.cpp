class Solution {
public:
    vector<string> ans ;

    void f(int i ,int n , vector<string> & temp , string& digits ,string &str ){
        if(i == n ) {
            if(str.size())ans.push_back(str) ;
            
            return ;
        }
        for(int j = 0 ; j < temp[digits[i] - '0'].size() ; j++ ) {
            str.push_back(temp[digits[i] -'0'][j]);
            f(i + 1 , n ,temp , digits , str) ;
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size() ;
        vector<string> temp(10) ;
        temp[2] = "abc";
        temp[3]= "def";
        temp[4] = "ghi";
        temp[5] = "jkl";
        temp[6] = "mno";
        temp[7] = "pqrs";
        temp[8] = "tuv";
        temp[9] = "wxyz";
        string str ;
        f(0 , n ,temp , digits ,str) ;
        return ans ;

    }
};