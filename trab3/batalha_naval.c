#include <stdio.h>

/***************************************** 
** File: battleship.c
** Author: Marie desJardins
** Date: 10/2/06
** E-Mail: mariedj@cs.umbc.edu 
** 
** Read in a Battleship game board, find the ships,
** and print their locations.
*****************************************/ 


#define BOARD_SIZE 10
#define OCEAN '-'
#define SHIP 'S'
#define CARRIER 5
#define BATTLESHIP 4
#define CRUISER 3
#define DESTROYER 2
#define FALSE 0
#define TRUE 1
#define ROW 0
#define COLUMN 1

void ReadBoard (char board[BOARD_SIZE][BOARD_SIZE]);
void PrintBoard (char board[BOARD_SIZE][BOARD_SIZE]);
void ScanRows (char board[BOARD_SIZE][BOARD_SIZE]);
void ScanCols (char board[BOARD_SIZE][BOARD_SIZE]);
void MaybePrintShip (int length, int rowstart, int rowend, 
		     int colstart, int colend);

int main () {
  char board[BOARD_SIZE][BOARD_SIZE];

  /* Initialize the board */
  ReadBoard (board);

  /* Print the board */
  PrintBoard (board);

  /* First scan the rows */
  ScanRows (board);

  /* Next scan the columns */
  ScanCols (board);

  return 0;
}


void ReadBoard (char board[BOARD_SIZE][BOARD_SIZE]) {
  int row, col;
  char c;  /* temp variable */

  /* Read the board */
  for ( row=0 ; row < BOARD_SIZE ; row++ ) {
    for ( col=0 ; col < BOARD_SIZE ; col++ ) {
      scanf ("%c", &board[row][col]);
    }
    scanf ("%c", &c);  /* if all goes well this should read the newline */
  }
}


/***************************************** 
 * Function: PrintBoard
 * Usage: PrintBoard (board);
 *
 * Prints out a formatted Battleship game board
 * 
 * Input: board, a BOARD_SIZE x BOARD_SIZE array of chars
 * Output: None
*****************************************/

void PrintBoard (char board[BOARD_SIZE][BOARD_SIZE]) {
  int row, col;

  for ( row=0 ; row < BOARD_SIZE ; row++ ) {
    for ( col=0 ; col < BOARD_SIZE ; col++ ) {
      printf ("%c", board[row][col]);
    }
    printf ("\n");
  }
}


/***************************************** 
 * Function: ScanRows
 * Usage: ScanRows (board);
 * 
 * Find and print out the locations of ships on a Battleship board
 * that lie in a horizontal orientation,
 *
 * Input: board, a BOARD_SIZE x BOARD_SIZE array of chars
 * Output: None
*****************************************/

void ScanRows (char board[BOARD_SIZE][BOARD_SIZE]) {
  int i, j, scanningShip, length;

  for ( i=0 ; i < BOARD_SIZE ; i++ ) {
    scanningShip = FALSE;
    length = 0;
    for ( j=0 ; j < BOARD_SIZE ; j++ ) {
      if ( board[i][j] == 'S' ) {
	scanningShip = TRUE;
	length++;
      } else {
	if ( scanningShip ) {
	  MaybePrintShip (length, i, j-length, i, j-1);
	  scanningShip = FALSE;
	  length = 0;
	}
      }
      /* what if a ship ended in the last column? */
    }
  }
}


/***************************************** 
 * Function: ScanCols
 * Usage: ScanCols (board)
 *
 * Find and print out the locations of ships on a Battleship board
 * that lie in a vertical orientation,
 * 
 * Input: board, a BOARD_SIZE x BOARD_SIZE array of chars
 * Output: None
*****************************************/

void ScanCols (char board[BOARD_SIZE][BOARD_SIZE]) {
  /* Left as an exercise for the reader... */
}


/***************************************** 
 * Function: MaybePrintShip
 * Usage: MaybePrintShip (length, rowstart, colstart, rowend, colend);
 *
 * Given a ship position (length, starting (x,y) and ending (x,y)),
 * checks to see whether it is really a ship.
 * If so, prints out a message about what type of ship was found,
 * and where it was located (start and end).
 * 
 * Input: board, a BOARD_SIZE x BOARD_SIZE array of chars
 * Output: None
*****************************************/

void MaybePrintShip (int length, int rowstart, int colstart, 
		     int rowend, int colend) {
  switch ( length ) {
    /* length 0 -> hadn't found anything */
    /* If it's length 1, that means it points the other way,
       so just ignore it */
  case 0 :
  case 1 :
    break;

    /* Anything that's length 2 or longer is really a ship.
       Check to see what type it is and print a message. */
  case CARRIER : {
    printf ("Found a carrier! ((%d, %d) to (%d, %d))\n", 
	    rowstart, colstart, rowend, colend);
    break;
  }
  case BATTLESHIP : {
    printf ("Found a battleship! ((%d, %d) to (%d, %d))\n", 
	    rowstart, colstart, rowend, colend);
    break;
  }
  case DESTROYER : {
    printf ("Found a destroyer! ((%d, %d) to (%d, %d))\n", 
	    rowstart, colstart, rowend, colend);
    break;
  }
  case CRUISER : {
    printf ("Found a cruiser! ((%d, %d) to (%d, %d))\n", 
	    rowstart, colstart, rowend, colend);
    break;
  }
  default : {
    printf ("Found unknown object of length %d! ((%d, %d) to (%d, %d))\n", 
	    length, rowstart, colstart, rowend, colend);
    break;
  }
  }
  length = 0;
}
