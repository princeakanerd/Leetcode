class Solution {
    using ll = long long ;
    const int mod = 1e9 + 7 ;
public:
    ll d(int node, int par, vector<vector<int>> &adj){
        ll maxi = 0 ;
        for(auto it : adj[node]){
            if(it == par) continue ;
            maxi = max(maxi, d(it, node,  adj)) ;
        }

        return maxi + 1 ;
    }
    ll binexp(ll a, ll b){
        ll res = 1 ;

        while(b){
            if(b & 1) res = res * a % mod ;
            a = a * a % mod ;
            b >>=1 ;
        }
        return res;
    }
    ll invmod(ll a){
        return binexp(a, mod -2) ;
    }

    ll fact[100005] ;

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1 ;
        vector<vector<int>> adj(n + 1) ;

        for(auto it : edges){
            adj[it[0]].push_back(it[1]) ;
            adj[it[1]].push_back(it[0]) ;
        }
        fact[0] = 1 ;
        for(int i = 1 ; i <= n ; i++ ){
            fact[i] = 1ll * fact[i - 1] * i % mod ;
        }

        ll depth = d(1, -1,  adj) - 1 ;
        ll res = 0 ;
        for(int i = 1 ; i <= depth ; i+= 2 ){
            res = (res + fact[depth] * invmod(fact[depth - i]) % mod * invmod(fact[i]) % mod ) % mod ;

        }

        return res;

    }
};