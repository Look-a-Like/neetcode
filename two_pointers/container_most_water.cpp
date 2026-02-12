#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int maxArea(vector<int> &nums){
        int n = nums.size();
        int ans = 0;
        int curr = 0;
        int st = 0;
        int ed = n-1;
        while(st < ed){
            curr = min(nums[st],nums[ed])*(ed-st);
            ans = max(ans,curr);
            int start = nums[st];
            int end = nums[ed];
            if(start < end){
                while(nums[st] <= start && st<ed){
                    st++;
                    cout<<"st:"<<st<<" ";
                }
                cout<<endl;
            }else if(end < start){
                while(nums[ed] <= end && st<ed){
                    ed--;
                    cout<<"ed:"<<ed<<" ";
                }
                cout<<endl;
            }else{
                st++;
                ed--;
            }
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
    int ans = s.maxArea(nums);
    cout<<ans<<endl;
    return 0;
}