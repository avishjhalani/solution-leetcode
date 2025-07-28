class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        stack<int>nums;
        int num =0;
        string cur ="";
        for(char ch:s){
            if(isdigit(ch)){
                num = num*10+(ch-'0');
            }
            else if(ch=='['){
                nums.push(num);
                st.push(cur);
                num=0;
                cur="";
            }
            else if(ch==']'){
                int repeat = nums.top();
                string top = st.top();
                nums.pop();
                st.pop();
                while(repeat--){
                    top+=cur;
                }
                cur =top;
            }
            else{
                cur+=ch;
            }
            
        }
        return cur;
    }
};