class Solution {
public:

     int beautySum(string s) {
        int n = s.length();
        int total =0;
        for(int i =0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j =i;j<n;j++){
                mp[s[j]]++;
        
        int maxf =0;
        int minf=INT_MAX;
        for(auto & it:mp){
            maxf= max(maxf, it.second);
            minf = min(minf, it.second);
        }
        total+=(maxf-minf);
            }
        }
        return total;
    }
};