#ifndef MAPA_H
#define	MAPA_H

#define TRUE	 1
#define FALSE	 0

#define MIN_ROWS	 3
#define MIN_COLS	 3
#define MAX_ROWS	30
#define MAX_COLS	30

#define NO_PLAYER	-1

#define EMPTY_SQUARE ' '

typedef struct {
	char letter;
	int	player;
} t_square;

typedef struct {
	int	num_rows;
	int	num_cols;
	int	num_squares;
	int	num_blank_squares;
	t_square square[MAX_ROWS][MAX_COLS];
} t_map;


/*
 * void initialize_map(t_map *map);
 * Map is initialized by calling get_user_rows_cols_input
 * and initialize_squares.
 */
void initialize_map(t_map *map);


/*
 * void get_user_rows_cols_input(t_map *map);
 * Given a pointer to map, user is asked for rows and columns. It is made sure
 * that entered values are within correct range. Such values are assigned to map
 * and squares are initialized.
 */
void get_user_rows_cols_input(t_map *map);


/*
 * void inicializar_casillas(t_map *map);
 * Given a pointer to map with the number of rows and columns already
 * initialized, all squares of the board are set to empty.
 */
void initialize_squares(t_map *map);


/*
 * void imprimir_map(t_map map);
 * Given a map, the game board is printed assigning 'O' and 'S'
 * characters to the player they belong to. 
 */
void print_map(t_map map);


/*
 * void draw_move(t_map *map, int number_of_player, int row, int col, char car);
 * Given a map, a player number, a row, a column and a character 'O' or 'S',
 * the character is written in the corresponding square for the specified player.
 */
void draw_move(t_map *map, int number_of_player, int row, int col, char car);


/*
 * int calculate_osos(t_map *map, int row, int col, char car);
 * Given a map pointer, a location in it (row and column) and a character, 
 * it calculates the number of osos that can be obtained by placing the input
 * character in the specified square.
 */
int calculate_osos(t_map *map, int row, int col, char car);

#endif	/* map_H */

