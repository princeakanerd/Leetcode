class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        map<int, int> mpp ;
        sort(nums.begin(), nums.end()) ;
        mpp[0] = 1 ;
        vector<int> temp;
        temp.push_back(0); 
        int n = nums.size() ;
        int idx = 0 ;
        vector<bool> res ;
        for(int i = 1 ; i <= n ; i++){
            
            while(idx < n && nums[idx] < i){
                int tsize = temp.size() ;
                for(int j = 0 ; j < tsize; j++ ){
                if(temp[j] + nums[idx] <= k &&  mpp.count(temp[j] + nums[idx]) == 0){
                    mpp[temp[j] + nums[idx]]++ ;
                    temp.push_back(temp[j] + nums[idx]) ;
                }
             }
            idx ++ ;
            }
            bool ispos = false ;
            for(int j = idx  ; j <= n ;j++ ){
                if(mpp.count(k - i * (j - idx))) {res.push_back(true) ; ispos = true ; break ;}
            }
            if(!ispos) res.push_back(false) ;
            
        } 
        return res ;
    }
};