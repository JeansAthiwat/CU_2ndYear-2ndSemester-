#include <bits/stdc++.h>
using namespace std;

const int INF = 2e8;

const vector<vector<int>> goalBoard = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 0}};

const vector<vector<int>> targetPos = {
    {3, 3},
    {0, 0},
    {0, 1},
    {0, 2},
    {0, 3},
    {1, 0},
    {1, 1},
    {1, 2},
    {1, 3},
    {2, 0},
    {2, 1},
    {2, 2},
    {2, 3},
    {3, 0},
    {3, 1},
    {3, 2}};
    
const int UP = 0,
          DOWN = 1,
          LEFT = 2,
          RIGHT = 3;

vector<int> opp_move = {DOWN, UP, RIGHT, LEFT};

class Board
{
public:
    vector<vector<int>> board; // stores the pos of numbers
    vector<int> moves;         // stores the move lists
    int r, c;                  // row and col of 0 (empty space)
    int heuristic_value;

    Board(vector<vector<int>> &startingPos, int emptyR, int emptyC) : r(emptyR), c(emptyC)
    {
        this->board = startingPos;
        moves = vector<int>();
        heuristic_value = 0;
        // heuristic_value = calculate_heuristic(1);
    }

    bool try_move(int direction)
    {
        if (moves.empty() || direction != opp_move[moves.back()])
        {
            if (direction == UP)
            {
                if (r == 0)
                    return false;

                board[r][c] = board[r - 1][c];
                board[r - 1][c] = 0;
                r = r - 1;
            }
            else if (direction == DOWN)
            {
                if (r == 3)
                    return false;

                board[r][c] = board[r + 1][c];
                board[r + 1][c] = 0;
                r = r + 1;
            }
            else if (direction == LEFT)
            {
                if (c == 0)
                    return false;

                board[r][c] = board[r][c - 1];
                board[r][c - 1] = 0;
                c = c - 1;
            }
            else if (direction == RIGHT)
            {
                if (c == 3)
                    return false;

                board[r][c] = board[r][c + 1];
                board[r][c + 1] = 0;
                c = c + 1;
            }
            moves.push_back(direction);
            heuristic_value = calculate_heuristic(1);

            return true;
        }
        else
        {
            return false;
        }
    }

    int calculate_heuristic(int mode = 0)
    {
        // mode 0 : count the misplaced tiles
        if (mode == 0)
        {
            int misplace_count = 0;
            for (int r = 0; r < 4; r++)
                for (int c = 0; c < 4; c++)
                    if (board[r][c] != goalBoard[r][c])
                        misplace_count++;

            return misplace_count + moves.size();
        }
        else
        {
            int total_dist = 0;
            for (int r = 0; r < 4; r++)
            {
                for (int c = 0; c < 4; c++)
                {
                    int distR = abs(r - targetPos[board[r][c]][0]);
                    int distC = abs(c - targetPos[board[r][c]][1]);
                    total_dist += distR + distC;
                }
            }

            return total_dist + moves.size();
        }
    }

    bool operator<(const Board &other) const
    {
        return board < other.board;
    }
};

int bfs_solve(vector<vector<int>> &startingBoard, int startingR, int startingC)
{
    set<Board> recognizedBoard;
    queue<Board> states;
    Board board(startingBoard, startingR, startingC);
    states.push(board);

    while (!states.empty())
    {
        auto b = states.front();
        states.pop();

        if (b.board == goalBoard)
        {
            return b.moves.size();
        }

        for (int d = 0; d < 4; d++)
        {
            auto new_board = b;
            if (new_board.try_move(d))
            {
                if (recognizedBoard.find(new_board) == recognizedBoard.end())
                {
                    states.push(new_board);
                    recognizedBoard.insert(new_board);
                }
            }
        }
    }

    return -1;
}

int main()
{

    vector<vector<int>> tmpBoard(4, vector<int>(4));
    int emptyR, emptyC;
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            cin >> tmpBoard[r][c];
            if (tmpBoard[r][c] == 0)
            {
                emptyR = r;
                emptyC = c;
            }
        }
    }

    int min_moves = bfs_solve(tmpBoard, emptyR, emptyC);

    cout << min_moves;
    return 0;
}