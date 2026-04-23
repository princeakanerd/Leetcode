class Solution {
    using ll = long long ;
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size() ;
        unordered_map<int,vector<int>> mpp ;
        for(int i = 0 ; i < n ;i++){
            mpp[nums[i]].push_back(i) ;
        }
        vector<long long> res(n, -1) ;
        for(auto it : mpp){
            vector<int> temp = it.second ;
            int num = it.first ;

            if(temp.size() == 1) {res[temp[0]] = 0 ; continue ;}

            ll l = 0, r = temp.size() ;
            ll sum = 0 ;

            for(int i = 1 ; i < temp.size() ;i ++ ){
                sum += temp[i] - temp[0] ;
            }
            res[temp[0]] = sum ;

            for(int i = 1 ; i < temp.size(); i++){
                r-- ;
                l ++ ;
                sum += 1ll * (l - r) * (temp[i] - temp[i - 1]) ;
                res[temp[i]] = sum ;
            }
        }
        return res;
    }
};