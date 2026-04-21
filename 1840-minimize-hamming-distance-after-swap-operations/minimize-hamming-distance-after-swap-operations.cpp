
struct dsu{
    vector<int> parent, size ;
    int comps ;

    dsu(int n){
        parent.resize(n) ;
        size.assign(n, 1) ;
        comps = n ;
        iota(parent.begin(), parent.end(), 0) ;
    }

    int findpar(int u){
        if(parent[u] == u) return u ;
        return parent[u] = findpar(parent[u]) ;
    }

    bool unionn(int a, int b){
        int para = findpar(a), parb = findpar(b) ;
        
        if(para != parb){
            if(size[para] < size[parb]) swap(para, parb) ;

            comps -- ;
            size[para] += size[parb] ;
            parent[parb] = para;
            return true ;
        }
        return false ;
    }
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size() ;

        dsu ds(n) ;

        for(auto it : allowedSwaps){
            ds.unionn(it[0], it[1]) ;
        }
        map<int, multiset<int>> mpp;
        for(int i = 0 ; i < n ; i++ ){
            mpp[ds.findpar(i)].insert(source[i]) ;
        }

        int cnt = 0;

        for(int i = 0 ; i< n ; i++ ){
            int par = ds.findpar(i) ;
            auto it = mpp[par].find(target[i]) ;
            if(it != mpp[par].end()){
                mpp[par].erase(it) ;
            } else cnt ++ ;
        }

        return cnt ;
    }
};