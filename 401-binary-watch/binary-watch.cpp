class Solution {
public:
    string f(int num){
        int mins = 0 ;

        for(int i = 0 ; i < 6 ;i++ ){
            mins *= 2;
            mins += num % 2;
            num /= 2;
        }
        if(mins >= 60) return "-1" ;
       
        if(num > 11) return "-1" ;
        
        string shrs = to_string(num) ;
        string smins = to_string(mins) ;
        if(smins.size() == 1) smins = "0" + smins ;

        return shrs + ":" + smins ;
    }
    int popcount(int n){
        int cnt = 0 ;
        while(n){
            cnt += (n % 2) ;
            n /= 2 ;
        }
        return cnt ;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        set<string> st ;
        int up = (1LL << 11);
        for(int i = 0 ; i < up ; i++ ){
            int bits = popcount(i) ;
            if(bits == turnedOn){
                string temp = f(i) ;
                if(temp != "-1") st.insert(temp) ;
            }
        }

        vector<string> res(st.begin(), st.end()) ;


        return res;
    }
};