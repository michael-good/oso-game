#ifndef JUGADORES_H 
#define	JUGADORES_H

#define MIN_PLAYERS	2
#define MAX_PLAYERS	6
#define MIN_HUMANS	0
#define MAX_HUMANS	MAX_PLAYERS

#define PLAYER_MACHINE	0
#define PLAYER_HUMAN	1

typedef struct {
	int	num_osos;
	int	type;
} t_player;

typedef struct {
	int	num_players;
	int	num_humans;
	int	turn;
	t_player	player[MAX_PLAYERS];
} t_players;


/*
 * void initialize_players(t_players *players);
 * Given a pointer to players, it asks for the number of players to play
 * and for the number of those players that will be human or machine.
 * It also gives turn to the first player.
 */
void initialize_players(t_players *players);


/*
 * void pass_turn(t_players *players);
 * Given a pointer to players, it passes the turn to next player.
 */
void pass_turn(t_players *players);


/*
 * void print_player_info(int player_number);
 * Given a number corresponding to one player, it prints the player
 * info and resets color.
 */
void print_player_info(int number_of_player);


/*
 * void print_players_oso_count(t_players players);
 * Given a list of players, it prints the number of players each
 * one have.
 */
void print_players_oso_count(t_players players);

#endif	/* players_H */

