class Solution {
public:
    int maximumLength(vector<int>& nums) {
        for(auto &it :nums) it = it % 2 ;

        int prev = -1 , cnt = 0 , ones = 0 , zeroes = 0 ;

        for(auto it : nums){
            if(it != prev){
                cnt ++ ;
                prev = it ;
            }

            if(it) ones ++ ;
            else zeroes ++ ;
        }

        return max(cnt , max(zeroes , ones)) ;
    }
};