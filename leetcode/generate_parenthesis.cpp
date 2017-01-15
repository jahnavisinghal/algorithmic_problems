class Solution {
public:
    void generateParenHelper(int left, int right, vector<string> &ans, string str) {
        //cout << "\nsee " << str;
        if(left > right) {
            return;
        }
        if(!left && !right) {
            ans.push_back(str);
            return;
        }
        if(left) {
            generateParenHelper(left-1, right, ans, str+"(");
        }
        if(right) {
            generateParenHelper(left, right-1, ans, str+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(!n) {
            return ans;
        }
        generateParenHelper(n, n, ans, "");
        return ans;
    }
};
