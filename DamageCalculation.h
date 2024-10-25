#ifndef HDamageCalc
#define HDamageCalc
// int attackCounter = 1;
float DamageCalc(float baseDamage, bool isStrengthen=false, bool isSpeed=false) {
    if (isStrengthen) {
        isStrengthen = false;
        baseDamage += (baseDamage * 0.50);
    }

    return baseDamage;
    // Attack(baseDamage, isSpeed);
    //! UNFINISHED
}

#endif