#pragma once
#include "Actor.h"

template<typename T>
class NonOwnerPointer;

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
	virtual auto spawnAnim(void) -> void;
	virtual auto setSprinting(bool) -> void;
	virtual auto getHurtSound(void) -> enum LevelSoundEvent;
	virtual auto getDeathSound(void) -> enum LevelSoundEvent;
	virtual auto getSpeed(void) -> float;
	virtual auto setSpeed(float) -> void;
	virtual auto getSprintSpeedIncrease(void) -> float;
	virtual auto hurtEffects(class ActorDamageSource*, float, bool, bool) -> void;
	virtual auto getMeleeWeaponDamageBonus(class Mob*) -> float;
	virtual auto getMeleeKnockbackBonus(void) -> __int64;
	virtual auto travel(float, float, float) -> void;
	virtual auto applyFinalFriction(float, bool) -> void;
	virtual auto aiStep(class IMobMovementProxy*) -> void;
	virtual auto aiStep(void) -> void;
	virtual auto pushActors(void) -> void;
	virtual auto lookAt(Actor*, float, float) -> void;
	virtual auto isLookingAtAnEntity(void) -> bool;
	virtual auto checkSpawnRules(bool) -> bool;
	virtual auto checkSpawnObstruction(void) -> bool;
	virtual auto getAttackAnim(float) -> float;
	virtual auto getItemUseDuration(void) -> __int64;
	virtual auto getItemUseStartupProgress(void) -> float;
	virtual auto getItemUseIntervalProgress(void) -> float;
	virtual auto getItemUseIntervalAxis(void) -> __int64;
	virtual auto getTimeAlongSwing(void) -> __int64;
	virtual auto ate(void) -> void;
	virtual auto getMaxHeadXRot(void) -> float;
	virtual auto isAlliedTo(class Mob*) -> bool;
	virtual auto doHurtTarget(class Actor*, enum ActorDamageCause*) -> bool;
	virtual auto canBeControlledByPassenger(void) -> bool;
	virtual auto leaveCaravan(void) -> void;
	virtual auto joinCaravan(class Mob*) -> void;
	virtual auto hasCaravanTail(void) -> bool;
	virtual auto getCaravanHead(void) -> class Mob*;
	virtual auto getArmorValue(void) -> __int64;
	virtual auto getArmorCoverPercentage(void) -> float;
	virtual auto getToughnessValue(void) -> __int64;
	virtual auto hurtArmorSlots(class ActorDamageSource const&, int, std::bitset<4>) -> void;
	virtual auto setDamagedArmor(enum ArmorSlot, class ItemStack*) -> void;
	virtual auto sendArmorDamage(std::bitset<4>) -> void;
	virtual auto sendArmor(std::bitset<4>) -> void;
	virtual auto containerChanged(int) -> void;
	virtual auto updateEquipment(void) -> void;
	virtual auto clearEquipment(void) -> __int64;
	virtual auto getAllArmorID(void) -> std::vector<int>;
	virtual auto getAllHand(void) -> __int64;
	virtual auto getAllEquipment(void) -> __int64;
	virtual auto getArmorTypeHash(void) -> __int64;
	virtual auto dropEquipmentOnDeath(void) -> __int64;
	virtual auto dropEquipmentOnDeath(class ActorDamageSource*, int) -> void;
	virtual auto clearVanishEnchantedItemsOnDeath(void) -> void;
	virtual auto sendInventory(bool) -> void;
	virtual auto getDamageAfterEnchantReduction(class ActorDamageSource*, float) -> float;
	virtual auto getDamageAfterArmorReduction(class ActorDamageSource*, float) -> float;
	virtual auto getDamageAfterResistanceEffect(class ActorDamageSource*, float) -> float;
	virtual auto createAIGoals(void) -> bool;
	virtual auto onBorn(Actor*, Actor*) -> void;
	virtual auto setItemSlot(enum EquipmentSlot, class ItemStack*) -> bool;
	virtual auto setTransitioningSitting(bool) -> void;
	virtual auto attackAnimation(Actor*, float) -> void;
	virtual auto getAttackTime(void) -> __int64;
	virtual auto _getWalkTargetValue(Vec3<int>) -> float;
	virtual auto canExistWhenDisallowMob(void) -> bool;
	virtual auto useNewAi(void) -> void;
	virtual auto ascendLadder(void) -> void;
	virtual auto ascendBlockByJumping(void) -> void;
	virtual auto descendBlockByCrouching(void) -> void;
	virtual auto dropContainer(void) -> void;
	virtual auto initBodyControl(void) -> std::unique_ptr<class BodyControl>;
	virtual auto jumpFromGround(void) -> void;
	virtual auto jumpFromGround(class IMobMovementProxy) -> void;
	virtual auto updateAi(void) -> void;
	virtual auto newServerStep(void) -> void;
	virtual auto _serverAiMobStep(void) -> void;
	virtual auto dropBags(void) -> void;
	virtual auto tickDeath(void) -> void;
	virtual auto updateGliding(void) -> void;
	virtual auto _allowAscendingScaffolding(void) -> bool;
	virtual auto _getAdjustedAABBForSpawnCheck(AABB<float>&, Vec3<float>&) -> AABB<float>&;
	virtual auto prepareRegion(class ChunkSource*) -> void;
	virtual auto destroyRegion(void) -> void;
	virtual auto suspendRegion(void) -> void;
	virtual auto resendAllChunks(void) -> void;
	virtual auto _fireWillChangeDimension(void) -> void;
	virtual auto _fireDimensionChanged(void) -> void;
	virtual auto changeDimensionWithCredits(class AutomaticID<class Dimension, int>) -> void;
	virtual auto tickWorld(class Tick*) -> void;
	virtual auto frameUpdate(class FrameUpdateContextBase*) -> void;
	virtual auto getTickingOffsets(void) -> std::vector<class ChunkPos>&;
	virtual auto moveView(void) -> void;
	virtual auto moveSpawnView(Vec3<float>&, class AutomaticID<class Dimension, int>) -> void;
	virtual auto setName(std::string&) -> void;
	virtual auto getTravelledMethod(void) -> enum TravelMethod;
	virtual auto checkMovementStats(Vec3<float>) -> void;
	virtual auto getCurrentStructureFeature(void) -> class StructureFeature;
	virtual auto isAutoJumpEnabled(void) -> bool;
	virtual auto respawn(void) -> void;
	virtual auto resetRot(void) -> void;
	virtual auto isInTrialMode(void) -> bool;
	virtual auto hasResource(int) -> bool;
	virtual auto completeUsingItem(void) -> void;
	virtual auto startDestroying(void) -> void;
	virtual auto stopDestroying(void) -> void;
	virtual auto openPortfolio(void) -> void;
	virtual auto openBook(int, bool, int, class BlockActor*) -> void;
	virtual auto openTrading(uint64_t*, bool) -> void;
	virtual auto canOpenContainerScreen(void) -> bool;
	virtual auto openChalkboard(class ChalkboardBlockActor*, bool) -> void;
	virtual auto openNpcInteractScreen(std::shared_ptr<class INpcDialogueData>) -> void;
	virtual auto openInventory(void) -> void;
	virtual auto displayChatMessage(std::string*, std::string*) -> void;
	virtual auto displayClientMessage(std::string*) -> void;
	virtual auto displayTextObjectMessage(class TextObjectRoot*, std::string*, std::string*) -> void;
	virtual auto displayTextObjectWhisperMessage(class ResolvedTextObject*, std::string*, std::string*) -> void;
	virtual auto displayTextObjectWhisperMessage(std::string*, std::string*, std::string*) -> void;
	virtual auto displayWhisperMessage(std::string*, std::string*, std::string*, std::string*) -> void;
	virtual auto startSleepInBed(Vec3<int>) -> enum BedSleepingResult;
	virtual auto stopSleepInBed(bool, bool) -> void;
	virtual auto canStartSleepInBed(void) -> bool;
	virtual auto getSleepTimer(void) -> __int64;
	virtual auto getPreviousTickSleepTimer(void) -> __int64;
	virtual auto openSign(Vec3<int>) -> void;
	virtual auto playEmote(std::string&) -> void;
	virtual auto isHostingPlayer(void) -> bool;
	virtual auto isLoading(void) -> bool;
	virtual auto isPlayerInitialized(void) -> bool;
	virtual auto stopLoading(void) -> void;
	virtual auto registerTrackedBoss(uint64_t) -> void;
	virtual auto unRegisterTrackedBoss(uint64_t) -> void;
	virtual auto setPlayerGameType(enum GameType) -> void;
	virtual auto initHUDContainerManager(void) -> void;
	virtual auto _crit(class Actor*) -> void;
	virtual auto getEventing(void) -> class IMinecraftEventing*;
	virtual auto getUserId(void) -> __int64;
	virtual auto sendEventPacket(class EventPacket*) -> void;
	virtual auto addExperience(int) -> void;
	virtual auto addLevels(int) -> void;
	virtual auto setContainerData(class IContainerManager*, int, int) -> void;
	virtual auto slotChanged(class IContainerManager*, class Container*, int, class ItemStack*, class ItemStack*, bool) -> void;
	virtual auto inventoryChanged(class Container*, int, class ItemStack*, class ItemStack*, bool) -> void;
	virtual auto refreshContainer(class IContainerManager*) -> void;
	virtual auto deleteContainerManager(void) -> void;
	virtual auto setFieldOfViewModifier(float) -> void;
	virtual auto isActorRelevant(class Actor*) -> void;
	virtual auto isTeacher(void) -> bool;
	virtual auto onSuspension(void) -> void;
	virtual auto onLinkedSlotsChanged(void) -> void;
	virtual auto startCooldown(class Item*, bool) -> void;
	virtual auto getItemCooldownLeft(unsigned __int64) -> __int64;
	virtual auto getItemCooldownLeft(class HashedString*) -> __int64;
	virtual auto getMaxItemCooldownLeft(void) -> __int64;
	virtual auto isItemOnCooldown(class HashedString*) -> bool;
	virtual auto sendInventoryTransaction(class InventoryTransaction*) -> void;
	virtual auto sendComplexInventoryTransaction(std::unique_ptr<class ComplexInventoryTransaction*>) -> void;
	virtual auto sendNetworkPacket(class Packet*) -> void;
	virtual auto getPlayerEventCoordinator(void) -> class PlayerEventCoordinator*;
	virtual auto tryGetMoveInputHandler(void) -> MoveInputHandler*;
	virtual auto getInputMode(void) -> enum InputMode;
	virtual auto getPlayMode(void) -> enum ClientPlayMode;
	virtual auto reportMovementTelemetry(enum MovementEventType) -> void;
	virtual auto isSimulated(void) -> bool;
	virtual auto getXuid(void) -> std::string&;
	virtual auto getMovementSettings(void) -> class PlayerMovementSettings*;
	virtual auto addSavedChunk(class ChunkPos*) -> void;
	virtual auto onMovePlayerPacketNormal(Vec3<float>*, Vec2<float>*, float) -> void;
	virtual auto _createChunkSource(class ChunkSource&) -> std::shared_ptr<class ChunkViewSource>;
	virtual auto setAbilities(class LayeredAbilities*) -> void;
	virtual auto getEditorPlayer(void) -> class NonOwnerPointer<class IEditorPlayer>;
	virtual auto destroyEditorPlayer(void) -> void;
	virtual auto _getSpawnChunkLimit(void) -> __int64;
	virtual auto _updateChunkPublisherView(Vec3<float>*, float) -> void;
};