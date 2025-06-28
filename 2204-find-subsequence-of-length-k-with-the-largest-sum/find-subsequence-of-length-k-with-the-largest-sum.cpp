class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans ;
        int n = nums.size() ;
        priority_queue<int> pq ;
        for(int i = 0 ; i < n ; i ++ ) {
            pq.push(nums[i]) ;
        }
        map<int , int> mpp ;
        for(int i = 0 ; i < k ; i++ ) {
            mpp[pq.top()] ++ ;
            pq.pop() ;
        }

        for(int i = 0 ;i < n ; i++ ) {
            if(mpp[nums[i]] > 0) {
                mpp[nums[i]] -- ;
                ans.push_back(nums[i]) ;
            }
        }    
        return ans;
    }
};