class Solution {
public:
    const int mod = 1e9 +7 ;
    static bool cmp(string &s1, string &s2){
        return (s1 + s2) > (s2 + s1) ;
    }
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size() ;
        vector<string> temp ;
        for(int i = 0 ; i < n ; i++ ){
            string s ;
            for(int j = 0 ; j < nums1[i]; j++ ) s.push_back('1') ;
            for(int j = 0 ; j < nums0[i]; j++ ) s.push_back('0') ;
            temp.push_back(s) ;
        }

        sort(temp.begin(), temp.end(), cmp) ;
        int res = 0 ;
        for(int i = 0 ; i < n ;i++ ){
            for(auto it : temp[i]){
                res = res * 2 % mod ;
                if(it == '1') res = (res + 1) % mod ;
            }
        }
        return res;
    }
};