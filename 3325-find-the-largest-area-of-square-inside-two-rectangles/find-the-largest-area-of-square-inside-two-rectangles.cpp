class Solution {
public:
    bool static comp(vector<int> &a, vector<int> &b)
    {
        if(a[0]!=b[0]) return a[0]<b[0];
        if(a[1]!=b[1]) return a[1]<b[1];
        if(a[2]!=b[2]) return a[2]<b[2];
        return a[3]<b[3];
    }
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        
        int n = bottomLeft.size();

        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            v.push_back({bottomLeft[i][0],bottomLeft[i][1],topRight[i][0],topRight[i][1]});
        }
        sort(v.begin(),v.end(),comp);

        long long ans=0;
        for(int i=0;i<n;i++)
        {
            long long x1=(long long)v[i][0]; long long y1=(long long)v[i][1]; long long x2=(long long)v[i][2]; long long y2=(long long)v[i][3];
            for(int j=i+1;j<n;j++)
            {
                long long p1 = (long long)v[j][0]; long long q1 = (long long)v[j][1]; long long p2=(long long)v[j][2]; long long q2=(long long)v[j][3];

                if(p1>=x1 && p1<=x2) {
         
                    long long xlen = min(x2,p2)-p1;

                    long long ylen=0;

                    if(q2>=y1 && q2<=y2){
                        ylen = q2-max(q1,y1);
                    }else if(q2>y2){
                        ylen = y2 - max(y1,q1);
                    }

                    long long mnlen = min(xlen,ylen);

                    if(mnlen>0)
                        ans = max(ans,mnlen*mnlen);
                }else{
                    break;
                }     
            }
        }

        return ans;
    }
};