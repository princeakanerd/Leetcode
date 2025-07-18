class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        
        int n = nums.size() ;
        multiset<int> first, last , candidates ;
        long long sum1 = 0 , sum2 = 0 , ans = 1e12 ;
        for(int i = 0 ; i < n / 3 ; i++){
            first.insert(nums[i]) ;
            sum1 += nums[i] ;
        }

        priority_queue<int> pq ;
        for(int i = n / 3 ; i < n ; i++ )pq.push(nums[i]) ;

        for(int i = 0 ; i < n / 3 ; i++ ) {
            last.insert(pq.top()) ;
            sum2 += pq.top() ;
            pq.pop() ;
        }
        for(int i = 0 ; i < n / 3 ; i++ ) {
            candidates.insert(pq.top()) ;
            pq.pop() ;
        }

    
        ans = min(ans , sum1 - sum2) ;

        for(int i = n / 3 ; i < 2 * n / 3 ; i++ ){
            sum1 += nums[i] ;
            first.insert(nums[i]) ;
            sum1 -= *first.rbegin() ;
            first.erase(prev(first.end())) ;

            if(nums[i] >= *last.begin()){
                sum2 -= nums[i] ;
                last.erase(last.find(nums[i])) ;
                last.insert(*candidates.rbegin()) ;
                sum2 += *candidates.rbegin() ;
                candidates.erase(prev(candidates.end())) ;
            } else{
                candidates.erase(candidates.find(nums[i])) ;
            }
            

            ans = min(sum1 - sum2 , ans) ;
        }

       
        return ans ;



       



    }
};