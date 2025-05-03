// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         int n = s.size();
//         int m =goal.size();
//         if(n!=m) return false;
//         for(int i =1;i<=n;i++){
//             rotate(begin(s),begin(s)+1,end(s));
//             if(s==goal){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string t=s+s;
        return t.find(goal) != string::npos;
    }
};