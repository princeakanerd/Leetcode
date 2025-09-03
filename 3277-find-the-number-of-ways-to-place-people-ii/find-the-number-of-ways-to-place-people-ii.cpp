class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](vector<int> a , vector<int> b){
            if(a[0] == b[0]){
                return a[1] > b[1] ;
            }
            return a[0] < b[0] ;
        }) ;

        int n = points.size() ;
        int res = 0 ;
        for(int i = 0 ; i < n ;i++ ){
            vector<int> mono ;
            int basey = points[i][1] ;
            for(int j = 0 ; j < i ; j++ ){
                if(points[j][1] < basey) continue ;
                while(mono.size() && points[j][1] <= mono.back()) mono.pop_back() ;
                mono.push_back(points[j][1]) ;
            }
            res += (int)mono.size() ;

        }
        return res ;

    }
};