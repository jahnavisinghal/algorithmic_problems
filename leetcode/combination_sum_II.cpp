class Solution {
public:
    void combinationHelper(vector<int> &candidates, vector<int> temp, int idx, int target, vector< vector<int> > &ans) {
        int prev = -1;
        for(int i = idx+1; i < candidates.size(); i++) {
            if(prev == candidates[i]) {
                continue;
            }
            if(candidates[i] == target) {
                temp.push_back(candidates[i]);
                ans.push_back(temp);
                temp.pop_back();
            } else if(candidates[i] < target) {
                temp.push_back(candidates[i]);
                combinationHelper(candidates, temp, i, target-candidates[i], ans);
                temp.pop_back();
            }
            prev = candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector< vector<int> > ans;
        if(!candidates.size()) {
            return ans;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        int prev = -1;
        for(int i = 0; i < candidates.size(); i++) {
            if(prev == candidates[i]) {
                continue;
            }
            if(candidates[i] == target) {
                temp.push_back(candidates[i]);
                ans.push_back(temp);
                temp.pop_back();
            } else if(candidates[i] < target) {
                temp.push_back(candidates[i]);
                combinationHelper(candidates, temp, i, target-candidates[i], ans);
                temp.pop_back();
            }
            prev = candidates[i];
        }
        return ans;
    }
};
