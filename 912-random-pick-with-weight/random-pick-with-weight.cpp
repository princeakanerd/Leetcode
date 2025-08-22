class Solution {
public:
    vector<int> pfx;
    

    Solution(vector<int>& w) {
         srand(time(0));
        int n = w.size() ;
        for(auto it : w){
            pfx.push_back(it + (pfx.size() ? pfx.back() : 0) ) ;
            cout << pfx.back() << " " ;
        }

    }
    
    int pickIndex() {
       
        int maxi = pfx.back() ;
        int num = rand() % maxi + 1 ;
        int idx = lower_bound(pfx.begin(), pfx.end(), num) - pfx.begin() ;
        return idx ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */