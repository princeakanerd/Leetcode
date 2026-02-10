class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        
        int n = nums.size() ;

        for(int len = n ; len >= 1 ; len -- ){
            map<int,int> odd, even ;
            for(int i = 0 ; i < n ;i ++ ){
                if(nums[i] % 2) odd[nums[i]] ++ ;
                else even[nums[i]] ++ ;
                if(i >= len){
                    if(nums[i - len] % 2) {
                        odd[nums[i - len]] -- ;
                        if(odd[nums[i - len]] == 0) odd.erase(nums[i - len]) ;
                    } else {
                        even[nums[i - len]] -- ;
                        if(even[nums[i - len]] == 0) even.erase(nums[i - len]) ;
                    }
                }
                if(i >= len - 1 && odd.size() == even.size()){
                    return len ;
                }   
                
            }
        }

        return 0 ;
    }
};