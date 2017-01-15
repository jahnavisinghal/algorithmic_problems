class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(!nums.size()) {
            return false;
        }
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if(sum%2) {
            return false;
        }
        //cout << "\nsum: " << sum;
        vector< vector<bool> > opt (nums.size()+1, vector<bool> (sum/2+1, false));
        for(int i = 1; i <= nums.size(); i++) {
            for(int j = 1; j <= sum/2; j++) {
                if(nums[i-1] > j) {
                    opt[i][j] = opt[i-1][j];
                } else if(nums[i-1] == j) {
                    opt[i][j] = true;
                } else {
                    opt[i][j] = opt[i-1][j] || opt[i-1][j-nums[i-1]];
                }
            }
        }
        return opt[nums.size()][sum/2];
    }
};
