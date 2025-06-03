class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(128,0);
        int start=0;
        int count=0;
        int ans=0;
        int maxcount=0;
        for(int end=0;end<s.length(); end++){
            v[s[end]]++;
            if(maxcount<v[s[end]]){
                maxcount=v[s[end]];
            }
            while(end-start+1-maxcount>k){
                v[s[start]]--;
                start++;
                for(int i = 0; i < 26; i++){
                    if(maxcount < v[i]){
                        maxcount = v[i];
                    }
                }   
            }
            ans=max(ans,end-start+1);  
        }
        return ans;        
    }
};