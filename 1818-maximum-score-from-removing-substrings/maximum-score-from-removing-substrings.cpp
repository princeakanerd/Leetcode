class Solution {
public:
    int helper(string &s, char a, char b){
        stack<char> stk ;
        int cnt = 0 ;
        for(int i = 0 ; i < s.length() ; i++ ){
            if(s[i] == b && !stk.empty() && stk.top() == a){
                stk.pop() ;
                cnt ++ ;
            } else stk.push(s[i]) ;
        }

        string temp ;
        while(stk.size()){
            temp.push_back(stk.top()) ;
            stk.pop() ;
        }
        s = temp ;

        return cnt ;
    }   
    int maximumGain(string s, int x, int y) {
        int ans = 0 ;
        if(y > x){
            ans = y * helper(s , 'b' , 'a') ;
            ans += x * helper(s , 'b' , 'a') ;
        } else {
            ans = x * helper(s , 'a' , 'b') ;
            ans += y * helper(s , 'a', 'b') ;
        }

        return ans;
    }
};