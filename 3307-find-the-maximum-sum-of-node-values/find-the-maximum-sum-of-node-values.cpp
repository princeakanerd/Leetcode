class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size() ;
        vector<pair<int , int>> a(n);
        int cnt = 0 ;
        long long sum = 0;
        for(int i = 0 ; i < n ; i++ ) {
            a[i].first = max(k ^ nums[i] , nums[i]) , a[i].second = min(k ^ nums[i] , nums[i]) ;
            sum += a[i].first ;
            if(a[i].first == (k ^ nums[i])) cnt ++ ;
        }

        for(auto it : a) cout << it.first << " " << it.second << endl;

        if(cnt % 2 == 0) return sum ;

        long long ans = 0 ;
        for(int i = 0 ; i < n ; i++ ) {
            
                ans = max(ans , sum - a[i].first + a[i].second) ; 
            
        }

        return ans ;

        
    }
};