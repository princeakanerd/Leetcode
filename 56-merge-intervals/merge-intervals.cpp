class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end()) ;
        vector<vector<int>> ans ;
        int l = intervals[0][0], r = intervals[0][1] ;
        for(int i = 0 ; i + 1< intervals.size() ; i++ ) {
            if(r >= intervals[i + 1][0]){
                r = max(intervals[i + 1][1] , r) ;
            } else {
                ans.push_back({l , r}) ;
                l = intervals[i + 1][0] , r = intervals[i + 1][1] ;
            }
        }
        ans.push_back({l , r}) ;
        return ans ;
    }
};