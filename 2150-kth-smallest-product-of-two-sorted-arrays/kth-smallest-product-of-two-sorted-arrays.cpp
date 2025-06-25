class Solution {
public:
    long long check(long long num , vector<int> & nums1 , vector<int> & nums2 ) {
        long long cnt = 0 ;
        for(auto it : nums1 ) {
            long long low = 0, high = nums2.size() - 1 , res = -1 ;
            if(it >= 0) {
                while(low <= high) {
                    long long mid = low + (high - low) / 2;
                    if(1LL * nums2[mid] * it <= num){
                        res = mid ; 
                        low = mid + 1 ;
                    } else high = mid - 1;
                }


                cnt +=  res + 1 ;
            } else {

                while(low <= high) {
                    long long mid = low + (high - low) / 2;
                    if(1LL *nums2[mid] * it > num){
                        res = mid ; 
                        low = mid + 1 ;
                    } else high = mid - 1;
                }
                cnt += nums2.size() - (res + 1);
            }
        }

        return cnt ;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long high = 1e10 , low = -1e10 , ans = LLONG_MIN ;
        
        while(low <= high) {
            long long mid = low + (high - low) / 2 ;

            if(check(mid , nums1 , nums2) >= k){
                ans = mid ;
                high = mid - 1;
            } else low = mid + 1;
        }

        return ans;
    }
};