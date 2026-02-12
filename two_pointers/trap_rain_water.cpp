#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
        int trap(vector<int> &nums){
            int n = nums.size();
            if(n==0 || n==1){
                return 0;
            }
            vector<int> preffixMap(n), suffixMap(n);
            preffixMap[0] = nums[0];
            suffixMap[n-1] = nums[n-1];
            for(int i=1;i<n;i++){
                preffixMap[i] = max(preffixMap[i-1], nums[i]);
            }
            for(int i = n-2;i>0;i--){
                suffixMap[i] = max(suffixMap[i+1], nums[i]);
            }
            int ans = 0;
            for(int i=1;i<n-1;i++){
                if(nums[i] < preffixMap[i] && nums[i]<suffixMap[i]){
                    ans += min(preffixMap[i], suffixMap[i]) - nums[i];
                }
            }
            return ans;
        }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution s;
    int ans = s.trap(nums);
    cout<<ans<<endl;
    return 0;
}