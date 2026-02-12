#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    vector<int> productExceptSelf(vector<int> &nums){
        int z = 0;
        int n = nums.size();
        int p = 1;
        int pos =0;
        for(int i=0;i<n;i++){
            if(z==2){
                break;
            }
            if(nums[i]==0){
                z++;
                pos = i;
            }else{
                p *= nums[i];
            }
        }
        vector<int> ans(n,0);
        if(z==2){
            return ans;
        }
        else if(z==1){
            ans[pos] = p;
            return ans;
        }
        for(int i=0;i<n;i++){
            ans[i] = p/nums[i];
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution s;
    vector<int> ans = s.productExceptSelf(nums);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}