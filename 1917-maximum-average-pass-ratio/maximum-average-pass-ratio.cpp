class Solution {
public:

    
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {


        auto cmp = [](const vector<double>& a, const vector<double>& b) {
            double gainA = (a[1] + 1) / (a[2] + 1) - a[1] / a[2];
            double gainB = (b[1] + 1) / (b[2] + 1) - b[1] / b[2];
            return gainA < gainB; 
        };

        priority_queue<vector<double>, vector<vector<double>>, decltype(cmp)> pq(cmp);
        int n = classes.size() ;
        for(auto i : classes ) {
            pq.push({double(i[0])/double(i[1]) , double(i[0]) , double(i[1])}) ;
        }

        for(int i = 0 ; i < extraStudents ; i++ ) {
            vector<double> temp = pq.top() ;
            temp[1] ++ , temp[2] ++ ;
            temp[0] = double(temp[1]) / double( temp[2]) ;

            pq.pop() ;
            pq.push(temp) ;
        }

         double sum = 0 ;
        
        while(!pq.empty()) {
            sum += pq.top()[0] ;
            pq.pop() ;
        }

        return sum / static_cast<double > (n) ;

    }
};