class Solution {
    using ll = long long ;
public:
    int sgtmini[400000], sgtmaxi[400000] ;

    void build(ll s, ll e, ll idx, vector<int> &a){
        if(s == e) {
            sgtmini[idx] = sgtmaxi[idx] = a[s] ;
            return ;
        }
        ll mid = (s + e) / 2;
        build(s, mid, 2 * idx, a) ;
        build(mid + 1, e, 2 * idx + 1 ,a) ;

        sgtmini[idx] = min(sgtmini[2 * idx] , sgtmini[2 * idx + 1] ); 
        sgtmaxi[idx] = max(sgtmaxi[2 * idx] , sgtmaxi[2 * idx + 1]) ; 
    }

    // mini, maxi
    pair<ll,ll> query(ll s, ll e, ll idx, ll l , ll r){
        if(r < s || l > e) return make_pair(INT_MAX, INT_MIN) ;
        if(s >= l && e <= r) return make_pair(sgtmini[idx], sgtmaxi[idx]);

        ll mid = (s + e) / 2;
        auto p1 = query(s, mid, 2 * idx, l, r) ;
        auto p2 = query(mid + 1, e, 2 * idx + 1, l , r) ;

        return make_pair(min(p1.first, p2.first), max(p1.second,p2.second)) ;
    }

    
    long long maxTotalValue(vector<int>& a, int k) {
        int n = a.size() ;

        priority_queue<pair<ll,pair<ll,ll>>> pq ;
        build(0, n - 1, 1, a) ;
        for(int i = 0 ; i < n ;i++ ){
            auto p = query(0, n - 1, 1, i, n - 1 ) ;
            pq.push(make_pair(p.second - p.first, make_pair(i, n - 1))) ;
        }
        ll res = 0 ;
        while(k--){
            auto p = pq.top() ;
            pq.pop() ;
            int l = p.second.first , r = p.second.second;
            r-- ;
            if(r < l) continue ;
            auto q = query(0, n - 1, 1, l, r) ;
            res += p.first;
            
            pq.push(make_pair(q.second - q.first, make_pair(l, r))) ;
        }

        return res;
        
    }
};