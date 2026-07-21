class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<int> zero;
        int ans = 0;

        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int st = i;
                while (i < n && s[i] == '0')
                    i++;
                zero.push_back(i - st);
            } else {
                ans++;
                i++;
            }
        }

        int temp = 0;
        for (int i = 1; i < zero.size(); i++) {
            temp = max(temp, zero[i] + zero[i - 1]);
        }

        return ans + temp;
    }
};