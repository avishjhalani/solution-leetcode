class Solution {
public:
typedef pair<int, pair<int, int>> p;
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();
        
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<p, vector<p>, greater<p>> pq;
        
        result[0][0] = 0;
        pq.push({0, {0, 0}});
        
        while (!pq.empty()) {
            int curTime = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            
            if (i == m - 1 && j == n - 1) {
                return curTime;
            }
            
            for (auto &it : direction) {
                int x = i + it[0];
                int y = j + it[1];
                
                if (x >= 0 && y >= 0 && x < m && y < n) {
                    int wait = max(0, moveTime[x][y] - curTime);
                    int arrTime = curTime + wait + 1;
                    
                    if (result[x][y] > arrTime) {
                        result[x][y] = arrTime;
                        pq.push({arrTime, {x, y}});
                    }
                }
            }
        }
        
        return -1;
    }
};