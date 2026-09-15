
class Solution {
public:

    int n;
    string s;

    int t[2001];
    bool pal[2001][2001];

    int solve(int idx, int k) {

        if (idx >= n)
            return 0;

        if (t[idx] != -1)
            return t[idx];

        // Option 1: skip current character
        int ans = solve(idx + 1, k);

        // Option 2: take a palindrome starting at idx
        for (int i = idx + k - 1; i < n; i++) {

            if (pal[idx][i]) {
                ans = max(ans, 1 + solve(i + 1, k));
            }
        }

        return t[idx] = ans;
    }

    int maxPalindromes(string s, int k) {

        this->s = s;
        n = s.size();

        memset(t, -1, sizeof(t));
        memset(pal, false, sizeof(pal));

        // Precompute palindromes
        for (int i = n - 1; i >= 0; i--) {

            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 2 || pal[i + 1][j - 1])) {

                    pal[i][j] = true;
                }
            }
        }

        return solve(0, k);
    }
};
