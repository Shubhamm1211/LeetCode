class Solution {
public:
    long long solve(int i, int j, vector<int>& robot, vector<vector<int>>& factory, vector<vector<long long>>& dp) {
        if (i < 0) return 0;  
        if (j < 0) return 1e15; 
        
        if (dp[i][j] != -1) return dp[i][j];

        long long minDist = 1e15;  
        long long totalDist = 0;

        minDist = solve(i, j - 1, robot, factory, dp);

        for (int k = 0; k < factory[j][1] && i - k >= 0; ++k) {
            totalDist += abs(robot[i - k] - factory[j][0]);

            if (totalDist >= 1e15) break;
            
            minDist = min(minDist, totalDist + solve(i - k - 1, j - 1, robot, factory, dp));
        }

        dp[i][j] = minDist;
        return dp[i][j];
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int m = robot.size();
        int n = factory.size();
        
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<vector<long long>> dp(m, vector<long long>(n, -1));

        return solve(m - 1, n - 1, robot, factory, dp);
    }
};