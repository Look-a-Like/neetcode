#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int findMin(vector<int>& nums){
        int n = nums.size();
        int st = 0;
        int ed = n-1;
        int ans = nums[0];
        while(st<=ed){
            if(nums[st] <= nums[ed]){
                return min(nums[st],ans);
            }
            int mid = st + (ed-st)/2;
            ans = min(ans, nums[mid]);
            if(nums[mid] >= nums[st]){
                st = mid+1;
            }else{
                ed = mid-1;
            }
        }
        return ans;
    }
};

int main(){
    int n;
    cin>> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution s;
    cout<< s.findMin(nums)<<endl;
    return 0;
}