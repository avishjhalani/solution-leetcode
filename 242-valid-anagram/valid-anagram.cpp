// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         sort(begin(s),end(s));
//         sort(begin(t),end(t));
//         return s==t;
//     }
// };

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> map;

        for (auto c: s) {
            map[c]++;
        }

        for (auto c: t) {
            if (map[c] <= 0) return false;
            map[c]--;
        }



        return true;
    }
};