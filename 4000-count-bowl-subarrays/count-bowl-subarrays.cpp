class Solution {
public:
    vector<int> helper(vector<int> &nums){
        
        // stores index, not values
        vector<int> dq ;
        int n = nums.size() ;
        vector<int> res(n , -1) ;
        for(int i = n - 1 ; i >= 0 ; i-- ){
            while(dq.size() && nums[dq.back()] < nums[i]) dq.pop_back()  ;

            if(!dq.empty()){
                res[i] = dq.back() ;
            }
            dq.push_back(i) ;
        }

        return res ;
        
    }
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size() ;

        vector<int> a = helper(nums) ;

        
        long long res = 0 ;
        for(long long i = 0 ; i < n ; i++ ){
            if(a[i] - i - 1 >= 1) res ++ ;
        }

        reverse(nums.begin(), nums.end()) ;
        a = helper(nums) ;
        for(auto it : a)cout << it << " " ;

        for(long long i = 0 ; i < n ; i++ ){
            if(a[i] - i - 1 >= 1) res ++ ;
        }
        return res ;

        

        
    }
};