class Solution {
public:
    string reverseVowels(string s) {
        string res;
        stack<char> vowels;

        for(auto character : s) {
            if(character == 'a' || character == 'A'
                || character == 'e' || character == 'E'
                || character == 'i' || character == 'I'
                || character == 'o' || character == 'O'
                || character == 'u' || character == 'U') 
            {
                vowels.push(character);
            }
        }

        for(auto character : s) {
            if(character == 'a' || character == 'A'
                || character == 'e' || character == 'E'
                || character == 'i' || character == 'I'
                || character == 'o' || character == 'O'
                || character == 'u' || character == 'U') 
            {
                res.push_back(vowels.top());
                vowels.pop();
            }
            else {
                res.push_back(character);
            }
        }

        return res;
    }
};