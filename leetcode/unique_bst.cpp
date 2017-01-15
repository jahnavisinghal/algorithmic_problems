ass Solution {
public:
    int numTrees(int n) {
        if(!n) {
            return 0;
        }
        vector<int> opt;
        
        for(int i = 0; i <= n; i++) {
            opt.push_back(1);
        }
        for(int i = 2; i <= n; i++) {
            opt[i] = 0;
            for(int j = 1; j <= i; j++) {
                opt[i] += opt[j-1]*opt[i-j]; 
            }
        }
        return opt[n];
    }
};
