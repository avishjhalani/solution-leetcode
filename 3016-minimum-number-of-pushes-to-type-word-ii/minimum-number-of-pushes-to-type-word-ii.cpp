class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if(n<=8) return n;
        int result =0;
        vector<int>freq(26,0);
        for(char &ch : word){
            freq[ch-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
        for(int i =0;i<26;i++){
            int temp = freq[i];
            int press = i/8+1;
            result+=press*temp;
        }
        return result;
    }
};