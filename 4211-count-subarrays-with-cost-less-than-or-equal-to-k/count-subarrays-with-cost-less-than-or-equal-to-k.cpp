class Solution {
    using ll = long long ;
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size() ;
        multiset<int> st ;
        int j = 0 ;
        ll res = 0 ;
        for(int i = 0 ; i < n ;i++ ){
            st.insert(nums[i]) ;

            while(st.size() && 1LL * (*st.rbegin() - *st.begin()) * (i - j + 1) > k){
                st.erase(st.find(nums[j])) ;
                j++ ;
            }
            res += i - j + 1;
        }

        return res;
     }
};