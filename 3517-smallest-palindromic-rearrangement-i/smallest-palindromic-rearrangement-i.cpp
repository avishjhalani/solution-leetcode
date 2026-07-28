class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int>cnt(26,0);
        for(char c:s){
            cnt[c-'a']++;
        }
        string left ="";
        string mid ="";
        for(int i =0;i<26;i++){
            if(cnt[i]%2==1){
                mid = char(i+'a');
            }
            left += string(cnt[i] / 2, char(i + 'a'));
        }
         string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};