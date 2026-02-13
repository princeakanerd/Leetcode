class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()) ;
        int cnt = 1 ;
        int total = 0 ;
        int res = 0 ;
        int n = nums.size() ;
        for(int i = n - 2 ; i >= 0 ; i-- ){
            if(nums[i] == nums[i + 1]){
                cnt ++ ;
            } else {
                if(total >= k) res += cnt ;
                total += cnt ;
                cnt = 1;
            }
        }
        if(total >= k) res += cnt ;
        return res ;
    }
};