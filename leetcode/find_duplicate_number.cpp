class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(!nums.size()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == prev) {
                return prev;
            }
            prev = nums[i];
        }
        return -1;
    }
};
