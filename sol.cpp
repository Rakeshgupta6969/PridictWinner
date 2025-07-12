class Solution {
public:
    long long int solve(int i, int j, vector<int>& nums, int player, vector<vector<vector<int>>> &dp){
        if(i==j){
            if(!player){
                return nums[i];
            }
            else{
                return -nums[i];
            }
        }
        if(dp[i][j][player]!=-1e7){
            return dp[i][j][player];
        }
        if(!player){
            return dp[i][j][player]=max(nums[i]+solve(i+1, j, nums, 1, dp), nums[j]+solve(i, j-1, nums, 1, dp));
        }
        else{
            return dp[i][j][player]=min(-nums[i]+solve(i+1, j, nums, 0, dp), -nums[j]+solve(i, j-1, nums, 0, dp));
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, -1e7)));

        long long int score=solve(0, n-1, nums, 0, dp);
        return score>=0;
    }
};
