class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> temp1(n , 1) , temp2(n , 1);

        for(int i = 1 ; i < n ; i++ ) {
            if(ratings[i] > ratings[i - 1]){
                temp1[i] = temp1[i - 1] + 1 ;
            }
        }
        int ans = temp1[n - 1] ;
        for(int i = n - 2 ; i >= 0 ; i -- ) {
            if(ratings[i] > ratings[i + 1]){
                temp2[i] = temp2[i + 1] + 1 ; ;
            }
            ans += max(temp1[i] , temp2[i]) ;
        }
        return ans  ;
    }
};