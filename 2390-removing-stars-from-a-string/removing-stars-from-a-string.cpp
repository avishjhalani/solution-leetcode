class Solution {
public:
    string removeStars(string s) {
        int n =s.size();
       stack<char>st;
       for(char ch:s){
        if(ch=='*'){
            if(!st.empty()) st.pop();
            
        }else st.push(ch);
       }
       string ans = "";
       int i =0;
       while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
        i++;
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};