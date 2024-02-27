#define RPG_H

using namespace std;

const int SKILL_SIZE = 2;

class RPG {
    public:
        //constructors
        RPG();
        RPG(string name, int health, int strength, int defense, string type);

        //Complete the rest

    private:
        //Complete the rest
        string type; //Warrior, Mage, Thief, Archer
        string skills[SKILL_SIZE];

};