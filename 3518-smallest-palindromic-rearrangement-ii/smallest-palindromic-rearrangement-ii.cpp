class Solution {
public:
    long long nCr(int n,int r,int k){
        r = min(r,n-r);
        long long result = 1;

        for(int i = 1; i <= r; i++){
            result = result * (n-r+i) / i;
            if(result >= k)
                return k;
        }
        return result;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.size();

        char mid = ' ';
        if(n % 2)
            mid = s[n/2];

        vector<int> freq(26,0);

        for(int i = 0; i < n; i++){
            if(n % 2 && i == n/2) continue;
            freq[s[i]-'a']++;
        }

        for(int i = 0; i < 26; i++)
            freq[i] /= 2;

        string left = "";
        int leftLen = n/2;

        for(int i = 0; i < leftLen; i++){

            bool placed = false;

            for(int j = 0; j < 26; j++){

                if(freq[j] > 0){

                    freq[j]--;

                    long long ways = 1;
                    int letter = 0;

                    for(int o = 0; o < 26; o++)
                        letter += freq[o];

                    for(int c = 0; c < 26; c++){
                        if(freq[c] > 0){
                            ways *= nCr(letter, freq[c], k);
                            if(ways >= k){
                                ways = k;
                                break;
                            }
                            letter -= freq[c];
                        }
                    }

                    if(ways >= k){
                        left.push_back(j + 'a');
                        placed = true;
                        break;
                    }

                    freq[j]++;
                    k -= ways;
                }
            }

            if(!placed)
                return "";
        }

        string right = left;
        reverse(right.begin(), right.end());

        if(mid != ' ')
            left.push_back(mid);

        return left + right;
    }
};