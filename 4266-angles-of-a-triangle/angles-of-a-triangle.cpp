class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(),sides.end());
        if(sides[0]+sides[1]<=sides[2]){
            return {};
        }
        vector<double>ans;
        int a=sides[0],b=sides[1],c=sides[2];
        double C = acos((a*a + b*b - c*c) / (2.0*a*b));
        double A = acos((b*b + c*c - a*a) / (2.0*b*c));
        double B = acos((a*a + c*c - b*b) / (2.0*a*c));
        A = A * 180.0 / M_PI;
        B = B * 180.0 / M_PI;
        C = C * 180.0 / M_PI;
        ans.push_back(A);
        ans.push_back(C);
        ans.push_back(B);
        sort(ans.begin(),ans.end());
        return ans;
    }
};