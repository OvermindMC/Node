#pragma once
#include "../../Module.h"

class Killaura : public Module {
public:
	float range = 12.f;
	bool multi = true;
public:
	size_t renderFrame = 0;
public:
	Killaura(Manager* mgr) : Module(mgr->categories[CategoryType::COMBAT], "Killaura") {

		registerEvent<RenderCtxEvent>([&](RenderCtxEvent* args) {

			this->renderFrame++;
			
			if(this->renderFrame >= 3)
				this->renderFrame = 0;
			else
				return;

			auto instance = args->ctx->instance;
			
			auto player = (instance != nullptr ? instance->getPlayer() : nullptr);
			auto myPos = (player != nullptr ? *player->getPos() : Vec3<float>());
			auto gm = (player != nullptr ? player->getGameMode() : nullptr);

			if(player == nullptr || gm == nullptr)
				return;

			auto I = 0;
			forEachEntity([&](Actor* entity, bool isRegular) {

				if(I > (multi ? 1 : 0) || !isRegular || entity->runtimeId == player->runtimeId || !entity->isAlive())
					return;
				
				if(entity->getPos()->dist(myPos) > this->range)
					return;

				I++;
				player->swing();
				gm->attack(entity);

			},
				[&](Actor* first, Actor* second) {
					return first->getPos()->dist(myPos) < second->getPos()->dist(myPos);
				}
			);

		});

	};
};