class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int soonest1 = INT_MAX, soonest2 = INT_MAX, res = INT_MAX;


        int n = landDuration.size(), m = waterDuration.size() ;

        for(int i = 0 ; i < n ;i++ ){
            soonest1 = min(landStartTime[i] + landDuration[i], soonest1) ;
        }

        for(int i = 0 ; i < m ;i++ ){
            soonest2 = min(waterStartTime[i] + waterDuration[i], soonest2) ;
             res = min(max(waterStartTime[i], soonest1) + waterDuration[i], res) ;
        }

        for(int i = 0 ;i < n ; i++ ){
            res = min(res, max(landStartTime[i], soonest2)  + landDuration[i]) ;
        }
        return res;


    }
};