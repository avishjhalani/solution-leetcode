// class Solution {
// public:
//     string addStrings(string num1, string num2) {
//        int i =num1.size()-1;
//        int j =num2.size()-1;
//        int carry =0;
//        string result;
//        while(i>=0||j>=0||carry){
//         int ans =carry;
//         if(i>=0){
//             ans+=num1[i--]-'0';
//         }
//         if(j>=0){
//             ans+=num2[j--]-'0';
//         }
//         result+=(ans%10+'0');
//         carry =ans/10;
//        }
//         reverse(result.begin(),result.end());
//        return result;
//     }
// };
class Solution {
 public:
  string addStrings(string num1, string num2) {
    string ans;
    int carry = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0)
        carry += num1[i--] - '0';
      if (j >= 0)
        carry += num2[j--] - '0';
      ans += carry % 10 + '0';
      carry /= 10;
    }

    ranges::reverse(ans);
    return ans;
  }
};

