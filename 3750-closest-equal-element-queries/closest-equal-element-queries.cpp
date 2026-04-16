class Solution {
    using ll = long long ;
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size() ;

        unordered_map<int,int> left, right ;
        vector<int> l(n , -1), r (n, -1) ;
        for(int i = 0; i < 2 * n ;i++ ){
            int idx = i % n ;
            if(left.count(nums[idx]) > 0){
                if(left[nums[idx]] > idx){
                    l[idx] = idx + (n - left[nums[idx]]) ;
                } else l[idx] = idx - left[nums[idx]] ;     
            }
            left[nums[idx]] = idx ;
        }

        for(int i = 2 * n - 1 ;i >= 0 ;i-- ){
            int idx = i % n;
            if(right.count(nums[idx]) > 0 ){

                if(right[nums[idx]] < idx) r[idx] = n - idx + right[nums[idx]] ;
                else r[idx] = right[nums[idx]] - idx;
            }
            right[nums[idx]] = idx ;
        }
        vector<int> res;
        for(auto it : queries){
            int temp = INT_MAX ;
            if(l[it]){
                temp = l[it] ;
            }

            if(r[it]){
                temp = min(temp, r[it]) ;
            }
            res.push_back((temp == INT_MAX ? -1 : temp)) ;
        }
        return res;
    }
};