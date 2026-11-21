class Solution {
    unordered_set<char*> inUseCells;

    bool cellFree(vector<vector<char>>& board, int r, int c) {
        return !inUseCells.contains(&board[r][c]);
    }

    bool findWord(vector<vector<char>>& board, string& word, int r, int c, int index) {
        inUseCells.insert(&board[r][c]);

        if (tolower(word[index]) != tolower(board[r][c])) {
            inUseCells.erase(&board[r][c]);
            return false;
        }
        if (index >= word.size() - 1) return true;

        bool foundWord = false;

        if (r-1 >= 0 && cellFree(board, r-1,c)) foundWord = findWord(board, word, r-1, c, index+1);
        if (foundWord) return foundWord;

        if (r+1 < board.size() && cellFree(board, r+1,c)) foundWord = findWord(board, word, r+1, c, index+1);
        if (foundWord) return foundWord;

        if (c-1 >= 0 && cellFree(board, r,c-1)) foundWord = findWord(board, word, r, c-1, index+1);
        if (foundWord) return foundWord;
        
        if (c+1 < board[r].size() && cellFree(board, r,c+1)) foundWord = findWord(board, word, r, c+1, index+1);
        if (foundWord) return foundWord;

        inUseCells.erase(&board[r][c]);
        return false;
    }

public:
    // Constraints say there will never be an empty input, no guard needed then
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); j++) {
                if (findWord(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }
};
