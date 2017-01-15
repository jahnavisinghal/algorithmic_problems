class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(!nums.size()) {
            return 1;
        }
        // the missing positive has to be within 1 to n+1
        // convert all negatives to n+2 .. .. 
        int count = nums.size()+2;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]<=0) {
                nums[i] = count++;
            }
        }
        /*
        cout << "\nafter changing negative values";
        for(int i = 0; i < nums.size(); i++) {
            cout << " " << nums[i];
        }*/
        // now all numbers are positive in the array
        for(int i = 0; i < nums.size(); i++) {
            if(abs(nums[i]) <= nums.size() && nums[abs(nums[i])-1] > 0) {
                nums[abs(nums[i])-1] = -1*nums[abs(nums[i])-1];
            }
        }/*
        cout << "\nafter making negative";
        for(int i = 0; i < nums.size(); i++) {
            cout << " " << nums[i];
        }*/
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                return i+1;
            }
        }
        return nums.size()+1;
    }
};
