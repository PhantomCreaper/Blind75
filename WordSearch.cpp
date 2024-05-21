// 79. Word Search
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(existHelp(board, word, i, j, 0)){
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool existHelp(vector<vector<char>>& board, string word, int x, int y, int index){
        if(index == word.size()){
            return true;
        }
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y]!=word[index]){
            return false;
        }

        char temp = board[x][y];
        board[x][y] = '.';

        bool found = existHelp(board, word, x+1, y, index+1) ||
                     existHelp(board, word, x-1, y, index+1) ||
                     existHelp(board, word, x, y+1, index+1) ||
                     existHelp(board, word, x, y-1, index+1);

        board[x][y] = temp;
        return found;
    }
};
