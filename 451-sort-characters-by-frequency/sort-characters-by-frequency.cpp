// class Solution {
// public:
// typedef pair<char,int>p;
//     string frequencySort(string s) {
//         vector<p>vec(123);
//         for(char &ch :s){
//             int freq = vec[ch].second;
//             vec[ch] = {ch ,freq+1};
//         }
//         auto lambda = [&](p &p1,p &p2){
//             return p1.second>p2.second;
//         };
//         sort(vec.begin(),vec.end());
//         string res ="";
//         for(int i=0;i<=122;i++){
//             if(vec[i].second>0){
//                 char ch =vec[i].first;
//                 int freq =vec[i].second;
//                 string temp =string(freq,ch);
//                 res +=temp;
//             }
//         }
// return res;
//     }
// };




// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char,int> mp;
//         multimap<int,char> r;
//         string ss="";

//         for(auto a : s)
//             mp[a]++;

//         for(auto a : mp)
//             r.insert({a.second, a.first});

//         for(auto it = r.rbegin(); it != r.rend(); ++it)
//             ss += string(it->first, it->second);

//         //for(auto it = r.rbegin(); it != r.rend(); ++it){
//         //   for (int i = 0; i < it->first; ++i) {
//         //          ss += it->second;
//         //        }
//         //} 

//         return ss;
//     }
// };

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(char ch : s) m[ch]++;

        vector<pair<int, char>> v;

        for(auto e : m)
            v.push_back({e.second, e.first});
            sort(v.rbegin(), v.rend());

            string ans = "";

            for(auto e : v){
                int f = e.first;
                char ch = e.second;

                while(f--)
                    ans += ch;

          }
          return ans;
    }
};



