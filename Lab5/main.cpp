#include <iostream>
#include "RPG.h"

using namespace std;

/**
 * @brief Prints both player's name and their health.
 * Example Output for names Wiz and NPC
 * Wiz health: 75 NPC health: 100\n
 * 
 * @param player1 
 * @param player2 
 */
void displayStats(RPG player1, RPG player2){
    printf("\n%s Current Stats\n", player1.getName().c_str());
    printf("Health: %i\t Strength: %i\t Defense: %i\n", player1.getHealth(), player1.getStrength(), player1.getDefense());

    printf("\n%s Current Stats\n", player2.getName().c_str());
    printf("Health: %i\t Strength: %i\t Defense: %i\n", player2.getHealth(), player2.getStrength(), player2.getDefense());



    printf("\nPlayer 1's New Health: %i\n", player1.getHealth());
    
    printf("\nPlayer 2's New Health: %i\n", player2.getHealth());
}

/**
 * @brief Displays who wins based on who is alive. Use an if statement to check whether
 * player 1 is alive. If so, print that they won, else player 2 won.
 * 
 * Example Output:
 * Wiz defeated NPC! Good game!\n
 * 
 * @param player1 
 * @param player2 
 */
void displayEnd(RPG player1, RPG player2){
    if(player1.isAlive() == false){
        printf("\nPlayer 1 is defeated\n");
        printf("\nPlayer 2 Wins! Good game!\n");
    } else{
        printf("\nPlayer 2 is defeated\n");
        printf("\nPlayer 1 wins! Good game!\n");
    }
}

/**
 * @brief uses a while loop to check whether both players are alive.
 * If so, it calls displayStats((*player1), (*player2))
 * Inside the while loop it:
 *  Then prints the name of player one to say that it is their turn
 *  Then call (*player1).useSKill(player2)
 *  Then prints "--------------------------------------\n"
 * 
 *  Repeat the process for player 2 acting on player 1 inside the same while loop
 *  Then prints the name of player two to say that it is their turn
 *  Then call (*player2).useSkill(player1)
 *  Then prints "--------------------------------------\n"
 * 
 Refer to the Role Playing Game Part Two instructions for the example output
 *
 * @param player1
 * @param player2
 */
void gameLoop(RPG * player1, RPG * player2){
    while((*player1).isAlive() && (*player2).isAlive() == true){
        displayStats((*player1), (*player2));

        printf("\nPlayer 1's Turn: \n");
        (*player1).useSkill(player2);
        printf("-------------------------------------\n");

        printf("\nPlayer 2's Turn: \n");
        (*player2).useSkill(player1);
        printf("-------------------------------------\n");
    }
}

int main()
{
    RPG player1 = RPG("Wiz", 70, 45, 15, "mage");
    RPG player2 = RPG();

    gameLoop(&player1, &player2);
    displayEnd(player1, player2);

    return 0;
}