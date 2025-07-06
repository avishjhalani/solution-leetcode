class Solution {
public:

    string gcdOfStrings(string str1, string str2) {
        string ans ="";
        if(str1+str2!=str2+str1) return ans;
        int gcdlen = gcd(str1.size(),str2.size());
        return str1.substr(0,gcdlen);
    }
private:
 int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};