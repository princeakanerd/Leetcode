class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        map<int , vector<int> > mpp ;


        int n = limit.size() ;
        for(int i = 0 ; i < n ; i ++ ){
            mpp[limit[i]].push_back(value[i]) ;
        }

        for(auto &it : mpp){
            sort(it.second.rbegin() , it.second.rend()) ;
        }   

        // for(int i = 1 ; i <=n ; i++ ){
        //     for(int j = 0 ; j <(int)mpp[i].size() ; j++){
        //         cout << mpp[i][j] << " " ;
        //     }
        //     cout << endl;
        // }

        long long ans = 0 ;

        for(int i = 1 ; i <= n ; i++ ){
            
            for(int j = 0 ; j < min((int)mpp[i].size() , i) ; j++ ){
                ans += mpp[i][j] ;
            }
        }
        return ans ;
    }
};