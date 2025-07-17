class Solution {
public:
    int compress(vector<char>& chars) {
        int ch,count,idx=0,n=chars.size();
        for(int i=0;i<n;i++){
            ch=chars[i];
            count=0;
            while(i<n&&chars[i]==ch){
                count++;
                i++;
            }
            if(count==1){
                chars[idx++]=ch;
            }
            else{
                chars[idx++]=ch;
                string str = to_string(count);
                for(char dig:str){
                    chars[idx++]=dig;
                }
            }
            i--;
        }
        chars.resize(idx);
        return idx;
    }
};