class Solution {
public:

    bool rabin(string &text, string &pattern) {
    long long base = 256;
    long long MOD = 1e9 + 7;

    int n = text.size();
    int m = pattern.size();

    if (m > n) return false;

    long long hashP = 0, hashT = 0, power = 1;

    for (int i = 0; i < m - 1; i++) {
        power = (power * base) % MOD;
    }

    for (int i = 0; i < m; i++) {
        hashP = (hashP * base + pattern[i]) % MOD;
        hashT = (hashT * base + text[i]) % MOD;
    }

    for (int i = 0; i <= n - m; i++) {
        if (hashP == hashT && text.substr(i, m) == pattern) {
            return true;
        }
        if (i < n - m) {
            hashT = (hashT - text[i] * power) % MOD;
            hashT = (hashT + MOD) % MOD; // avoid negative
            hashT = (hashT * base + text[i + m]) % MOD;
        }
    }
    return false;
}

    int repeatedStringMatch(string a, string b) {
        string temp =a;
        int count=1;
        while(temp.size()<b.size()){
            temp+=a;
            count++;
        }
        if (rabin(temp,b)) return count;
        temp+=a;
        if(rabin(temp,b))return count+1;
        return -1;
    }
};