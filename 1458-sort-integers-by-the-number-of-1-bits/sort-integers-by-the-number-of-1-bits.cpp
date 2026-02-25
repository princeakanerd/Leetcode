class Solution {
public:
    static int popcnt(int arr){
        int cnt = 0 ;
        while(arr){
            cnt += arr % 2;
            arr /= 2;
        }
        return cnt ;
    }
    static bool cmp(int &a, int& b){
        if(popcnt(a) == popcnt(b)){
            return a < b ;
        }
        return popcnt(a) < popcnt(b) ;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp) ;
        return arr;
    }
};