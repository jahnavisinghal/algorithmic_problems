class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
         if(!triangle.size()) {
             return 0;
         }
         vector< vector<int> > dp;
         for(int i = 0; i < triangle.size(); i++) {
             vector<int> temp;
             for(int j = 0; j < triangle[i].size(); j++) {
                 temp.push_back(0);
             }
             dp.push_back(temp);
         }
         dp[0][0] = triangle[0][0];
         int minFinal = dp[0][0];
         for(int i = 1; i < triangle.size(); i++) {
             for(int j = 0; j < triangle[i].size(); j++) {
                 int sum = triangle[i][j];
                 // this element chosen, so select the min path till i-1
                 if(!j) {
                     sum += dp[i-1][0];
                 } else if(j == triangle[i].size()-1) {
                     sum += dp[i-1][j-1];
                 } else {
                     sum += min(dp[i-1][j-1], dp[i-1][j]);
                 }
                 dp[i][j] = sum;
                 if(!j) {
                     minFinal = sum;
                 } else if(minFinal > sum) {
                     minFinal = sum;
                 }
             }
         }
         return minFinal;
    }
};
