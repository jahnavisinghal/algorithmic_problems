class Solution {
public:
    int numLiveNeighbors(int idx_i, int idx_j, vector< vector<int> > board) {
        int ans = 0;
        for(int i = idx_i-1; i <= idx_i+1; i++) {
            for(int j = idx_j-1; j <= idx_j+1; j++) {
                if((i == idx_i && j == idx_j)|| i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
                    continue;
                }
                //cout << "\nreached " << i << " " << j;
                if(board[i][j] == 1 || board[i][j] == 2) {
                    ans += 1;
                    //cout << "\nwoho";
                }
            }
        }
        return ans;
    }
    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                int n = numLiveNeighbors(i, j, board );
                //cout << "\nlive neigh: " << n;
                if(board[i][j] == 0) {
                    // dead cell
                    if(n == 3) {
                        board[i][j] = 3;
                    }
                } else {
                    // live cell
                    if(n > 3 || n < 2) {
                        board[i][j] = 2;
                    }
                }
            }
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == 2) {
                    board[i][j] = 0;
                } else if(board[i][j] == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};
