#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include "items.h"
#include "DamageCalculation.h"


using std::string;

enum Difficulty { // 0-2 
    EASY = 0,
    NORMAL = 1,
    HARD = 2
};

class Player {
    public: 
        string name = "Hero";
        string role = "Stranger";
        int level = 1;
        float health = 50;
        float baseDamage = 4;
        uint32_t defense = 5;
        uint32_t gold = 10;
        uint32_t exp = 10;
        bool isStrengthen = false;
        bool isSpeed = false;
        
        enum Difficulty difficulty;

        std::map<enum Items, int> inventory = {
            {STRENGTHPOT, 0},
            {SPEEDPOT, 0},
            {HEALTHPOT, 0},
            {LOCKPICK, 0},
            {ANTIDOTE, 0}
        };
        string primary = "";
        string offhand = "";

    public: Player(string name, enum Difficulty difficulty, string role) {
        this->name = name;
        this->difficulty = difficulty;
        difficultySelector(difficulty);
        setRole(role);

    }
    void setRole(string role) {
        this->role = role;
        setBaseStats(role);
    }
    void setBaseStats(string role) {
        if (role == "knight") {
            this->baseDamage = 5;
            this->defense = 20;
            this->primary = "Sword";
            this->offhand = "Shield";
        }
        else if (role == "rogue") {
            this->baseDamage = 15;
            this->defense = 5;
            this->primary = "Dagger";
        }
        else if (role == "warrior")
        {
            this->baseDamage = 10;
            this->defense = 10;
            this->primary = "Greatsword";
        }
        else if (role == "archer") {
            this->baseDamage = 15;
            this->defense = 5;
            this->primary = "Bow";
        }
        else if (role == "stranger") {
            this->baseDamage = 100;
            this->defense = 100;
            this->health = 1000;
            this->gold = 9999;
            this->level = 99;
            setDifficulity(1); // sets difficulty to normal
            this->difficulty == NORMAL;
            this->primary = "Durandal";
            this->offhand = "The Dragon's Eye";
        }  
    }
    void difficultySelector(enum Difficulty difficulty) {
        switch (difficulty) {
            case 0:
                setDifficulity(2);
                break;
            case 1:
                setDifficulity(1);
                break;
            case 2:
                setDifficulity(0.8);
                break;
        }
    }
    void setDifficulity(float multiplier) {
        this->health = this->health * multiplier;
        this->gold = this->gold * multiplier;
    }

    //* Gameplay methods
    public:
        // template<typename Target>
        // void Attack(Target target) {
        //     float damage = DamageCalculation(target->baseDamage, target->isStrengthen, target->isSpeed);
            
        //     std::cout << damage << "\n";
        //     std::cout << target->health << "\n";
        //     target->health -= damage;
        //     std::cout << target->health << "\n";
        //     //! UNFINISHED
        // }

        void useConsumable(int consumable) {
            consumable = static_cast<Items>(consumable);
            switch (consumable)
            {
            case STRENGTHPOT:
                this->isStrengthen = true;
                break;
            case SPEEDPOT:
                this->isSpeed = true;
                break;
            case HEALTHPOT:
                break;
            case LOCKPICK:
                break;
            case ANTIDOTE:
                break;
            default:
                break;
            }
        }

};



