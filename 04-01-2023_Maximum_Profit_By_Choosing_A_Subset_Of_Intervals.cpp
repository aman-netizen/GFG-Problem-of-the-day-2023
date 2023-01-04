// Explanation : first sort according to starting point then on each position check for their right maximun profit (loop start from n-1 to 0)

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int maximum_profit(int n, vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<int> maxx(n);
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int start = intervals[i][0];
            int prev = intervals[i][1];
            maxx[i] = intervals[i][2];
            for (int j = i + 1; j < n; j++)
            {
                if (intervals[j][0] >= prev)
                {
                    // important condition
                    if (maxx[i] < maxx[j] + intervals[i][2])
                    {
                        maxx[i] = intervals[i][2] + maxx[j];
                    }
                }
            }
            ans = max(ans, maxx[i]);
        }
        return ans;
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
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++)
        {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends