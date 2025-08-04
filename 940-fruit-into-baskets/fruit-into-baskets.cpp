class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int ,int> mpp ;
        int ans = 0 ;

        int n = fruits.size() , i = 0 ;
        for(int j = 0 ; j < n ; j++ ){
            mpp[fruits[j]] ++ ; 

            while(mpp.size() > 2){
                mpp[fruits[i]] -- ;
                if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]) ;
                i++ ; 
            }

            ans = max(ans , j - i + 1 ) ;
        }
        return ans ;
    }
};