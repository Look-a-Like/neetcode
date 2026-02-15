#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution{
public:
    int minEatingSpeed(vector<int>& piles, int h){
        int n = piles.size();
        int st = 1;
        int ed = *max_element(piles.begin(),piles.end());
        int ans = 0;
        while(st <= ed){
            int mid = st + (ed-st)/2;
            double hrs = 0;
            for(int i=0;i<n;i++){
                hrs += (piles[i]+mid-1)/mid;
            }
            if(hrs <= h){
                ans = mid;
                ed = mid -1;
            }else{
                st = mid +1;
            }
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> piles(n);
    for(int i=0;i<n;i++){
        cin>>piles[i];
    }
    int h;
    cin>>h;
    Solution s;
    cout<<s.minEatingSpeed(piles,h)<<endl;
    return 0;
}