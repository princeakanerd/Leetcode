class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        double sum = 0 ;
        int n = nums.size() ;
        int cnt = 0 ;
        for(int i = n - 1 ;i >= 0 ; i-- ){

            if(i < n - 1){
                sum += nums[i + 1] ;
            } 

            double avg = sum / (n - i - 1) ;
            if(1.0 * nums[i] > avg) cnt ++ ;
        }

        return cnt;
    }
};