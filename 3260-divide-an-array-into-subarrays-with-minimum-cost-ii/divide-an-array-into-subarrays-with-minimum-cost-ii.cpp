class Solution {
    using ll = long long ;
public:
    void balance(int k, multiset<ll>& small, multiset<ll> &big, ll &ss, ll &sb){

        while(small.size() > k){
            ll ele = *small.rbegin() ;
            ss -= ele ;
            sb += ele ;
            big.insert(ele) ;
            small.erase(prev(small.end())) ;
        }
        while (small.size() < k && !big.empty()) {
        ll ele = *big.begin();
        sb -= ele;
        ss += ele;
        small.insert(ele);
        big.erase(big.begin());
    }

        while(small.size() && big.size() && *small.rbegin() > *big.begin()){
            ll ele = *small.rbegin(), ele2 = *big.begin() ;
            ss -= ele ;
            sb -= ele2 ;
            ss += ele2 ;
            sb += ele ;
            small.erase(prev(small.end())) ;
            big.erase(big.begin()) ;
            small.insert(ele2) ;
            big.insert(ele) ;
        }

    }

    void del(int ele, multiset<long long> & small, multiset<ll> &big, ll &ss, ll &sb){

        if(ele > *small.rbegin()){
            big.erase(big.find(ele)) ;
            sb -= ele ;
        } else {
            small.erase(small.find(ele)) ;
            ss -= ele ;
        }
    }


    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        ll res = LLONG_MAX ;
        ll ss = 0 , sb = 0 ;
        
        int last = dist ;
        multiset<ll> small, big ;
        for (int i = 1; i < n; i++) {
    small.insert(nums[i]);
    ss += nums[i];
        balance(k - 1, small, big, ss, sb);
    
   
    if (i > dist + 1) {
        int rem = nums[i - (dist + 1)];
        del(rem, small, big, ss, sb);
        balance(k - 1, small, big, ss, sb);
    }
    
    if (i >= dist + 1) {
        res = min(res, ss);
    }
}

        return res + nums[0] ;

    }

};