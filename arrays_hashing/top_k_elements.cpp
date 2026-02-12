#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution{
public:
    vector<int>  topKFrequent(vector<int>& nums, int k){
        //count occurrences
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        //implement a max heap
        priority_queue<pair<int,int>> pq;

        for(auto it: mp){
            pq.push({it.second,it.first});
        }

        vector<int> ans;

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }   
};

int main(){
    int n;
    cin>>n;
    vector<int> inp(n);
    for(int i=0;i<n;i++){
        cin>> inp[i];
    }
    int k;
    cin>>k;
    Solution s;
    vector<int> ans = s.topKFrequent(inp,k);
    for(int i=0;i<k;i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}