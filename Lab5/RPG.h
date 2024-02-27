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
        RPG::RPG();
        RPG::RPG(string, int, int, int, string);
        
        void setSkills();
        void printAction(string, RPG);
        void updateHealth(int);
        void attack(RPG *);
        void useSkill(RPG *);

    private:
        //Complete the rest


        string type; //Warrior, Mage, Thief, Archer
        string skills[SKILL_SIZE];

};
#endif