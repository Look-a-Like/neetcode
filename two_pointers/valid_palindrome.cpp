#include<iostream>

using namespace std;

class Solution{
public:
    bool isPalindrome(string s){
        int n = s.size();
        string str;
        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
                str += tolower(s[i]);
            }
        }
        n = str.size();
        int start = 0;
        int end = n-1;
        while(start < end){
            if(str[start]!=str[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};

int main(){
    string str;
    cin>>str;
    Solution s;
    bool ans = s.isPalindrome(str);
    cout<<ans<<endl;
    return 0;
}