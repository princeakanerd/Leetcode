class Solution {
public:
    vector<int> st ;
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size() ;
        multiset<int> st ;
        
        for(int i = 0 ; i < n ;i++ ){
            if(i == 0) st.insert(startTime[i]) ;
            else st.insert(startTime[i] - endTime[i - 1]) ;
            if(st.size() > 3) st.erase(st.begin()) ;
        }

        st.insert(eventTime - endTime.back()) ;
        if(st.size() > 3) st.erase(st.begin()) ;
        int ans = 0 ;

        for(int i = 0 ; i < n ; i++){
            int gap1 , gap2 ;
            if(i == 0) gap1 = startTime[i] ;
            else gap1 = startTime[i] - endTime[i - 1] ;

            if(i == n - 1) gap2 = eventTime - endTime[i] ;
            else gap2 = startTime[i + 1] - endTime[i] ;

            int block = endTime[i] - startTime[i] ;
            
            bool g1 = false, g2 = false ;
            if(st.find(gap1) != st.end()){
                st.erase(st.find(gap1)) ;
                g1 =true ;
            }
            if(st.find(gap2) != st.end()){
                st.erase(st.find(gap2)) ;
                g2 =true ;
            }

            if(*st.rbegin() >= block) ans = max(ans , block + gap1 + gap2) ;
            else ans = max(gap1 + gap2, ans) ;

            if(g1) st.insert(gap1) ;
            if(g2) st.insert(gap2) ;
        }
        return ans;
    }
};