class Solution {
    using ll = long long ;
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& health, string directions) {
        stack<pair<ll,ll>> stk ;

        vector<vector<ll>> a ;
        int n = positions.size() ;

        for(int i = 0 ;i < n ;i++ ){
            a.push_back({positions[i], health[i], (directions[i] == 'L' ? 0 : 1)}) ;
        }
        sort(a.begin(),a.end()) ;
        vector<int> res ;
        map<int,int> mpp ;

        for(int i = 0; i < n; i++ ){
            ll hlth = a[i][1] ;
            if(a[i][2] == 1){
                stk.push(make_pair(hlth, a[i][0])) ;
            } else {
                bool flag = true ;
                    while(!stk.empty()){
                        if(hlth > stk.top().first){
                            hlth -- ;
                            stk.pop() ;
                        } else if(hlth == stk.top().first) {
                            flag = false ;
                            stk.pop() ;
                            break ;
                        }
                        else {
                            stk.top().first-- ;
                            break ;
                        }
                    }

                if(flag && stk.empty()) mpp[a[i][0]] = hlth ;
            }
        }

        while(stk.size()){
            auto [hlth, idx] = stk.top() ;
            stk.pop() ;
            mpp[idx] = hlth ;
        }

        for(int i = 0 ;i < n ;i++ ){
            if(mpp.count(positions[i])) res.push_back(mpp[positions[i]]) ;
        }
        return res;
    }
};