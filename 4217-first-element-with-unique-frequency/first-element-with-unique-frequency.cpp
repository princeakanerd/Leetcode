class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int,int> mpp ;
        int n = nums.size();

        for(auto it : nums) mpp[it] ++ ;

        map<int,int> freq ;

        for(auto it :mpp) freq[it.second] ++ ;
        for(int i = 0 ; i < n;i++ ){
            if(freq[mpp[nums[i]]] == 1) return nums[i] ;
        }
        return -1 ;
    }
};