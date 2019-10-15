#include <stdio.h>
#include "colors.h"
#include "players.h"


/*
 * void initialize_players(t_players *players);
 * Given a pointer to players, it asks for the number of players to play
 * and for the number of those players that will be human or machine.
 * It also gives turn to the first player.
 */
void initialize_players(t_players *players) {
    int flag = 1;
    while(flag) {
        printf("Type in the number of players (2-6): ");
        scanf("%d", &players->num_players);
        if (players->num_players < 2 || players->num_players > 6) {
            printf("Wrong input\n");
        } else {
            flag = 0;
        }
	}
    flag = 1;
    while(flag) {
        printf("Type in the number of human players (0-%d): ", players->num_players);
        scanf("%d", &players->num_humans);
        if (players->num_humans < 0 || players->num_humans > players->num_players) {
            printf("Wrong input\n");
        } else {
            flag = 0;
        }
	}
	printf("\n");
	players->turn = 0;
    for (int i = 0; i < players->num_players; i++) {
        players->player[i].num_osos = 0;
        if (i < players->num_humans) {
            players->player[i].type = PLAYER_HUMAN;
        } else {
            players->player[i].type = PLAYER_MACHINE;
        }
    }
}


/*
 * void pass_turn(t_players *players);
 * Given a pointer to players, it passes the turn to next player.
 */
void pass_turn(t_players *players) {
    players->turn++;
    if(players->turn == players->num_players) {
        players->turn = 0;  
    }
}


/*
 * void print_player_info(int player_number);
 * Given a number corresponding to one player, it prints the player
 * info and resets color.
 */
void print_player_info(int player_number) {
    set_print_color(player_number);
    printf("#%d", player_number);
    reset_print_color();
}

/*
 * void print_players_oso_count(t_players players);
 * Given a list of players, it prints the number of players each
 * one have.
 */
void print_players_oso_count(t_players players) {
    for(int i = 0; i < players.num_players; i++) {
        print_player_info(i);
        printf(": %d ", players.player[i].num_osos);
    }
}
