class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        for (int i = 1; i < n; i++) stones[i] += stones[i - 1];

        int a = stones[n - 1];
        for (int i = n - 2; i; i--) a = max(a, stones[i] - a);
        return a;
        
    }
};