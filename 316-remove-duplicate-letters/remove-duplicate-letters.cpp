class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int>lastidx(26);
        vector<bool>vis(26,false);
        string res;
        for(int i =0;i<n;i++){
            char ch =s[i];
            lastidx[ch-'a']=i;
        }
        for(int i=0;i<n;i++){
            char ch =s[i];
            int idx = ch-'a';
            if(vis[idx]==true) continue;
            while( res.size()>0 && res.back()>ch && lastidx[res.back()-'a']>i){
                vis[res.back()-'a']=false;
                res.pop_back();

            }
            res.push_back(ch);
            vis[ch-'a']=true;
        }
        return res;
    }
};