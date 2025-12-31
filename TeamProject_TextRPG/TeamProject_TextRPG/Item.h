#pragma once
#include "Global.h"
#include "Character.h"

class Character;
class Item 
{
public:
	virtual ~Item() = default;

	virtual std::string GetName() const = 0;

	virtual void Use(Character& character) = 0;
};