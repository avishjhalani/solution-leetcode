// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         vector<int>b(2,0);
//         int type1 =-1 ,type2=-1,ans=0;
//         for(int i =0;i<fruits.size();i++){
//             if(type1 ==-1 || fruits[i]==-1){
//                 type1=fruits[i];
//                 b[0]++;

//             }
//             else if(type2 ==-1 || fruits[i]==-1){
//                 type2=fruits[i];
//                 b[1]++;
                
//             }
//             else{
//                 ans =max(ans ,b[0]+b[1]);
//                 int prev =i-1;
//                 while(prev>=0&&fruits[prev]==fruits[i-1]) prev--;
//                 type1 =fruits[i-1] ,type2 =fruits[i];
//                 b[0] =i-prev-1;
//                 b[1] =i;

//             }
        
//         }
//         ans =max(ans,b[0]+b[1]);
//         return ans;
//     }
// };

// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         unordered_map<int, int> basket;
//         int left = 0, maxFruits = 0;
        
//         for (int right = 0; right < fruits.size(); ++right) {
//             basket[fruits[right]]++;
//             while (basket.size() > 2) {
//                 basket[fruits[left]]--;
//                 if (basket[fruits[left]] == 0) {
//                     basket.erase(fruits[left]);
//                 }
//                 left++;
//             }

//             maxFruits = max(maxFruits, right - left + 1);
//         }

//         return maxFruits;
//     }
// };

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int count[100001] = {0};  // Assuming fruit values < 100001
        int types = 0;
        int maxLen = 0;
        int left = 0;
        
        for(int right = 0; right < fruits.size(); right++){
            if(count[fruits[right]] == 0) types++;
            count[fruits[right]]++;
            
            while(types > 2){
                count[fruits[left]]--;
                if(count[fruits[left]] == 0) types--;
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};