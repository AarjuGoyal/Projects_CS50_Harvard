/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

//position of the empty space
int x_BlankSpace, y_BlankSpace;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);
        
        // check for win
        if (won())
        {
                
            printf("ftw!\n");
            return 0;
        }

       

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }
        
                 

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
        
        
    }
    
    // close log
    fclose(file);

    // failure
    return 1;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // TODO
    int ValueToBeFilled, i, j;
    ValueToBeFilled = d*d - 1;
    for(i=0 ; i<d-1; i++)
    {
        for(j=0; j<d; j++)
        {
            board[i][j] = ValueToBeFilled;
            ValueToBeFilled--;
            
        }
        
    }
    for(j = 0; j<d-3; j++)
    {
        board[i][j] = ValueToBeFilled;
        ValueToBeFilled--;
    }
    if(d%2 == 0)
    {
        board[i][j] = 1;
        board[i][j+1] = 2;
    }
    else
    {
        board[i][j] = 2;
        board[i][j+1] = 1;
    }
    j = j+2;
    board[i][j] = 0;
    x_BlankSpace = i;
    y_BlankSpace = j;
    
    
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
    int i, j;
    for(i = 0 ; i < d; i++)
    {
        for(j = 0; j< d; j++)
        {
            if(i == x_BlankSpace && j == y_BlankSpace)
                printf("  ");
            else
                printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO
    int x_PosOfTile, y_PosOfTile, flag = 0, temp;
    if(board[x_BlankSpace][y_BlankSpace - 1] == tile)
    {
        flag  = 1;
        x_PosOfTile = x_BlankSpace;
        y_PosOfTile = y_BlankSpace - 1;
    }
    
    else if(board[x_BlankSpace][y_BlankSpace + 1] == tile)
    {
        flag  = 1;
        x_PosOfTile = x_BlankSpace;
        y_PosOfTile = y_BlankSpace + 1;
    }
        
    else if(board[x_BlankSpace - 1][y_BlankSpace] == tile)
    {
        flag  = 1;
        x_PosOfTile = x_BlankSpace - 1;
        y_PosOfTile = y_BlankSpace;
    }
        
    else if(board[x_BlankSpace + 1][y_BlankSpace] == tile)
    {
        flag  = 1;
        x_PosOfTile = x_BlankSpace + 1;
        y_PosOfTile = y_BlankSpace;
    }
        
    if(flag == 0)
        return false;
    else
        //printf("\nlegal move, tile found at %d and %d", x_PosOfTile, y_PosOfTile);
    
    
    temp = board[x_PosOfTile][y_PosOfTile];
    board[x_PosOfTile][y_PosOfTile] = board[x_BlankSpace][y_BlankSpace];
    board[x_BlankSpace][y_BlankSpace] = temp;
    x_BlankSpace = x_PosOfTile;
    y_BlankSpace = y_PosOfTile;
        //printf("\n position of white Space is %d and %d ", x_BlankSpace, y_BlankSpace);
    return true;
    

}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    int i, j, flag = 1, Value = 1;
    for(i = 0; i < d -1 ; i++)
    {
        for(j = 0; j < d; j++)
        {
            if(board[i][j] != Value)
            {
                flag = 0;
                //printf("The Value at %d,%d is wrong", i,j);
                break;
            }
            Value++;
        }
    }
    for(j = 0; j < d - 1; j++)
    {
        if(board[i][j] != Value)
        {
            flag = 0;
            //printf("The Value at %d,%d is wrong", i,j);
            break;
        }
        Value++;
    }
    if(board[i][j] != 0)
    {
        flag = 0;
        //printf("The Value at %d,%d is wrong", i,j);
    }

    if(flag == 0)
        return false;
    else
        return true;
}