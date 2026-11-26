class Solution {
public:
    bool canAliceWin(int n) {
        int turn = 0;

        for (int i = 10; i >= 1; i--) {
            if (n < i) {
                return turn % 2 == 1;
            }

            n -= i;
            turn++;
        }

        return turn % 2 == 1;
    }
};