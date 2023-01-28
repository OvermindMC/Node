#pragma once
#include "Actor.h"

class Player : public Actor {
public:
	auto getSupplies(void) -> PlayerInventory* {
		return *(PlayerInventory**)((uintptr_t)(this) + 0xDB8);
	};
public:
	auto getGameMode(void) -> GameMode* {
		return *(GameMode**)((uintptr_t)(this) + 0x1658);
	};
private:
	virtual ~Player(void);
public:
	virtual auto knockback(class Actor*, int, float, float, float, float, float) -> void;
public:
	virtual auto spawnAnim(void) -> void;
public:
	virtual auto setSprinting(bool) -> void;
};