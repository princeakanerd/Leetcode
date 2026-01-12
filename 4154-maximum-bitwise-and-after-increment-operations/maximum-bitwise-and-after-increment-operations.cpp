class Solution {
    using ll = long long ;
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        multiset<ll>st ;
        for(auto it : nums) st.insert(it) ;
        ll res = 0 ;
        for(ll i = 32 ; i >= 0 ; i-- ){
            ll cnt = 0 ;
            ll bit = (1ll << i) ;
            priority_queue<ll, vector<ll>, greater<>> pq ;
            ll numb = bit - 1 ;
            multiset<ll> newst ;

            for(auto it : st){
                if(bit & it){
                    cnt ++ ;
                    newst.insert(numb & it);
                } else {
                    pq.push(bit - it) ;
                }
            }

            ll cost = 0 ;
            ll add = 0 ;
            while(cnt < m && pq.size()){
                cost += pq.top() ;
                cnt ++ ;
                pq.pop() ;
                add ++ ;
            }

            if(cnt >= m && cost <= k){
                res += bit ;
                k -= cost ;
                for(int a = 0 ; a < add ; a++ ){
                    newst.insert(0) ;
                }
            } else {
                for(auto it : st){
                    if((bit & it) == 0) newst.insert(numb & it) ;
                }
            }

            st = newst ;
            
        }
        return res ;
    }
};