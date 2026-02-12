#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution{
public:
    int longestConsecutive(vector<int> &nums){
        //unoptimized version
        // if(nums.empty()){
        //     return 0;
        // }
        // int n = nums.size();
        // set<int> st;
        // int ans = 1;
        // for(int i=0;i<n;i++){
        //     st.insert(nums[i]);
        // }
        // int temp = 1;
        // for(auto it: st){
        //     if(st.find(it-1)!= st.end()){
        //         temp++;
        //         ans = max(ans,temp);
        //     }else{
        //         temp = 1;
        //     }
        // }
        // return ans;

        if(nums.empty()){
            return 0;
        }

        unordered_set<int> st(nums.begin(),nums.end());

        int ans = 0;

        for(auto num: st){
            if(st.find(num-1) == st.end()){
                int currNum = num;
                int currStreak = 1;

                while(st.find(currNum + 1)!= st.end()){
                    currNum++;
                    currStreak++;
                }
                ans = max(ans,currStreak);
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
    int ans = s.longestConsecutive(nums);
    cout<<ans<<endl;
    return 0;
}