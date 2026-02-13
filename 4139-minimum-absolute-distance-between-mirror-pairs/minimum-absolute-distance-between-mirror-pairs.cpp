class Solution {
public:
    int rev(int n){
        int num = 0 ;
        while(n){
            num *= 10 ;
            num += n % 10 ;
            n /= 10 ;
        }
        return num ;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        
        map<int,vector<int>> mpp ;
        int n = nums.size() ;
        for(int i = n - 1 ; i >= 0 ; i-- ){
            mpp[nums[i]].push_back(i) ;
        }
       
        int res = INT_MAX ;
        for(int i = 0 ; i < n ;i++ ){
            mpp[nums[i]].pop_back() ;
            int num = rev(nums[i]) ;
            if(!mpp[num].empty()){
                res = min(res, mpp[num].back() - i ) ;
            }
        }

        return (res == INT_MAX ? -1 : res) ;


    }
};