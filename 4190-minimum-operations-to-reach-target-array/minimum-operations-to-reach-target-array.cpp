class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        set<int> st ;
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i++ ){
            if(nums[i] != target[i]){
                st.insert(nums[i]) ;
            }
        }

        return st.size() ;
    }
};