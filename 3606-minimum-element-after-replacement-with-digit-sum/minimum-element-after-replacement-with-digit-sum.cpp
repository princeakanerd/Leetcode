class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX ;

        int n = nums.size() ;

        for(auto it : nums){
            int num = it ;
            int sum = 0 ;
            while(it){
                sum += it % 10 ;
                it /= 10 ;
            }
            mini = min(mini, sum) ;
        }
        return mini ;


    }
};