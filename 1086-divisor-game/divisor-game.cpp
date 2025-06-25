
class Solution {
public:
    int dp[1001] = {};
    bool divisorGame(int N) {
        if (dp[N] == 0)
            for (int i = 1; dp[N] != 1 && i <= N / 2; ++i)
                dp[N] = N % i == 0 ? divisorGame(N - i) ? -1 : 1 : -1;
        return dp[N] == 1;
    }
};