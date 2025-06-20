class Solution {
public:
    string convertToTitle(int col) {
        string s;
       while(col>0){
        char i =((col-1)%26+65);
        col =((col-1)/26);
        s =i+s;
       }
       return s;
    }
};