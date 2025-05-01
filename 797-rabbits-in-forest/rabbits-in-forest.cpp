class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int , int> mpp ;

        for(auto it : answers){
            mpp[it] ++ ;
        }
        long long ans = 0 ;
        for(auto it : mpp) {
            ans += ((it.second + it.first ) / (it.first + 1) ) * (it.first + 1) ;
        }
        return ans;


    }
};