#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int search(vector<int> &nums, int target){
        int n = nums.size();
        int st = 0;
        int ed = n-1;
        while(st <= ed){
            int mid = st + (ed-st)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(target > nums[mid]){
                st = mid+1;
            }
            else{
                ed = mid -1;
            }
        }
        return -1;
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
    int ans = s.search(nums,target);
    cout<<ans<<endl;
    return 0;
}