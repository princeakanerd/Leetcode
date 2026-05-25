class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length() ;

        vector<int> temp(n + 1, 0) ;
        temp[1] = 1;

        for(int i = 2 ; i <= n ;i++ ){
            if(s[i - 1] == '1'){
                temp[i] = temp[i - 1] ;
                continue ;
            }

            int maxidx = max(i - minJump, 0) , minidx = max(1, i - maxJump) ;

            if(temp[maxidx] == temp[minidx - 1]) temp[i] = temp[i - 1] ;
            else temp[i] = temp[i - 1] + 1;
        }

        // for(auto it : temp) cout << it << " " ;

        return temp[n] != temp[n - 1] ;

        
    }
};