class Solution {
public:
    void combinationHelper(vector<int> &candidates, vector<int> temp, int target, vector< vector<int> > &ans) {
        for(int i = 0; i < candidates.size(); i++) {
            if(candidates[i] < temp[temp.size()-1]) {
                continue;
            }
            if(candidates[i] == target) {
                temp.push_back(candidates[i]);
                ans.push_back(temp);
                temp.pop_back();
            } else if(candidates[i] < target) {
                temp.push_back(candidates[i]);
                combinationHelper(candidates, temp, target-candidates[i], ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector< vector<int> > ans;
        if(!candidates.size()) {
            return ans;
        }
        vector<int> temp;
        for(int i = 0; i < candidates.size(); i++) {
            if(candidates[i] == target) {
                temp.push_back(candidates[i]);
                ans.push_back(temp);
                temp.pop_back();
            } else if(candidates[i] < target) {
                temp.push_back(candidates[i]);
                combinationHelper(candidates, temp, target-candidates[i], ans);
                temp.pop_back();
            }
        }
        return ans;
    }
};
