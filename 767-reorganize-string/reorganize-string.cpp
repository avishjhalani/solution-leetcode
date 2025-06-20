class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> mp;

        for (char ch : s) {
            mp[ch]++;
        }

        // Find the character with max frequency
        int maxf = 0;
        char maxch;
        for (auto &p : mp) {
            if (p.second > maxf) {
                maxf = p.second;
                maxch = p.first;
            }
        }

        // If the max frequency is more than (n+1)/2, it's impossible
        if (maxf > (n + 1) / 2) return "";

        // Start placing max frequent char at even indices first
        string res(n, ' ');
        int i = 0;

        while (mp[maxch] > 0) {
            res[i] = maxch;
            mp[maxch]--;
            i += 2;
        }

        
        for (auto &p : mp) {
            char ch = p.first;
            int freq = p.second;

            while (freq > 0) {
                if (i >= n) i = 1; 
                res[i] = ch;
                i += 2;
                freq--;
            }
        }

        return res;
    }
};
