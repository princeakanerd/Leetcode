class Solution {
    using ll = long long ;
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<ll> stk ;

        int n = nums.size() ;

        for(int i= 0 ;i < n ;i++ ){
            
            ll ele = nums[i] ;

            while(stk.size() && ele == stk.top()){
                stk.pop() ;
                ele *= 2 ;
            }
            stk.push(ele) ;
        }

        vector<ll> res ;

        while(stk.size()){
            res.push_back(stk.top()) ;
            stk.pop() ;
        }


        reverse(res.begin(), res.end()) ;
        return res;
    }
};