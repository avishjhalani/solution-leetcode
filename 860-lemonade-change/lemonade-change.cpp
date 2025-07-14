class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int a =0;
        int b=0;
        int c=0;
        for(int i =0;i<n;i++){
            if(bills[i]==5){
                a=a+1;
            }
            else if(bills[i]==10){
                if(a){
                    a=a-1;
                    b=b+1;
                }
               else return false;
            }
            else {
                if(a && b){
                    b=b-1;
                    a=a-1;
                }
                else{
                    if(a>=3){
                        a=a-3;
                    }
                    else  return false;
                }
                  
            }
        }
        return true;
    }
};