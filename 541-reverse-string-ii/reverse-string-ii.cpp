class Solution {
public:
// void reverse(string &s ,int st , int end){
//     for(int i =st,j=end;i<j;i++,j--){
//         swap(s[i],s[j]);
//     }
// }
    string reverseStr(string s, int k) {
        int n =s.size();
        for(int i =0;i<n;i+=2*k){
            int left =i;
        int right = min(i+k-1,n-1);
        while(left<=right){
            swap(s[left++],s[right--]);
        }
        }
        return s;
        // int n =s.size();
        // for(int i =0;i<n;i+=2*k){
        //     if(i+k<n){
        //         reverse(s,i,i+k-1);
        //     }
        //     else{
        //         reverse(s,i,n-1);
        //     }
        // }
        // return s;
    }
};