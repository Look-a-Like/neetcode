#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

//unoptimized solution using maps

// class Solution{
// public:
//     vector<vector<string>> groupAnagrams(vector<string> &strs){
//         vector<unordered_map<int,int>> vmp;
//         vector<vector<string>> ans;
//         int n = strs.size();
//         for(int i=0;i<n;i++){
//             unordered_map<int,int> mp;

//             //frequency map
//             for(int j=0;j<strs[i].size();j++){
//                 mp[strs[i][j]-'a']++;
//             }
//             bool found = false;

//             //compare with existing maps
//             for(int j=0;j<vmp.size();j++){
//                 bool check = true;
//                 for(int k=0;k<26;k++){
//                     if(vmp[j][k] != mp[k]){
//                         check = false;
//                         break;
//                     }
//                 }
//                 if(check){
//                     ans[j].push_back(strs[i]);
//                     found = true;
//                     break;
//                 }
//             }
//             if(!found){
//                 vmp.push_back(mp);
//                 ans.push_back({strs[i]});
//             }
//         }
//         return ans;
//     }
// };

class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string> strs){
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> groups;
        for(string &s: strs){
            vector<int> count(26,0);
            for(char c: s){
                count[c-'a']++;
            }

            string key;
            for(int i=0;i<26;i++){
                key += to_string(count[i]) + "#";
            }

            groups[key].push_back(s);
        }
        for(auto &p: groups){
            ans.push_back(p.second);
        }
        return ans;
    }
};
int main(){
    int n;
    cin>> n;
    vector<string> strs;
    for(int i=0;i<n;i++){
        string inp;
        cin>>inp;
        strs.push_back(inp);
    }
    Solution s;
    vector<vector<string>> ans = s.groupAnagrams(strs);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<< ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}