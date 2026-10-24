class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        vector<int> months = {31, 28, 31, 30, 31, 30,
                              31, 31, 30, 31, 30, 31};

        int Alice_Arrive_Month = stoi(arriveAlice.substr(0, 2));
        int Alice_Arrive_Day = stoi(arriveAlice.substr(3, 2));

        int Alice_Leave_Month = stoi(leaveAlice.substr(0, 2));
        int Alice_Leave_Day = stoi(leaveAlice.substr(3, 2));

        int Bob_Arrive_Month = stoi(arriveBob.substr(0, 2));
        int Bob_Arrive_Day = stoi(arriveBob.substr(3, 2));

        int Bob_Leave_Month = stoi(leaveBob.substr(0, 2));
        int Bob_Leave_Day = stoi(leaveBob.substr(3, 2));

        int Alice_Arrive_Date = Alice_Arrive_Day;
        for (int i = 0; i < Alice_Arrive_Month - 1; i++)
            Alice_Arrive_Date += months[i];

        int Alice_Leave_Date = Alice_Leave_Day;
        for (int i = 0; i < Alice_Leave_Month - 1; i++)
            Alice_Leave_Date += months[i];

        int Bob_Arrive_Date = Bob_Arrive_Day;
        for (int i = 0; i < Bob_Arrive_Month - 1; i++)
            Bob_Arrive_Date += months[i];

        int Bob_Leave_Date = Bob_Leave_Day;
        for (int i = 0; i < Bob_Leave_Month - 1; i++)
            Bob_Leave_Date += months[i];

        int start = max(Alice_Arrive_Date, Bob_Arrive_Date);
        int end = min(Alice_Leave_Date, Bob_Leave_Date);

        return max(0, end - start + 1);
    }
};