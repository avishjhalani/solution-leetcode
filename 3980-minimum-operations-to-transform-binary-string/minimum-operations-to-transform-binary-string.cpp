class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        int count =0;
        if(n ==1){
            if(s1 =="1" && s2 =="0") return -1;

            return s1 == s2 ? 0:1;
        }
        int i =0;
        while(i<n){
            if(s1[i] =='0' && s2[i]=='1'){
                count+=1;
                i+=1;
            }
            else if(s1[i]=='1' && s2[i]=='0'){
                int j =i;
                while(j<n && s1[j] == '1' && s2[j]=='0'){
                    j+=1;
                }
                int k =j-i;
                count +=(k/2)+2*(k%2);
                i=j;
            }
            else{
                i+=1;
            }
        }
        return count;
    }
};