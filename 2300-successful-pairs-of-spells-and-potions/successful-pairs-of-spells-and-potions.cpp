// class Solution {
// public:
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         sort(potions.begin(), potions.end()); // Sort potions for binary search
//         vector<int> ans;

//         for (int i = 0; i < spells.size(); ++i) {
//             long long spell = spells[i];
//             int low = 0, high = potions.size() - 1;
//             int pos = potions.size(); // Default to 0 successful pairs

//             // Binary search to find the first potion such that spell * potion >= success
//             while (low <= high) {
//                 int mid = low + (high - low) / 2;
//                 if (spell * 1LL * potions[mid] >= success) {
//                     pos = mid;
//                     high = mid - 1;
//                 } else {
//                     low = mid + 1;
//                 }
//             }

//             ans.push_back(potions.size() - pos);
//         }

//         return ans;
//     }
// };
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> result;

        for (int spell : spells) {
            long long minPotion = (success + spell - 1) / spell; // ceil(success / spell)
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);
            result.push_back(potions.end() - it);
        }

        return result;
    }
};