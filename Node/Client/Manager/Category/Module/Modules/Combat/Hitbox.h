#pragma once
#include "../../Module.h"

class Hitbox : public Module {
public:
	std::map<uint8_t, Vec2<float>> collisions;
public:
	float width = 2.f, height = 2.f;
public:
	Hitbox(Manager* mgr) : Module(mgr->categories[CategoryType::COMBAT], "Hitbox") {

		registerEvent<GameModeTickEvent>([&](GameModeTickEvent* args) {

			auto gm = args->GM;
			auto player = gm->player;

			forEachEntity([&](Actor* entity, bool isRegular) {

				if(!isRegular || player->runtimeId == entity->runtimeId)
					return;
				
				auto type = entity->getEntityTypeId();

				if (!collisions.contains(type)) {

					auto bounds = entity->boundingBox;
					auto diff = bounds.upper.sub(bounds.lower);

					collisions[type] = Vec2<float>(diff.x, diff.y);

				};

				entity->setSize(width, height);

			});

		});

		registerEvent<ModuleEvent>([&](ModuleEvent* args) {

			if(args->isTicking)
				return;

			if(!args->isEnabled) {

				forEachEntity([&](Actor* entity, bool isRegular) {

					if(!isRegular)
						return;

					auto type = entity->getEntityTypeId();
					
					if (!collisions.contains(type))
						return;

					auto size = collisions[type];
					entity->setSize(size.x, size.y);

				});

			};

		});

	};
};