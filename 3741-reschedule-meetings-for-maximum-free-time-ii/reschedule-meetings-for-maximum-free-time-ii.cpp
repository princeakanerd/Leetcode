class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size() ;

        vector<int> gap ;
        multiset<int> st ;
        
        for(int i = 0 ; i < n ;i++ ){
            if(i == 0) gap.push_back(startTime[i]) ;
            else gap.push_back(startTime[i] - endTime[i - 1]) ;
            st.insert(gap.back()) ;
        }

        gap.push_back(eventTime - endTime.back()) ;
        st.insert(eventTime - endTime.back()) ;

        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            int gap1 = gap[i] , gap2 = gap[i + 1] ;
            st.erase(st.find(gap1));
            st.erase(st.find(gap2));
            int blocksize = endTime[i] - startTime[i] ;
            int biggap = gap1 + gap2 + endTime[i] - startTime[i] ;
            ans = max(ans , biggap - (*st.rbegin() >= blocksize ? 0 : blocksize));
            st.insert(gap1) ;
            st.insert(gap2) ;
        }
        return ans;
    }
};