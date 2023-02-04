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
public:
	virtual auto getHurtSound(void) -> enum LevelSoundEvent;
	virtual auto getDeathSound(void) -> enum LevelSoundEvent;
public:
	virtual auto getSpeed(void) -> float;
	virtual auto setSpeed(float) -> void;
public:
	virtual auto getPickRadius(void) -> float;
public:
	virtual auto hurtEffects(class ActorDamageSource*, float, bool, bool) -> void;
public:
	virtual auto getMeleeWeaponDamageBonus(class Mob*) -> float;
	virtual auto getMeleeKnockbackBonus(void) -> __int64;
public:
	virtual auto travel(float, float, float) -> void;
	virtual auto applyFinalFriction(float, bool) -> void;
public:
	virtual auto aiStep(class IMobMovementProxy*) -> void;
	virtual auto aiStep(void) -> void;
public:
	virtual auto pushActors(void) -> void;
public:
	virtual auto lookAt(Actor*, float, float) -> void;
	virtual auto isLookingAtAnEntity(void) -> bool;
public:
	virtual auto checkSpawnRules(bool) -> bool;
	virtual auto checkSpawnObstruction(void) -> bool;
public:
	virtual auto getAttackAnim(float) -> float;
	virtual auto getItemUseDuration(void) -> __int64;
	virtual auto getItemUseStartupProgress(void) -> float;
	virtual auto getItemUseIntervalProgress(void) -> float;
	virtual auto getItemUseIntervalAxis(void) -> __int64;
	virtual auto getTimeAlongSwing(void) -> __int64;
public:
	virtual auto ate(void) -> void;
public:
	virtual auto getMaxHeadXRot(void) -> float;
public:
	virtual auto isAlliedTo(class Mob*) -> bool;
public:
	virtual auto doHurtTarget(class Actor*, enum ActorDamageCause*) -> bool;
public:
	virtual auto canBeControlledByPassenger(void) -> bool;
public:
	virtual auto leaveCaravan(void) -> void;
	virtual auto joinCaravan(class Mob*) -> void;
	virtual auto hasCaravanTail(void) -> bool;
	virtual auto getCaravanHead(void) -> class Mob*;
public:
	virtual auto getArmorValue(void) -> __int64;
	virtual auto getArmorCoverPercentage(void) -> float;
	virtual auto getToughnessValue(void) -> __int64;
public:
	virtual auto hurtArmorSlots(class ActorDamageSource const&, int, std::bitset<4>) -> void;
	virtual auto setDamagedArmor(enum ArmorSlot, class ItemStack*) -> void;
	virtual auto sendArmorDamage(std::bitset<4>) -> void;
	virtual auto sendArmor(std::bitset<4>) -> void;
public:
	virtual auto containerChanged(int) -> void;
	virtual auto updateEquipment(void) -> void;
	virtual auto clearEquipment(void) -> __int64;
public:
	virtual auto getAllArmorID(void) -> std::vector<int>;
	virtual auto getAllHand(void) -> __int64;
	virtual auto getAllEquipment(void) -> __int64;
	virtual auto getArmorTypeHash(void) -> __int64;
	virtual auto dropEquipmentOnDeath(void) -> __int64;
	virtual auto dropEquipmentOnDeath(class ActorDamageSource*, int) -> void;
	virtual auto clearVanishEnchantedItemsOnDeath(void) -> void;
	virtual auto sendInventory(bool) -> void;
public:
	virtual auto getDamageAfterEnchantReduction(class ActorDamageSource*, float) -> float;
	virtual auto getDamageAfterArmorReduction(class ActorDamageSource*, float) -> float;
	virtual auto getDamageAfterResistanceEffect(class ActorDamageSource*, float) -> float;
public:
	virtual auto createAIGoals(void) -> bool;
public:
	virtual auto onBorn(Actor*, Actor*) -> void;
public:
	virtual auto setItemSlot(enum EquipmentSlot, class ItemStack*) -> bool;
public:
	virtual auto setTransitioningSitting(bool) -> void;
public:
	virtual auto attackAnimation(Actor*, float) -> void;
	virtual auto getAttackTime(void) -> __int64;
public:
	virtual auto _getWalkTargetValue(Vec3<int>*) -> float;
public:
	virtual auto canExistWhenDisallowMob(void) -> bool;
public:
	virtual auto useNewAi(void) -> void;
public:
	virtual auto ascendLadder(void) -> void;
	virtual auto ascendBlockByJumping(void) -> void;
	virtual auto descendBlockByCrouching(void) -> void;
public:
	virtual auto dropContainer(void) -> void;
public:
	virtual auto initBodyControl(void) -> std::unique_ptr<class BodyControl>;
public:
	virtual auto jumpFromGround(class IMobMovementProxy*) -> void;
	virtual auto jumpFromGround(void) -> void;
public:
	virtual auto updateAi(void) -> void;
	virtual auto newServerStep(void) -> void;
	virtual auto _serverAiMobStep(void) -> void;
public:
	virtual auto dropBags(void) -> void;
	virtual auto tickDeath(void) -> void;
	virtual auto updateGliding(void) -> void;
public:
	virtual auto _allowAscendingScaffolding(void) -> bool;
public:
	virtual auto _getAdjustedAABBForSpawnCheck(AABB<float>&, Vec3<float>&) -> AABB<float>&;
public:
	virtual auto prepareRegion(class ChunkSource*) -> void;
	virtual auto destroyRegion(void) -> void;
	virtual auto suspendRegion(void) -> void;
	virtual auto resendAllChunks(void) -> void;
public:
	virtual auto _fireWillChangeDimension(void) -> void;
	virtual auto _fireDimensionChanged(void) -> void;
public:
	virtual auto changeDimensionWithCredits(class AutomaticID<Dimension, int>) -> void;
public:
	virtual auto tick(class Tick*) -> void;
public:
	virtual auto frameUpdate(class FrameUpdateContextBase&) -> void;
public:
	virtual auto getTickingOffsets(void) -> std::vector<class ChunkPos>&;
public:
	virtual auto moveView(void) -> void;
};