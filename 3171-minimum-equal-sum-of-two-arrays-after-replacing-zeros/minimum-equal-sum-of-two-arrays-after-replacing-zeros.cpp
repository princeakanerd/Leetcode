class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long cnt1 = 0 , cnt2 = 0 ;

        for(int i = 0 ;i < nums1.size() ; i++ ) {
            cnt1 += (nums1[i] == 0) ; 
        }

        for(int i = 0 ; i < nums2.size() ; i++ ) {
            cnt2 += (nums2[i] == 0) ;
        }

        for(int i = 0 ; i < nums1.size() && cnt1 > 1 ; i++ ) {
            if(!nums1[i]) {nums1[i] = 1; cnt1--;}
        }

        for(int i = 0 ; i < nums2.size() && cnt2> 1 ; i++ ) {
            if(!nums2[i]) {nums2[i] = 1; cnt2--;}
        }

        long long sum1 = 0 , sum2 = 0 ;

        for(int i = 0 ; i < nums1.size() ; i++ ) {
            sum1 += nums1[i] ;
        }
        for(int i = 0 ;i < nums2.size() ; i++) {
            sum2 += nums2[i] ;
        }

        if(sum1 > sum2) {
            if(cnt2 == 1) {
                return (cnt1 == 1)? sum1 + 1 : sum1 ;
            } 
            return -1 ;
        } else if (sum1 < sum2) {
            if(cnt1 == 1) {
                return (cnt2 == 1) ? sum2 + 1 : sum2 ;
            }
            return -1 ;
        } else {
            if(cnt1 == cnt2) {
                return (cnt1) ? sum1 + 1 : sum1 ;
            }
            return -1 ;

        }

        

        return -2 ;




    }
};