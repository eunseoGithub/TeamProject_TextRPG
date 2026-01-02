#pragma once
#include "Character.h"
class Warrior :
    public Character
{
public:
    Warrior(string name);

    void Attack(Monster& monster) override;
};

