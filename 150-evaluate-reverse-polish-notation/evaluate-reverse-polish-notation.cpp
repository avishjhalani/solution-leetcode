// class Solution {
// public:
// bool isOperator(string s){
//     if(s=="+"|| s=="*"||s=="/" || s=="-" ){
//         return true;
//     }
//     return false;
// }
// int solve(int b , string s, int a){
//     if(s=="+") return a+b;
//     else if(s=="-") return b-a;
//     else if(s=="*") return a*b;
//     else if(s=="/") return b/a;
//     else return 0;
// }
//     int evalRPN(vector<string>& post) {
//         stack<int>st;
        
//         for(string s:post){
//             if(isOperator(s)){
//                 int a =st.top();
//                 st.pop();
//                 int b =st.top();
//                 st.pop();
//                  int result = solve(b, s, a);
//                 st.push(result);
//             }
//             else{
//                 st.push(stoi(s));

//             }
//         }
        
// return st.top();
//     }
// };
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stk;
       for (int i = 0; i < tokens.size(); i++)
       {
        //string token = tokens[i];
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
            int n = stk.back() ;
            stk.pop_back();
            int m = stk.back() ;
            stk.pop_back();
            if (tokens[i] == "+") stk.push_back((n+m) );
            if (tokens[i] == "-") stk.push_back((m-n) );
            if (tokens[i] == "*") stk.push_back((n*m) );
            if (tokens[i] == "/") stk.push_back((m/n) );
        }
        else{
            stk.push_back(stoi(tokens[i]));
        }
       } 
        return stk.back();
    }
   
};
