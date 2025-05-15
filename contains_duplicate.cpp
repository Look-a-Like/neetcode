#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool hasDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            if (mp[nums[i]] > 1)
            {
                return true;
            }
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
    Solution obj;
    bool ans = obj.hasDuplicate(nums);
    cout << ans << endl;
}