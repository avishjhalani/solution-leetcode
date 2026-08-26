class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int count1 = 0;
        int left = 0;

        string ans = "";

        for (int right = 0; right < n; right++) {

            // Add current element
            if (s[right] == '1')
                count1++;

            // We only need windows containing exactly k ones
            while (count1 > k) {
                if (s[left] == '1')
                    count1--;

                left++;
            }

            // We have exactly k ones
            if (count1 == k) {

                // Remove unnecessary leading zeros
                while (left < right && s[left] == '0') {
                    left++;
                }

                string curr = s.substr(left, right - left + 1);

                // Shorter is better.
                // If same length, lexicographically smaller is better.
                if (ans == "" ||
                    curr.size() < ans.size() ||
                    (curr.size() == ans.size() && curr < ans)) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};