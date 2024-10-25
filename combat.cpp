#include <iostream>
#include "DamageCalculation.h"


template<typename Attacker, typename Target>
void Attack(Attacker* attacker, Target* target) {
    float damage;
    
    damage = DamageCalc(attacker->baseDamage, attacker->isStrengthen, attacker->isSpeed);
    
   
    
    std::cout << attacker->name << " damage after buffs: " << damage << "\n";
    target->health -= damage;
    
    //! UNFINISHED
}