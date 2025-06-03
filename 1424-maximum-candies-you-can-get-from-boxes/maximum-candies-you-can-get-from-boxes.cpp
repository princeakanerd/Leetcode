class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size() ;
        vector<int> havebox(n , 0) , markedopen(n ,0) , havekey(n , 0);

        for(auto it : initialBoxes) {
            havebox[it] = 1 ;
        }

        for(int i = 0 ; i < n; i++){
            if(status[i]) havekey[i] = 1 ;
        }
        int ans = 0 ;

        for(int itr = 0 ; itr < n ; itr++ ) {
            for(int i = 0 ;i < n ; i ++ ) {
                
                if(havebox[i] && havekey[i] && !markedopen[i]){
                    cout << i << endl;
                    ans += candies[i] ;
                    markedopen[i] = 1;
                    for(auto it : keys[i]){
                        havekey[it] = 1 ;
                    }
                    for(auto it : containedBoxes[i]) {
                        havebox[it] = 1 ;
                    }
                }
            }
        }
        return ans ;
    }
};