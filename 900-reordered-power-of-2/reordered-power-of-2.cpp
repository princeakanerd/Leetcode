class Solution {
public:

    bool reorderedPowerOf2(int n) {
        int num = n ;
    vector<int> a ;
    while(num){
        a.push_back(num % 10 ) ;
        num /= 10 ;
    }
    for(int i = 0 ; i <= 30 ; i++ ){
        int num =(1 << i) ;
        multiset<int> st;
        bool ispos = true ;

        while(num){
            st.insert(num % 10) ;
            num /= 10 ;
        }

        for(auto it : st) cout << it << " " ;
        cout << endl ;

        for(auto it : a){
            if(st.find(it) == st.end()){
                ispos = false ;
                break ;
            } else st.erase(st.find(it)) ;
        }

        if(st.empty() && ispos) return true ;
        

    } 

    return false ;       
    }
};