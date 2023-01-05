// Explanation - store in set for finding prefix is exist or not after that sort and traverse from last

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    static bool myCmp(string &a, string &b)
    {
        if (a.length() != b.length())
        {
            return a.length() < b.length();
        }
        return a > b;
    }
    string longestString(vector<string> &words)
    {
        int n = words.size();
        unordered_set<string> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(words[i]);
        }
        sort(words.begin(), words.end(), myCmp);
        for (int i = n - 1; i >= 0; i--)
        {
            string text = "";
            bool flag = true;
            for (int j = 0; j < words[i].size(); j++)
            {
                text += words[i][j];
                if (s.find(text) == s.end())
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return words[i];
            }
        }
        return "";
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends