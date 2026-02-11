#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int tgt){
        int n = nums.size();
        int st = 0;
        int ed = n-1;
        while(st<ed){
            int curr = nums[st] + nums[ed];
            if(curr == tgt){
                return {st+1, ed+1};
            }
            else if(curr < tgt){
                st++;
            }
            else{
                ed--;
            }
        }
        return {};
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int target;
    cin>> target;
    Solution s;
    vector<int> ans = s.twoSum(nums,target);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}