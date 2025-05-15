#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int cmp = target - nums[i];
            if (mp.find(cmp) != mp.end())
            {
                return {mp[cmp], i};
            }
            mp[nums[i]] = i;
        }
    }
};

int main()
{
    vector<int> nums;
    int inp = 0;
    while (inp != -1)
    {
        cin >> inp;
        if (inp != -1)
        {
            nums.push_back(inp);
        }
    }
    int target;
    cin >> target;

    Solution obj;
    vector<int> ans = obj.twoSum(nums, target);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}