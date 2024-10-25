#include <iostream>
#include <queue>
#include <ctime>
#include <vector>
#include "items.h"
#include "myVector.cpp"

enum Monster {
    goblin,
    wolf,
    ghost,
    demon,
};

class Enemy {
    int totalEnemies = 4; 
    int uniqueDrops = 5;
    int totalLootNum;
    linkedList<Items> lootOnDrop;
    
    public: 
        enum Monster enemyID;
        std::string name;
        float health;
        float baseDamage;
        bool isStrengthen = false;
        bool isSpeed = false;

        Enemy() {
            srand(time(0));
            totalLootNum = std::rand() % 3 + 1;
            createEnemy();
        }
    
        void createEnemy() {
            int randomID = std::rand() % totalEnemies;
            Monster randomEnemy = static_cast<Monster>(randomID);
            this->enemyID = randomEnemy;
            setLootTable();

            switch (randomEnemy)
            {
            case goblin:
                this->name = "goblin";
                setStats(6,10);
                
                break;
            case wolf:
                this->name = "wolf";
                setStats(12,22);
                break;
            case ghost:
                this->name = "ghost";
                setStats(18,55);
                break;
            case demon:
                this->name = "demon";
                setStats(25,100);
                break;

            default:
                std::cout << randomID;
                break;
            }

    }

    

    
    public: 

        void setStats(float damage, float health) {
            this->baseDamage = damage;
            this->health = health;
        }
        // ! DOESN'T randomize each loot.
        void setLootTable() {
            int randomLoot;
            
            for (int i = 0; i < totalLootNum; i++)
            {   
                
                srand(time(0));     
                int randomLoot = rand() % uniqueDrops;
                Items drops = static_cast<Items>(randomLoot);
                
                // lootOnDrop.push_back(drops);
                lootOnDrop.insert(0, drops);
        
            }
            
        }
        // ? Set return value to the head of the linked list
        // ? Use random number to decide where to loop to in linked list and return value. To decide Player loot
        void getLootTable() {
            setLootTable();
    
            // * DEBUG: Checks if list is populated correctly
            while (lootOnDrop.head != nullptr)
            {
                std::cout << lootOnDrop.head->value << "\n";
                lootOnDrop.head = lootOnDrop.head->next;
            }
            
                    
        }
    
};


// //* DEBUG: Main function to test Enemy class
// int main() {
//     Enemy mon;
//     mon.createEnemy();
//     std::cout << mon.enemyID << ": " << mon.name << std::endl;
//     std::cout << "Damage: " << mon.baseDamage << " " << "Health: " << mon.health << std::endl;
//     mon.getLootTable();
//     return 0;
// }