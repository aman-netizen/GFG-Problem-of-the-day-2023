// Explanation : Simple concept of LIS

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int cIdx(int tail[], int l, int r, int x)
    {
        while (r > l)
        {
            int m = l + (r - l) / 2;
            if (tail[m] >= x)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return r;
    }
    int removeStudents(int H[], int N)
    {
        int tail[N];
        int len = 1;
        tail[0] = H[0];
        for (int i = 1; i < N; i++)
        {
            if (H[i] > tail[len - 1])
            {
                tail[len] = H[i];
                len++;
            }
            else
            {
                int c = cIdx(tail, 0, len - 1, H[i]);
                tail[c] = H[i];
            }
        }
        return N - len;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        int H[N];
        for (int i = 0; i < N; i++)
            cin >> H[i];

        Solution ob;
        cout << ob.removeStudents(H, N) << endl;
    }
    return 0;
}
// } Driver Code Ends