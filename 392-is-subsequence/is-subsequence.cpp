class Solution {
public:
    bool isSubsequence(string s, string t) {
        int st=0;
        int tt=0;
        
        while(st<s.size() && tt<t.size()){
            if(s[st]==t[tt]){
                st++;
            }
            tt++;
            
        }
        return st == s.size();
    }
};