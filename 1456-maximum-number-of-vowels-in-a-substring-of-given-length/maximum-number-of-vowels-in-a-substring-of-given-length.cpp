// class Solution {
// public:
//     int maxVowels(string s, int k) {
//         int n = s.size();
//         int i =0,j=0;
//         int maxvol =0;
//         int count =0;
//         while(j<n){
//             if(isVowel(s[j])){
//                 count++;
//             }
//             if(j-i+1== k){
//                 maxvol = max(maxvol,count);
//                 if(isVowel(s[i])){
//                     count--;
//                 }
//                 i++;
//             }
//             j++;
//         }
//         return maxvol;
//     }
//     private:
//     bool isVowel(char &ch){
//         return ch =='a'||ch =='e'||ch =='i'||ch =='o'||ch =='u';
//     }
// };
class Solution {
public:
    int maxVowels(string s, int k) {
        int maxcount=INT_MIN;
        int windowcount=0;
        int start=0;
        for(int end=0;end<s.size();end++){
            if(s[end]=='a' || s[end]=='e'|| s[end]=='i'||s[end]=='o'||s[end]=='u'){
                windowcount+=1;
            }
            if(end>=k-1){
                maxcount=max(maxcount,windowcount);
                if(s[start]=='a' || s[start]=='e'|| s[start]=='i'||s[start]=='o'||s[start]=='u'){
                    windowcount-=1;
                    start++;
            }else{
                start++;
            }
            }
        }
        return maxcount;
        
    }
};