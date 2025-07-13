class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size() , m = trainers.size() ;
        int i = n - 1 , j = m - 1 ;
        sort(players.begin() , players.end()) ;
        sort(trainers.begin() , trainers.end()) ;
        int cnt = 0 ;
        while(i >= 0 && j >= 0){
            
            if(players[i] <= trainers[j]){
                j-- ;
                cnt ++ ;
            }
            i-- ;
        }

        return cnt ;
    }
};