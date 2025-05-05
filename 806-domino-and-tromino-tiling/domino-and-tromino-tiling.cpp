class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long f(int i, bool possible, int n, vector<vector<long long>>& memo) {
        if (i > n) return 0;
        if (i == n) return !possible;

        int possibleIdx = possible ? 1 : 0;
        if (memo[i][possibleIdx] != -1) {
            return memo[i][possibleIdx];
        }

        long long result;
        if (possible) {
            result = (f(i + 1, true, n, memo) + f(i + 1, false, n, memo)) % MOD;
        } else {
            result = ((f(i + 1, false, n, memo) + f(i + 2, false, n, memo)) % MOD + 2 * f(i + 2, true, n, memo)) % MOD;
        }

        memo[i][possibleIdx] = result;
        return result;
    }

    int numTilings(int n) {
        vector<vector<long long>> memo(n + 3, vector<long long>(2, -1));
        return f(0, false, n, memo);
    }
};