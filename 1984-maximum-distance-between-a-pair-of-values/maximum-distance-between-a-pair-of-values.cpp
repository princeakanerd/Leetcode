class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size(), m = nums2.size() ;
        int i = n - 1 , j = m - 1 ;
        int res = 0 ;
        while(i >= 0 && j >= 0){

            while(j >= 0 && nums2[j] < nums1[i]){
                j-- ;
            }
            res = max(res, j - i) ;
            i-- ;
        }   

        return res;
    }
};