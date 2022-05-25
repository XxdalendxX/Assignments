#include <iostream>
#include <vector>

/*
You are required to implement the IsValidMove method for an 'Othello' game.
ALL TESTS CASES MUST PASS.

You are required to implement the MakeMove method for an Othello Game
ALL TEST CASES MUST PASS

*/

typedef std::vector<std::vector<char>> OthelloBoardState;

bool IsValidMove(char player, int col, int row, const OthelloBoardState& grid);
OthelloBoardState MakeMove(char player, int col, int row, OthelloBoardState grid);

int main(int argc, char** argv)
{
    OthelloBoardState state1 =
    {//   0    1    2    3    4    5    6    7
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 0
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 1
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 2
        {' ', ' ', ' ', 'W', 'B', ' ', ' ', ' '}, // 3
        {' ', ' ', ' ', 'B', 'W', ' ', ' ', ' '}, // 4
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 5
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 6
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}  // 7
    };

    auto ShouldBe = [](auto result, auto expected) {
        std::cout << (result == expected ? "\033[32m [PASS]" : "\033[31m [FAIL]") << "\033[0m" << std::endl;
    };


    ShouldBe(IsValidMove('B', 5, 4, state1), true);  // true
    MakeMove('B', 5, 4, state1);
    for (int j = 0; j < 8; j++)

    ShouldBe(IsValidMove('B', 2, 4, state1), false); // false
    MakeMove('B', 2, 4, state1);

    ShouldBe(IsValidMove('B', 3, 2, state1), true);  // true
    MakeMove('B', 3, 2, state1);

    ShouldBe(IsValidMove('B', 3, 5, state1), false); // false
    MakeMove('B', 3, 5, state1);

    ShouldBe(IsValidMove('B', 5, 5, state1), false); // false
    MakeMove('B', 5, 5, state1);

    ShouldBe(IsValidMove('W', 5, 4, state1), false); // false
    MakeMove('W', 5, 4, state1);

    ShouldBe(IsValidMove('W', 2, 4, state1), true);  // true
    MakeMove('W', 2, 4, state1);

    ShouldBe(IsValidMove('W', 3, 2, state1), false); // false
    MakeMove('W', 3, 2, state1);

    ShouldBe(IsValidMove('W', 3, 5, state1), true);  // true
    MakeMove('W', 3, 5, state1);

    ShouldBe(IsValidMove('W', 5, 5, state1), false); // false
    MakeMove('W', 5, 5, state1);

    OthelloBoardState state2 =
    {//   0    1    2    3    4    5    6    7
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 0
        {' ', ' ', 'B', ' ', ' ', ' ', ' ', ' '}, // 1
        {' ', ' ', 'B', 'W', ' ', ' ', ' ', ' '}, // 2
        {' ', ' ', 'B', 'W', 'B', ' ', ' ', ' '}, // 3
        {' ', ' ', 'W', 'W', 'W', ' ', ' ', ' '}, // 4
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 5
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 6
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}  // 7
    };

    ShouldBe(IsValidMove('B', 2, 5, state2), true);  // true
    MakeMove('B', 2, 5, state2);

    ShouldBe(IsValidMove('B', 3, 5, state2), false); // false--
    MakeMove('B', 3, 5, state2);

    ShouldBe(IsValidMove('B', 4, 5, state2), true);  // true
    MakeMove('B', 4, 5, state2);

    ShouldBe(IsValidMove('B', 3, 1, state2), false); // false--
    MakeMove('B', 3, 1, state2);

    ShouldBe(IsValidMove('B', 4, 2, state2), true);  // true
    MakeMove('B', 4, 2, state2);

    ShouldBe(IsValidMove('B', 4, 1, state2), true);  // true--
    MakeMove('B', 4, 1, state2);

    ShouldBe(IsValidMove('W', 2, 5, state2), false); // false
    MakeMove('W', 2, 5, state2);

    ShouldBe(IsValidMove('W', 2, 0, state2), true);  // true
    MakeMove('W', 2, 0, state2);

    ShouldBe(IsValidMove('W', 3, 1, state2), false); // false--
    MakeMove('W', 3, 1, state2);


    return 0;
}

bool IsValidMove(char player, int col, int row, const OthelloBoardState& grid)
{
    // Task 1:
    // this method should return true if the 'player'
    // can be placed on the grid at the specified row/col location.

    char opponent;
    
    if (player == 'B')
    {
        opponent = 'W';
    }
    else if (player == 'W')
    {
        opponent = 'B';
    }

    
    //top left
    if (row - 1 > 0 && col - 1 > 0)
    {
        if (grid[row - 1][col - 1] == opponent)
        {
            for (int i = 1; col - i > 0 && row + i > 0; i++)
            {
                if (grid[row - i][col - i] == ' ')
                {
                    continue;
                }
                else if (grid[row - i][col - i] == player)
                {
                    return true;
                }
            }
        }
    }

    //top
    if (row - 1 > 0)
    {
        if (grid[row - 1][col] == opponent)
        {
            for (int i = 1; row - i > 0; i++)
            {
                if (grid[row -i][col] == ' ')
                {
                    continue;
                }
                else if (grid[row - i][col] == player)
                {
                    return true;
                }
            }
        }
    }

    //top right
    if (row - 1 > 0 && col + 1 < 8)
    {
        if (grid[row - 1][col + 1] == opponent)
        {
            for (int i = 1; col + i < 8 && row - i > 0; i++)
            {
                if (grid[row - i][col + i] == ' ')
                {
                    
                }
                else if (grid[row - i][col + i] == player)
                {
                    return true;
                }
                
            }
        }
    }
   
    //left
    if (col - 1 > 0)
    {
        if (grid[row][col - 1] == opponent)
        {
            for (int i = 1; col - i > 0; i++)
            {
                if (grid[row][col - i] == ' ')
                {
                    continue;
                }
                else if (grid[row][col - i] == player)
                {
                    return true;
                }
            }
        }
    }
    //right
    if (col + 1 < 8)
    {
        if (grid[row][col + 1] == opponent)
        {
            for (int i = 1; col + i < 8; i++)
            {
                if (grid[row][col + i] == ' ')
                {
                    continue;
                }
                else if (grid[row][col + i] == player)
                {
                    return true;
                }
            }
        }
    }
    
    //bottom left
    if (row + 1 < 8 && col - 1 > 0)
    {
        if (grid[row + 1][col - 1] == opponent)
        {
            for (int i = 1; col - i > 0 && row + i < 8; i++)
            {
                if (grid[row + i][col - i] == ' ')
                {
                    continue;
                }
                else if (grid[row + i][col - i] == player)
                {
                    return true;
                }
            }
        }
    }

    //bottom
    if (row + 1 < 8)
    {
        if (grid[row + 1][col] == opponent)
        {
            for (int i = 1; row + i < 8; i++)
            {
                if (grid[row + i][col] == ' ')
                {
                    continue;
                }
                else if (grid[row + i][col] == player)
                {
                    return true;
                }
            }
        }
    }

    //bottom right
    if (row + 1 < 8 && col + 1 < 8)
    {
        if (grid[row + 1][col + 1] == opponent)
        {
            for (int i = 1; col + i < 8 && row + i > 0; i++)
            {
                if (grid[row + i][col + i] == ' ')
                {
                    continue;
                }
                else if (grid[row + i][col + i] == player)
                {
                    return true;
                }
            }
        }
    }
    

    return false;
}



OthelloBoardState MakeMove(char player, int col, int row, OthelloBoardState grid)
{
    // if the move was not valid, just return the origional...
    if (IsValidMove(player, col, row, grid) == false)
        return grid;

     grid[row][col] = player;

     

 
     for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            /*
            if (grid[j][i] == ' ')
            {
                grid[j][i] = 'o';
            }
            */
            std::cout << grid[j][i] << " ";
        }
        std::cout << std::endl;
    }
    

    // Task 2:
    // Implement the make move method
    // The method should alter the 'grid' variable, and return it as a copy
    // that represets the new board state

    return grid;
}