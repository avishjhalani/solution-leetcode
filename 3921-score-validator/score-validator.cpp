class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int>ans;
        int n = events.size();
        int score =0;
        int counter =0;
        for(int i =0;i<n;i++){
            if(events[i]=="0"){
            score+=0;
            }
        if(events[i]=="1"){
            score+=1;
        }
        if(events[i]=="2"){
            score+=2;
        }
        if(events[i]=="3"){
            score+=3;
        }
        if(events[i]=="4"){
            score+=4;
        }
        if(events[i]=="5"){
            score+=5;
        }
        if(events[i]=="6"){
            score+=6;
        }
        if(events[i]=="W"){
            counter+=1;
        }
            if(events[i]=="WD" || events[i]=="NB"){
            score+=1;
        }
        if(counter == 10){
            break;
        }
        }
    ans.push_back(score);
    ans.push_back(counter);
    return ans;
    }
};