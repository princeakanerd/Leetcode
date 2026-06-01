class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int sum = 0 ;
        sort(cost.begin(), cost.end()) ;
        int n = cost.size() ;
        for(int i = n - 1 ;i >= 0 ; i-- ){
            if((n - i) % 3 != 0) sum += cost[i] ;
        }
        return sum ;
    }
};