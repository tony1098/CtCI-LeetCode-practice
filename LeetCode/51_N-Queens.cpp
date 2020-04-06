#include <vector>
#include <string>
#include <set>
#include <iostream>

bool possibleConfig(std::vector<int>& cur_sol, int row, int col, int n)
{
    // check col
    for(int r = 0; r < row; r++)
        if(cur_sol[r] == col)
            return false;
    // check diagonal
    for(int r = 0; r < cur_sol.size(); r++)
    {
        if(abs(col - cur_sol[r]) == row - r)
            return false;
    }
    return true;
}

void solve(std::vector<int> &cur_sol, int row, int n, std::vector< std::vector<int> >& sols)
{
    if(row == n)
    {
        sols.push_back(cur_sol);
        return;
    }
    for(int col = 0; col < n; col++)
    {
        if(possibleConfig(cur_sol, row, col, n))
        {
            cur_sol.push_back(col); // for row cur_sol.size()
            solve(cur_sol, row + 1, n, sols);
            cur_sol.pop_back();
        }
    }
}

std::vector< std::vector<std::string> > solveNQueens(int n) { 
    std::vector< std::vector<int> > sols; 
    std::vector<int> cur_sol;
    solve(cur_sol, 0, n, sols);
    std::vector< std::vector<std::string> > graphical_sols;
    for(auto sol : sols)
    {
        std::vector<std::string> chess_board;
        for(auto pos : sol)
        {
            std::string s;
            s.reserve(n);
            for(int i = 0; i < pos; i++)
                s += ".";
            s += "Q";
            for(int i = 0; i < n - pos - 1; i++)
                s += ".";
            chess_board.push_back(s);
        }
        graphical_sols.push_back(chess_board);
    }
    return graphical_sols;
}

int main()
{
    std::cout << solveNQueens(4);
}
