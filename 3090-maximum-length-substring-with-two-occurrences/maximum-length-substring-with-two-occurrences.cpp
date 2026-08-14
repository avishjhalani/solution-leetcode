class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int i=0,j=0,count=0;
        unordered_map<int,int>mp;
        for(j=0;j<n;j++){
            mp[s[j]]++;
            while(mp[s[j]]>2){
                mp[s[i]]--;
                i++;
            }
            count =max(count,j-i+1);
        }
        return count;
    }
};