class Solution {
public:
    vector<string> letterCombHelper(string digits, map<int,string> &map1) {
        //cout << "\nthis is for " << digits;
        vector<string> ans;
        int numDigits = digits.size();
        //cout << "\nok " << numDigits << " " << digits[0] << " " << map1[(int)digits[0]-48];
        string st = map1[(int)digits[0]-48];
        if(numDigits == 1) {
             for(int i = 0; i < st.size(); i++) {
                 //cout << "\nsee " << st[i];
                 ans.push_back(st.substr(i,1));
             }
             return ans;
        }
        vector<string> temp = letterCombHelper(digits.substr(1, numDigits-1), map1);
        //cout << "\nwe got in temp!";
        /*for(int i = 0; i < temp.size(); i++) {
            cout << " " << temp[i];
        }*/
        for(int i = 0; i < st.size(); i++) {
            for(int j = 0; j < temp.size(); j++) {
                ans.push_back(st.substr(i,1)+temp[j]);
            }
        }
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(!digits.size()) {
            return ans;
        }
        std::map<int, string> map1;
        map1[2] = "abc";
        map1[3] = "def";
        map1[4] = "ghi";
        map1[5] = "jkl";
        map1[6] = "mno";
        map1[7] = "pqrs";
        map1[8] = "tuv";
        map1[9] = "wxyz";
        ans = letterCombHelper(digits, map1);
        return ans;
    }
};
