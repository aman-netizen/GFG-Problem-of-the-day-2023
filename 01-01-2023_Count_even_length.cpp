//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long division(long long x, long long y, long long mod)
    {
        y = y % mod;
        long long ans = 1;
        long long b = mod - 2;
        while (b > 0)
        {
            if (b & 1)
            {
                ans = (ans * y) % mod;
            }
            y = (y * y) % mod;
            b = b >> 1;
        }
        return (x * 1ll * ans) % mod;
    }
    int compute_value(int n)
    {
        long long mod = 1000000007;
        long long ans = 0;
        long long fact[2 * n + 1];
        fact[0] = 1;
        for (long long i = 1; i <= 1ll * 2 * n; i++)
        {
            fact[i] = ((fact[i - 1] % mod) * (i % mod)) % mod;
        }
        ans = division(fact[2 * n], fact[n], mod);
        ans = division(ans, fact[n], mod);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.compute_value(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends