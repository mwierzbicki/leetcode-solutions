// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
//
//
// A partially filled sudoku which is valid.
//
//
// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
//


class Solution {
public:
    unordered_map<char,bool> ij,ji;
    bool isValidSudoku(vector<vector<char>>& board) {
        bool fail=0;
        for (int i=0; i<9; i++) {
            ij.clear(); ji.clear();
            for (int j=0; j<9; j++) {
                if(check(i,j,board)) {
                    return false;
                }
            }
        }
        for (int i=0; i<=6; i+=3) {
            for (int j=0; j<=6; j+=3) {
                ij.clear(); ji.clear();
                for (int k=0; k<3; k++) {
                    for (int l=0; l<3; l++) {
                        if(check(i+k,j+l,board)) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    bool check(int i, int j, vector<vector<char>>& board) {
        if ((ij[board[i][j]] && board[i][j]!='.') || (ji[board[j][i]] && board[j][i]!='.')) {
            return true;
        }
        ij[board[i][j]]=true;
        ji[board[j][i]]=true;
        return false;
    }
};
