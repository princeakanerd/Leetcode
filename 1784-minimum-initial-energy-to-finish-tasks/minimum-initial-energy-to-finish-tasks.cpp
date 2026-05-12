class Solution {
    using ll = long long ;
public:

    bool check(ll mid, vector<vector<int>> & a){
        for(int i = 0 ; i < a.size(); i++ ){
            if(mid >= a[i][1]){
                mid -= a[i][0] ;
            } else return false ;
        }

        return true ;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](vector<int> &a, vector<int> &b){
            return a[1] - a[0] > b[1] - b[0] ;
        });

        ll low = 0 , high = 1e9, ans = -1 ;

        while(low <= high){
            ll mid = low + (high - low)/ 2;
            if(check(mid, tasks)){
                ans = mid ;
                high = mid - 1 ;
            } else low = mid + 1 ;
        }
        return ans ;
    }
};