class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        // cosA = b*b + c * c - a* a / 2bc

        double a = sides[0], b = sides[1], c = sides[2] ;
        vector<double> res ;
        if((a + b) <= c || (b + c <= a) || (a + c <= b)) return res;

        double val =  (b * b + c * c - a * a) / (2 * b * c) ;
        res.push_back(1.0 * acos(val) * 180 / (3.1415926535)) ;
        val = (a * a + c * c - b * b) / (2 * a * c) ;
        res.push_back(1.0 * acos(val) * 180 / (3.1415926535)) ;
        val = (a * a + b * b - c * c) / (2 * a * b) ;
        res.push_back(1.0 * acos(val) * 180 / (3.1415926535)) ;

        sort(res.begin(), res.end()) ;
        return res;
    }
};