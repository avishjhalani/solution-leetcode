class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, set<int>> mp;
        for (auto reserve : reservedSeats) {
            int row = reserve[0];
            int col = reserve[1];
            mp[row].insert(col);
        }
        int result = 0;
        result += (n - mp.size()) * 2;
        for (auto &[row,book]:mp) {
            auto isAvailable=[&](int sear){
                return book.find(sear)==book.end();
            };
            bool GroupA = isAvailable(2) && isAvailable(3) && isAvailable(4) &&
                          isAvailable(5);
            bool GroupB = isAvailable(4) && isAvailable(5) && isAvailable(6) &&
                          isAvailable(7);
            bool GroupC = isAvailable(6) && isAvailable(7) && isAvailable(8) &&
                          isAvailable(9);
            
            if (GroupA && GroupC){
                result +=2;
            }
            else if(GroupA || GroupC || GroupB){
                result +=1;
            }
        }
        return result;
        
    }
};