#include<iostream>
#include<vector>
using namespace std;
#define N 9

bool isSafe(vector<vector<char>>& board, int row, int col, char dig){
    
    for(int i=0; i<9; i++){
        if(board[row][i] == dig){
            return false;
        }
    }

    
    for(int j=0; j<9; j++){
        if(board[j][col] == dig){
            return false;
        }
    }

    
    int sr = (row/3)*3, sc = (col/3)*3;
    for(int i=sr; i <= sr + 2; i++){
        for(int j= sc; j<= sc+2; j++){
            if(board[i][j] == dig){
                return false;
            }
        }
    }
    return true;
}

bool solve(vector<vector<char>>& board, int row, int col){

    if(row == 9){
        return true;
    }
    int nextRow = row, nextCol = col + 1;
    if(nextCol == 9){
        nextRow = row + 1;
        nextCol = 0;
    }

    if(board[row][col] != '.'){
        return solve(board, nextRow, nextCol);
    }

    for(char dig = '1'; dig <= '9'; dig++){
        if(isSafe(board, row, col, dig)){
            board[row][col] = dig;
            if(solve(board, nextRow ,nextCol)) {
                return true;
            }
            board[row][col] = '.';
        }
    }

    return false;

}

void sudokuSolver(vector<vector<char>>& board){
    solve(board, 0, 0);
}

void printBoard(vector<vector<char>>& grid){
    
    for(int i=0; i< grid.size(); i++){
        for(int j=0; j< grid[0].size(); j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
vector<vector<char>> board = {
        {'9','.','.','8','4','1','3','.','.'},
        {'.','.','1','9','.','.','4','2','.'},
        {'.','.','.','2','.','.','.','1','.'},
        {'8','7','.','1','.','.','5','4','.'},
        {'1','5','.','3','6','.','.','.','2'},
        {'2','.','.','.','.','.','7','6','.'},
        {'7','2','.','.','.','5','1','9','.'},
        {'6','3','.','.','.','.','2','.','7'},
        {'.','1','5','7','.','2','.','.','8'}
    };
    cout<<"\nThe current state of the board is: "<<endl;
    printBoard(board);

    sudokuSolver(board);
    cout<<"\nAfter solving the sudoku"<<endl;
    printBoard(board);
    return 0;
}