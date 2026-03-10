class Solution {
public:
    //0101
    int zerone(vector<int> &nums){
        int miniout = INT_MAX, maxiout = INT_MIN ;
        int miniin = INT_MAX, maxiin =INT_MIN ;

        int n =nums.size() ;
         for(int i = 0 ; i < n ;i++ ){
                if(i % 2 == 0){
                    if(nums[i] % 2) {
                        miniin = min(miniin , nums[i]);
                        maxiin = max(maxiin, nums[i]) ;
                    } else {
                        miniout = min(miniout, nums[i]) ;
                        maxiout = max(maxiout, nums[i]) ;
                    }
                } else {
                    if(nums[i] % 2){
                        miniout = min(miniout, nums[i]) ;
                        maxiout = max(maxiout, nums[i]) ;
                    } else {
                        miniin = min(miniin , nums[i]);
                        maxiin = max(maxiin, nums[i]) ;
                    }
                }
            }


             if(maxiin == INT_MIN){
            return maxiout - miniout ;
        }

        if(maxiin - miniin > 1){
                return max(maxiin - 1, maxiout) - min(miniin + 1, miniout);
            }

            if(maxiin == miniin){
                int num = maxiin + 1 ;
                int res1 = max(maxiout, num) - min(num, miniout) ;
                num = maxiin - 1 ;
                int res2 = max(maxiout, num) - min(num, miniout) ;
                return min(res1, res2);
            }

            int res1 = max(maxiout, maxiin) - min(miniout, miniin) ;
            int res2 = max(maxiout, maxiin + 1) - min(miniout, miniin + 1) ;
            int res3 = max(maxiout, maxiin - 1) - min(miniout, miniin - 1) ;

            return min({res1, res2, res3}) ;
    }

    int onezero(vector<int> &nums){
        int n= nums.size() ;
         int miniout = INT_MAX, maxiout = INT_MIN ;
        int miniin = INT_MAX, maxiin =INT_MIN ;

        for(int i = 0 ; i < n ;i++ ){
                if(i % 2 == 0){
                    if(nums[i] % 2 == 0) {
                        miniin = min(miniin , nums[i]);
                        maxiin = max(maxiin, nums[i]) ;
                    } else {
                        miniout = min(miniout, nums[i]) ;
                        maxiout = max(maxiout, nums[i]) ;
                    }
                } else {
                    if(nums[i] % 2 == 0){
                        miniout = min(miniout, nums[i]) ;
                        maxiout = max(maxiout, nums[i]) ;
                    } else {
                        miniin = min(miniin , nums[i]);
                        maxiin = max(maxiin, nums[i]) ;
                    }
                }
            }


             if(maxiin == INT_MIN){
            return maxiout - miniout ;
        }

        if(maxiin - miniin > 1){
                return max(maxiin - 1, maxiout) - min(miniin + 1, miniout);
            }

            if(maxiin == miniin){
                int num = maxiin + 1 ;
                int res1 = max(maxiout, num) - min(num, miniout) ;
                num = maxiin - 1 ;
                int res2 = max(maxiout, num) - min(num, miniout) ;
                return min(res1, res2);
            }

            int res1 = max(maxiout, maxiin) - min(miniout, miniin) ;
            int res2 = max(maxiout, maxiin + 1) - min(miniout, miniin + 1) ;
            int res3 = max(maxiout, maxiin - 1) - min(miniout, miniin - 1) ;

            return min({res1, res2, res3}) ;
    }
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = nums.size() ;
        int op0 = 0 , op1 = 0 ;
        
        for(int i = 0; i < n ; i++ ){
            if(i % 2 == 0 && nums[i] % 2) op0++;
            else if(i % 2 && nums[i] % 2 == 0) op0++;

            if(i % 2 == 0 && nums[i] % 2 == 0) op1++;
            else if(i % 2 && nums[i] % 2 ) op1++;
        }

        vector<int> res ;
        res.push_back(min(op1, op0)) ;
        // culprit is in, safe is out
        int miniout = INT_MAX, maxiout = INT_MIN ;
        int miniin = INT_MAX, maxiin =INT_MIN ;
        if(op0 < op1){
            int num = zerone(nums) ;
            res.push_back(num) ;
            return res;
        } else if(op0 > op1){
            int num = onezero(nums) ;
            res.push_back(num) ;
            return res;
        } else {
            int num = min(onezero(nums), zerone(nums)) ;
            res.push_back(num) ;
            return res;
        }

        if(maxiin == INT_MIN){
            res.push_back(maxiout - miniout) ;
            return res ;
        }

            return res;
    }
};