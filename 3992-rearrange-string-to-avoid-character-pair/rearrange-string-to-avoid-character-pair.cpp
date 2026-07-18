class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int i =0,j=0;
        string a ;
        for(char c :s){
            if(c == x)i++;
            else if(c==y)j++;
            else a+=c;
        }
        string ans;
        ans.append(j,y);
        ans+=a;
        ans.append(i,x);
        return ans;
    }
};