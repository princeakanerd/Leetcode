class Solution {
public:
    int maxFreqSum(string s) {
            int f1 = 0 , f2 = 0 ;
        set<char> st = {'a' , 'e' , 'i' ,'o' , 'u'} ;
        map<char ,int> freq ;
        
        
        for(auto it : s){
            freq[it] ++ ;
        }


        for(auto it : freq) {
            if(st.find(it.first) == st.end()){
                f2 = max(f2 , it.second ) ;
            } else f1 = max(f1 , it.second) ;
        }
        return f1 + f2 ;
    }
};