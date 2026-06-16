class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string temp1;
        string temp2;
        stack<char>st;
        for(char c : s){
            if(st.empty() && c == '#') continue;
            if(c!='#'){
                st.push(c);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        while(!st.empty()){
            char c= st.top();
            temp1+=c;
            st.pop();
        }
        for(char c : t){
            if(st.empty() && c == '#') continue;
            if(c!='#'){
                st.push(c);
            }
            else{
                st.pop();
            }
        }
        while(!st.empty()){
            char c= st.top();
            temp2+=c;
            st.pop();
        }
        

        return temp1 == temp2;
    }
};