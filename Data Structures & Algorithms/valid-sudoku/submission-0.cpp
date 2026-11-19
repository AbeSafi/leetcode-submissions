class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> currentNine;
        currentNine.reserve(9);

        // Check all rows for dupes
        for (const auto& row : board) {
            for (char num : row) {
                if (num == '.') continue;
                if (!currentNine.insert(num).second) return false;
            }
            currentNine.clear();
        }

        // Check all columns for dupes
        for (int col = 0; col < board[0].size(); ++col) {
            for (int row = 0; row < board.size(); ++row) {
                char num = board[row][col];
                if (num == '.') continue;
                if (!currentNine.insert(num).second) return false;
            }
            currentNine.clear();
        }

        int row = 0;
        int col = 0;
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                for (int r = 0; r < 3; ++r) {
                    for (int c = 0; c < 3; ++c) {
                        char num = board[row+r][col+c];
                        if (num == '.') continue;
                        if (!currentNine.insert(num).second) return false;
                    }
                }
                currentNine.clear();
            }
        }

        return true;
    }
};
