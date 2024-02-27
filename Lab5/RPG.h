#ifndef RPG_H
#define RPG_H

#include <iostream>
#include <string>
using namespace std;

const int SKILL_SIZE = 2;

class RPG {
    public:
        //constructors
        RPG();
        RPG(string name, int health, int strength, int defense, string type);

        //Complete the rest
        
        //Mutators
        void setSkills();
        void printAction(string, RPG);
        void updateHealth(int new_health);
        void attack(RPG *);
        void useSkill(RPG *);

        //Accessors
        string getName();
        int getHealth();
        int getStrength();
        int getDefense();
        string getType();


    private:
        //Complete the rest
        string name;
        int health;
        int strength;
        int defense;
        
        string type; //Warrior, Mage, Thief, Archer
        string skills[SKILL_SIZE];

};
#endif