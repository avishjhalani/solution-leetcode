class Solution {
public:
const double PI = acos(-1);

double toDegree(double rad) {
    return rad * 180.0 / PI;
}
    vector<double> internalAngles(vector<int>& sides) {
        vector<double>ans;
        if((sides[0]+sides[1])<=sides[2] || (sides[1]+sides[2])<=sides[0] || 
        (sides[0]+sides[2])<=sides[1]){
            return ans;
        }
        double a = sides[0];
        double b = sides[1];
        double c = sides[2];

        double A = toDegree(acos((b*b+c*c-a*a)/(2*b*c)));
        double B = toDegree(acos((a*a+c*c-b*b)/(2*a*c)));
        double C = toDegree(acos((a*a+b*b-c*c)/(2*b*a)));
       
        ans.push_back(A);
        ans.push_back(B);
        ans.push_back(C);
        sort(ans.begin(),ans.end());

        return ans;
    }
};