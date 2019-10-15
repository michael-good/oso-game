#include <stdio.h>
#include "colors.h"
#include "map.h"


/*
 * void initialize_map(t_map *map);
 * Map is initialized by calling get_user_rows_cols_input
 * and initialize_squares.
 */
void initialize_map(t_map *map) {
    get_user_rows_cols_input(map);
    initialize_squares(map);
}


/*
 * void get_user_rows_cols_input(t_map *map);
 * Given a pointer to map, user is asked for rows and columns. It is made sure
 * that entered values are within correct range. Such values are assigned to map
 * and squares are initialized.
 */
void get_user_rows_cols_input(t_map *map) {
    int flag = TRUE;
    while(flag) {
        printf("Type in the number of rows (%d - %d): ", MIN_ROWS, MAX_ROWS);
        scanf("%d%*c", &map->num_rows);
        printf("Type in the number of columns (%d - %d): ", MIN_COLS, MAX_COLS);
        scanf("%d%*c", &map->num_cols);
        if (map->num_rows <= MAX_ROWS && map->num_rows >= MIN_ROWS && map->num_cols <= MAX_COLS && map->num_cols >= MIN_COLS) {
            flag = FALSE;
        } else { 
            printf("Wrong input!\n");
        }
    }
}


/*
 * void inicializar_casillas(t_map *map);
 * Given a pointer to map with the number of rows and columns already
 * initialized, all squares of the board are set to empty.
 */
void initialize_squares(t_map *map) {
	int row, col;
	for(row = 0; row < map->num_rows; row++) {
		for(col = 0; col < map->num_cols; col++) {
			map->square[row][col].letter = EMPTY_SQUARE;
			map->square[row][col].player = NO_PLAYER;
		}
	}
	map->num_squares = map->num_rows * map->num_cols;
	map->num_blank_squares = map->num_squares;
}


/*
 * void imprimir_map(t_map map);
 * Given a map, the game board is printed assigning 'O' and 'S'
 * characters to the player they belong to. 
 */
void print_map(t_map map) {
    int col, row, ten;

    printf("  ");
    for(col = 0; col < map.num_cols; col++) {
        if (col < 10) {
            printf("|0");
        } else if (col < 20) {
            printf("|1");
        } else if (col < 30) {
            printf("|3");
        }
    }
    printf("|");
    printf("\n");
    printf("  ");
    ten = 0;
    for(col = 0; col < map.num_cols; col++) {
        printf("|%d", ten);
        ten++;
        if(ten == 10) {
            ten = 0;
        }
    }
    printf("|");
    printf("\n");
    for(row = 0; row < map.num_rows; row++) {
        printf("%02d", row);
        for(col = 0; col < map.num_cols; col++) {
            printf("|");
            set_print_color(map.square[row][col].player);
            printf("%c", map.square[row][col].letter);	
            reset_print_color();
        }
        printf("|");
        printf("\n");
    }
}


/*
 * void draw_move(t_map *map, int number_of_player, int row, int col, char car);
 * Given a map, a player number, a row, a column and a character 'O' or 'S',
 * the character is written in the corresponding square for the specified player.
 */
void draw_move(t_map *map, int number_of_player, int row, int col, char car) {
    map->square[row][col].letter = car;
    map->square[row][col].player = number_of_player;
}


/*
 * int calculate_osos(t_map *map, int row, int col, char car);
 * Given a map pointer, a location in it (row and column) and a character, 
 * it calculates the number of osos that can be obtained by placing the input
 * character in the specified square.
 */
int calculate_osos(t_map *map, int row, int col, char car){
	int osos = 0, N = TRUE, NE = TRUE, E = TRUE, SE = TRUE, S = TRUE, SO = TRUE, O = TRUE, NO = TRUE;  
	if (car == 'S') {
		if((col != 0 && row != 0 || row != map->num_rows - 1) && (col != map->num_cols - 1 || col != map->num_cols - 1) && (row != 0 || row != map->num_rows - 1 && col != 0) ) 
		{
			if (map->square[row-1][col].letter == 'O' && map->square[row+1][col].letter == 'O') {
				osos = osos + 1;
			}
			if(map->square[row][col-1].letter == 'O' && map->square[row][col+1].letter == 'O') {
				osos = osos + 1;
			}
			if(map->square[row-1][col-1].letter == 'O' && map->square[row+1][col+1].letter == 'O') {
				osos = osos + 1;
			}
			if(map->square[row-1][col+1].letter == 'O' && map->square[row+1][col-1].letter == 'O') {
				osos = osos + 1;
			}
		}
		else if(col == 0 && row != 0 && row != map->num_rows - 1 || col == map->num_cols - 1 && row != 0 && row != map->num_rows - 1 ) {
			if (map->square[row-1][col].letter == 'O' && map->square[row+1][col].letter == 'O') {
				osos = osos + 1;
			}
		} else if(row == 0 && col != 0 && col != map->num_cols - 1 || row == map->num_rows - 1 && col != 0 && col != map->num_cols - 1 ) {
			if(map->square[row][col-1].letter == 'O' && map->square[row][col+1].letter == 'O') {
				osos = osos + 1;
			}
		}
	  }
	else if (car == 'O') {
		if(row == 0 || row == 1) {
			N = FALSE;
			NE = FALSE;
			NO = FALSE;
		}
		if(col == 0|| col == 1) {
			NO = FALSE;
			O = FALSE;
			SO = FALSE;
		}
		if(row == map->num_rows - 1 || row == map->num_rows - 2) {
			SO = FALSE;
			S = FALSE;
			SE = FALSE;
		}
		if(col == map->num_cols - 1 ||col == map->num_cols - 2) {
			SE = FALSE;
			E = FALSE;
			NE = FALSE;
		}
		if (N == TRUE){
			if(map->square[row-2][col].letter == 'O' && map->square[row-1][col].letter == 'S') {
				osos++;
			}
		}
		if (NE == TRUE){
			if(map->square[row-2][col+2].letter == 'O' && map->square[row-1][col+1].letter == 'S') {
				osos++;
			}
		}
		if (E == TRUE){
			if(map->square[row][col+2].letter == 'O' && map->square[row][col+1].letter == 'S') {
				osos++;
			}
		}
		if (SE == TRUE){
			if(map->square[row+2][col+2].letter == 'O' && map->square[row+1][col+1].letter == 'S') {
				osos++;
			}
		}
		if (S == TRUE){
			if(map->square[row+2][col].letter == 'O' && map->square[row+1][col].letter == 'S') {
				osos++;
			}
		}
		if (SO == TRUE){
			if(map->square[row+2][col-2].letter == 'O' && map->square[row+1][col-1].letter == 'S') {
				osos++;
			}
		}
		if (O == TRUE){
			if(map->square[row][col-2].letter == 'O' && map->square[row][col-1].letter == 'S') {
				osos++;
			}
		}
		if (NO == TRUE){
			if(map->square[row-2][col-2].letter == 'O' && map->square[row-1][col-1].letter == 'S') {
				osos++;
			}
		}
	}
	return (osos);	
}

