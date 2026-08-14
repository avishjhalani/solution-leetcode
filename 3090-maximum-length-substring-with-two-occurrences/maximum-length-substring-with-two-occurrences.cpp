class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int i=0,j=0,count=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]]>2){
                mp[s[i]]--;
                i++;
            }
            count =max(count,j-i+1);
            j++;
        }
        return count;
    }
};