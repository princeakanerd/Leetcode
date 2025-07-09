class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size() ;
        vector<int> gaps ;
        int last = 0 ;
        for(int i = 0 ; i < n ; i++ ) {
            gaps.push_back(startTime[i] - last) ;
            last = endTime[i] ;
        }
        gaps.push_back(eventTime - endTime.back()) ;

        int window = k + 1;
        long long ans = 0 ;
        long long sum = 0 ;
        for(int i = 0 ;i < gaps.size() ; i++ ) {
            sum += gaps[i] ;
            if(i >= window) sum -= gaps[i - window] ;
            if(i >= min(window - 1 , n - 1 )) ans = max(ans , sum) ;
        }
        



        return ans ;

        
    }
};