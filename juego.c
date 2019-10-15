#include <stdio.h>
#include "random.h"
#include "sleep.h"
#include "map.h"
#include "players.h"



/*
 * int human_play(t_map *map, int number_of_player);
 * Given a map and a player number, it asks the user for a row,
 * a column and a character ('O' or 'S') and makes a move.
 * It returns the number of OSOs got in this play.
 */
int human_play(t_map *map, int number_of_player) {
    int flag = TRUE, count_osos, row, col;
    char car; 
    while (flag) {
        printf("\nType in a row: ");
        scanf("%d%*c", &row);
        while (row >= map->num_rows || row < 0) {
            printf("Wrong input!\n");
            printf("Type in a row: ");
            scanf("%d%*c", &row);
        }	
        printf("Type in a column: ");
        scanf("%d%*c", &col);
        while (col >= map->num_cols || col < 0) {
            printf("Wrong input!\n");
            printf("Type in a column: ");
            scanf("%d%*c", &col);
        }
        if (map->square[row][col].letter == EMPTY_SQUARE) {
            flag = FALSE;
        } else {
            printf("Position already occupied");
        }
    }
    printf("Type in a letter (O or S): ");
    scanf("%c%*c", &car); 
    while (car != 'O' && car != 'o' && car != 'S' && car != 's') {
        printf("Wrong input!\n");
        printf("Type in a letter (O or S): ");
        scanf("%c%*c", &car); 
    }
    if(car == 'o'){
        car = 'O';
    } else if(car == 's'){
        car = 'S';
    }
    map->square[row][col].player = number_of_player;
    map->square[row][col].letter = car;
    count_osos = calculate_osos(map, row, col, car);
    return (count_osos);
}


/*
 * int machine_play(t_map *map, int player_number);
 * Given a map and a player number, the machine makes a move.
 * It returns the number of OSOs got in this play.
 */
int machine_play(t_map *map, int player_number) {
    int final_row, final_col, row, col;
    int flag = TRUE, count = 0, osos_s = 0, osos_o = 0;
    char letter;
    for (row = 0; row < map->num_rows; row++) {
        for (col = 0; col < map->num_cols; col++) {
            if (map->square[row][col].letter == EMPTY_SQUARE){
                osos_s = calculate_osos(map, row, col, 'S');
                osos_o = calculate_osos(map, row, col, 'O');
                if (osos_s > count) {
                    final_row = row;
                    final_col = col;
                    letter = 'S';
                    count = osos_s;
                }
                if (osos_o > count) {
                    final_row = row;
                    final_col = col;
                    letter = 'O';
                    count = osos_o;
                }
            }
        }
    }	
    if (count == 0) {	
        while (flag){
            final_row = get_random_number(map->num_rows) - 1;
            final_col = get_random_number(map->num_cols) - 1;
            if (map->square[final_row][final_col].letter == EMPTY_SQUARE){
                if(get_random_number(2) == 1) {
                    letter = 'S';
                } else {
                    letter = 'O';
                }
                flag = FALSE;
            }
        }
    }
    sleep_for_while();
    sleep_for_while();
    map->square[final_row][final_col].letter = letter;
    map->square[final_row][final_col].player = player_number;
    return (count);
}


/*
 * int is_game_over(t_map map, t_players players);
 * Given a map and all players, it checks whether the game is
 * over or not. It returns TRUE if game is indeed over. Otherwise,
 * it returns FALSE.
 */
int is_game_over(t_map map, t_players players) {
    int best_player = 0;
    if(map.num_blank_squares == 0){
        for(int i = 0; i < players.num_players; i++) {
            if(players.player[i].num_osos > best_player) {
                best_player = players.player[i].num_osos;
            }
        }
        printf("\nPlayers with more OSOS are: ");
        for(int i = 0; i < players.num_players; i++) {
            if(players.player[i].num_osos == best_player){
                printf("%d,", i);
            }
        }
        return (TRUE);
    } else {
        return(FALSE);
    }
}


/*
 * void print_game_status(t_map map, t_players players);
 * It print the map and the OSO counter of each player given 
 * a map and a list of players.
 */
void print_game_status(t_map map, t_players players) {
    print_map(map);
    print_players_oso_count(players);
}


/*
 * void make_move(t_map *map, t_players *players);
 * Given a map and players, it manages all he logic behind making a move.
 */
void make_move(t_map *map, t_players *players) {
    int osos, flag = TRUE;
    while(flag == TRUE){
        if (players->player[players->turn].type == PLAYER_HUMAN) {
            printf("\nPlayer");
            print_player_info(players->turn);
            osos = human_play(&*map, players->turn);
            map->num_blank_squares--;
            players->player[players->turn].num_osos += osos;
            printf("\n%d osos\n\n", osos);
        }
        else if (players->player[players->turn].type == PLAYER_MACHINE) {
            printf("\nPlayer");
            print_player_info(players->turn);
            osos = machine_play(&*map, players->turn);
            map->num_blank_squares--;
            players->player[players->turn].num_osos += osos;
            printf("\n%d osos\n\n", osos);
        }
        if (osos == 0 || map->num_blank_squares == 0){
            flag = FALSE;
        } else { 
            print_game_status(*map, *players);
        }
    }
    pass_turn(players);
}


/*
 * Iinitializes the game and periodically checks if it is over. 
 */

int main() {
    int game_over;
    char another_game;
    t_map map;
    t_players players;
    set_seed_random_generator();
    printf("Welcome to the OSO game!\n");
    do {
        game_over = FALSE;
        reset_print_color();
        initialize_map(&map);
        initialize_players(&players);
        print_game_status(map, players);
        while(game_over == FALSE){
            make_move(&map, &players);
            print_game_status(map, players);
            game_over = is_game_over(map, players);
            reset_print_color();
        }
        printf("\nDo you want to play again (Y/N)?: ");
        scanf("%*c%c", &another_game);
        while (another_game != 'n' && another_game != 'N' && another_game != 'y' && another_game != 'Y') {
            printf("Wrong input\nDo you want to play again (Y/N)?: ");
            scanf("%*c%c", &another_game);
        }
    } while(another_game == 'y' || another_game == 'Y');
    printf("See you next time!\n");
}
