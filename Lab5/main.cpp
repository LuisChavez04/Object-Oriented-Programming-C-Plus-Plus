#include <iostream>
#include "RPG.h"

using namespace std;

int main()
{
    RPG p1 = RPG("Wiz", 70, 45, 15, "mage");
    RPG p2 = RPG();

    printf("%s Current Stats\n", p1.getName().c_str());
    printf("Health: %i\t Strength: %i\t Defense: %i\n", p1.getHealth(), p1.getStrength(), p1.getDefense());

    printf("\n%s Current Stats\n", p2.getName().c_str());
    printf("Health: %i\t Strength: %i\t Defense: %i\n", p2.getHealth(), p2.getStrength(), p2.getDefense());

    p2.updateHealth(0);

    printf("\nPlayer 1's New Health: %i\n", p1.getHealth());
    
    printf("\nPlayer 2's New Health: %i\n", p2.getHealth());

    if(p1.isAlive() == true){
        printf("\nPlayer 1 is alive\n");
    } else{
        printf("\nPlayer 1 defeated\n");
    }

    if(p2.isAlive() == true){
        printf("\nPlayer 2 is alive\n");
    } else{
        printf("\nPlayer 2 is defeated\n");
    }

    return 0;
}