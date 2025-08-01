class Solution
{
public:
    int fib(int n)
    {
        if (n == 0 || n == 1)
            return n;

        int prev_prev = 0, prev = 1;
        int ans = 0;
        for (int i = 2; i <= n; i++)
        {
            ans = prev + prev_prev;
            prev_prev = prev;
            prev = ans;
        }
        return ans;
    }
};