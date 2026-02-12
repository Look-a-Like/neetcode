#include<iostream>
#include<stack>

using namespace std;

class Solution{
public:
    bool isValid(string s){
        stack<char> stk;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                stk.push(')');
            }else if(s[i]=='['){
                stk.push(']');
            }else if(s[i]=='{'){
                stk.push('}');
            }else{
                if(stk.empty() || stk.top()!= s[i]){
                    return false;
                }
                stk.pop();
            }
        }
        if(stk.empty()){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    string inp;
    cin>>inp;
    Solution s;
    cout<< s.isValid(inp)<<endl;
    return 0;
}