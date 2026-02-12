#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<int, int> mp1;
        for (int i = 0; i < s.size(); i++)
        {
            mp1[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            mp1[t[i] - 'a']--;
            if (mp1[t[i] - 'a'] < 0)
            {
                return false;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (mp1[i] > 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string inp1, inp2;
    cin >> inp1 >> inp2;
    Solution obj;
    bool ans = obj.isAnagram(inp1, inp2);
    cout << ans << endl;
}