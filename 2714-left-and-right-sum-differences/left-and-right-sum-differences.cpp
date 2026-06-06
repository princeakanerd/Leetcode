class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> pfx(n + 1, 0), sfx(n + 1, 0) ;

        for(int i = 1 ; i < n;i++ ){
            pfx[i] = pfx[i - 1] + nums[i - 1] ;
        }

        for(int i = n - 1 ; i >= 0 ;i -- ){
            sfx[i] = sfx[i + 1] + nums[i] ;
        }
        vector<int> res ;

        for(int i = 0 ;i <n ;i++ ){
            res.push_back(abs(pfx[i] - sfx[i + 1])) ;
        }

        return res;
    }

};