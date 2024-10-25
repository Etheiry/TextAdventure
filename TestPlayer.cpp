#include <iostream>
#include "Player.cpp"
#include "Enemy.cpp"
#include "combat.cpp"


//* TEST FUNCTIONS BELOW!
void TestPlayerStats(string role, enum Difficulty diff) {
    string name = "Etheirys";
    
    Player player(name, diff, role);

    assert((player.name == name) && "Name is not the given name!");
    assert((player.role == role) && "Role is not the given role!");
    assert((player.level == 1 || (player.role == "stranger" && player.level == 99)) && "Level changed");

    if (player.role == role) {
        if (player.role == "knight") {
            assert((player.baseDamage == 5 && player.defense == 20 && player.primary == "Sword" && player.offhand == "Shield") && "Player doesn't have correct class stats!");
            
        }
        else if (player.role == "rogue") {
            assert((player.baseDamage == 15 && player.defense == 5 && player.primary == "Dagger") && "Player doesn't have correct class stats!");
            
        }
        else if (player.role == "warrior") {
            assert((player.baseDamage == 10 && player.defense == 10 && player.primary == "Greatsword") && "Player doesn't have correct class stats!");
            
        }
        else if (player.role == "archer") {
            assert((player.baseDamage == 15 && player.defense == 5 && player.primary == "Bow") && "Player doesn't have correct class stats!");
            
        }
        else if (player.role == "stranger") {
            assert((player.baseDamage == 100 && player.defense == 100 && player.health == 1000 && player.gold == 9999 && player.level == 99 && player.primary == "Durandal" && player.offhand == "The Dragon's Eye") && "Player doesn't have correct class stats!");

        }
        if (player.difficulty == EASY && player.role != "stranger") {
            assert((player.health == 100) && "Incorrect starting health for easy mode!");
            assert((player.gold == 20) && "Incorrect starting gold for easy mode!");
        }
        else if (player.difficulty == NORMAL && player.role != "stranger") {
            assert((player.health == 50) && "Incorrect starting health for Normal mode!");
            assert((player.gold == 10) && "Incorrect starting gold for Normal mode!");
        }
        else if (player.difficulty == HARD && player.role != "stranger") {
            assert((player.health == 40) && "Incorrect starting health for Hard mode!");
            assert((player.gold == 8) && "Incorrect starting gold for Hard mode!");
        }
        
    }
    
    std::cout << "PLAYER BASE STATS" << "\n";
    std::cout << "Name: " << player.name << "\n";
    std::cout << "role: " << player.role << "\n";
    std::cout << "Level: " << player.level << "\n";
    std::cout << "Difficulty: " << player.difficulty << "\n";
    std::cout << "Health: " << player.health << "\n";
    std::cout << "Base Damage: " << player.baseDamage << "\n";
    std::cout << "Defense: " << player.defense << "\n";
    std::cout << "Exp: " << player.exp << "\n";
    std::cout << "Gold: " << player.gold << "\n";
    std::cout << "Primary hand: " << player.primary << "\n";
    std::cout << "Offhand: " << player.offhand << "\n";
    std::cout << "Power State: " << player.isStrengthen << "\n";
    std::cout << "Speed State: " << player.isSpeed << "\n" << "\n";

    std::cout << "DEBUGGING INVENTORY SYSTEM" << "\n";
    std::cout << player.inventory.at(STRENGTHPOT) << "\n";
    std::cout << player.inventory.at(SPEEDPOT) << "\n";
    std::cout << player.inventory.at(HEALTHPOT) << "\n";
    std::cout << player.inventory.at(LOCKPICK) << "\n";
    std::cout << player.inventory.at(ANTIDOTE) << "\n";




}

void TestRoleAndDifficultyCombinations() {
    string role;
    enum Difficulty diff;
    int counter = 0;

    string roles[5] = {"archer", "knight", "warrior", "rogue", "stranger"};
    enum Difficulty difficulty[3] = {EASY, NORMAL, HARD};

    for (int i = 0; i < 5; i++)
    {
        role = roles[i];
        for (int i = 0; i < 3; i++)
        {
            diff = difficulty[i];
            counter++;
            std::cout << "Combination # ";
            std::cout << counter << "\n";
            TestPlayerStats(role, diff);
        }
        
    }
}

void TestAttack() {
    Player player("Etheirys", EASY, "knight");
    Enemy enemy;
    
    std::cout << player.name << " base damage: " << player.baseDamage << "\n";
    std::cout << player.name << " health: " << player.health << "\n";
    std::cout << enemy.name << " health: " << enemy.health << "\n";
    Attack<Player, Enemy>(&player, &enemy); 
    
    
    std::cout << enemy.name << " health after damage: " << enemy.health << "\n";
    Attack<Enemy, Player>(&enemy, &player);
    std::cout << player.name << " health after damage: " << player.health << "\n";
}

int main() {
    TestRoleAndDifficultyCombinations();
    TestAttack();
    
    
    return 0;
}

