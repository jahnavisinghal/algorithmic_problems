class Solution {
public:
    int findMin(vector<int>& nums) {
        if(!nums.size()) {
            return 0;
        }
        int st = 0;
        int en = nums.size()-1;
        while(st <= en) {
            if(st == en) {
                return nums[st];
            }
            int mid = (st+en)/2;
            if(nums[mid] >= nums[st]) {
                if(nums[mid] < nums[en]) {
                    en = mid-1;
                    if(en < st) {
                        return nums[mid];
                    }
                } else {
                    st = mid+1;
                }
            } else {
                if(nums[mid] > nums[mid-1]) {
                    en = mid-1;
                } else {
                    return nums[mid];
                }
            }
        }
        return -1;
    }
};
