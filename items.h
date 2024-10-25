// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <bitset>

// using std::string, std::vector;
// using Entity = std::uint32_t;
// using ComponentType = std::uint8_t;
// using Signature = std::bitset<MAX_COMPONENTS>;

// const Entity MAX_ENTITTIES = 200;
// const ComponentType MAX_COMPONENTS = 10;


// // affects starting stats
// enum Difficulty { // 0-2 
//     EASY = 0,
//     NORMAL = 1,
//     HARD = 2
// };
#ifndef HITEMS 
#define HITEMS

// Your header file content here



enum Items { // id 3 - 50
    STRENGTHPOT,
    SPEEDPOT,
    HEALTHPOT,
    LOCKPICK,
    ANTIDOTE,
};
#endif
// enum Usables { // 51 - 99
//     LOCKPICK,
//     ANTIDOTE,
// };



// enum Weapons { // 100 - 199
//     SWORD = 100,
//     DAGGER = 101,
//     GREATSWORD = 102,
//     BOW = 103,
//     SHIELD = 104,


    
// };

// enum Armor { // 200 - 299
//     LEATHER = 200,
//     PLATE = 201,
//     CHAINMAIL = 202,
// };

// enum ItemInfo {
//     name,           // str
//     description,    // str
//     owned,          // bool
//     total,          // uint8
// }

// struct weapons {
//     string name;
//     int id;
//     int damage;
// };



// class Player {
//     public: 
//         string name;
//         int level = 1;
//         int exp = 10;
//         int health = 50;
//         int gold = 10;
        
//         enum Difficulty difficulty;

//         vector<string> inventory;
//         string primary = "";
//         string offhand = "";

//     public: Player(string name, enum Difficulty) {
//         this->name = name;
//     }
//     void setDamage(weapon) {

//     }
//     float diffSelector() {
//         switch (this->difficulty) {
//             case 0:
//                 return 2;
//             case 1:
//                 return 1.5;
//             case 2:
//                 return 1;
//         }
//     }
    
//     void diffSet(int mode) {
//         int multiplier = this->diffSelector();
//         this->health *= multiplier;
//         this->gold *= multiplier;


//     }

//     public: void equipment() {
//         string armor = "shirt";
//         string primary = "stick";
//         string offhand = "";

//     }
    


// };

// class Floor {
//     int totalFloors = 10;
//     int rooms;
//     vector<string> items;
//     vector<string> enemies;


//     void createLayout() {

//     }
// };


