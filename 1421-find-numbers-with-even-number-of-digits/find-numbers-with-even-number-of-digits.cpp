class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0 ;
        for(auto it : nums) count += (((int)log10(it) + 1) % 2 == 0) ;
        return count ;
    }
};