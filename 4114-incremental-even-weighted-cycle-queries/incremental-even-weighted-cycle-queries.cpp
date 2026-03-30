class dsu{
    public: 
    vector<int> parent, size, parity ;

    dsu(int n){
        parent.resize(n) ;
        size.resize(n, 1);
        parity.resize(n, 0)  ;

        for(int i = 0 ; i < n ;i++ ) parent[i] = i ;
    }

    pair<int,int> find(int x){
        if(parent[x] == x) return {x, 0} ;

        //finding root recursively
        auto [root, par] = find(parent[x]) ;
        parity[x] = (parity[x] + par) % 2;
        //path comp
        parent[x] = root ;
        return {root, parity[x]} ;
    }

    bool unionn(int u, int v,int w){
        auto [ru, pu] = find(u) ;
        auto [rv, pv] = find(v) ;

        // already in same components 
        if(ru == rv){
            return ((pu + pv + w) % 2 == 0) ;
        }

        // diff comp

        if(size[ru] < size[rv]){
            swap(ru, rv) ;
            swap(pu, pv) ;
        }

        parent[rv] = ru ;
        size[ru] += size[rv] ;

        parity[rv] = (pu + pv + w) % 2;
        return true ;
    }



};
class Solution {
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        dsu ds(n) ;
        int cnt = 0 ;
        for(auto it : edges){
            if(ds.unionn(it[0], it[1], it[2])) cnt ++ ;
        }
        return cnt ;
    }
};