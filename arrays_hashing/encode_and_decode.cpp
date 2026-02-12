#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    string encode(vector<string> &strs){
        string ans;
        int n = strs.size();
        for(string s: strs){
            ans += to_string(s.size()) + "#" + s;
        }
        return ans;
    }

    vector<string> decode(string s){
        int n = s.size();
        vector<string> ans;
        int i=0;
        while(i<n){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            string word = s.substr(j+1, len);
            ans.push_back(word);
            i= j+1+len;
        }
        return ans;
    }
};

int main(){

}
