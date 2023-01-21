#pragma once
#include "../../Module.h"

class Killaura : public Module {
public:
	float range = 12.f;
	bool multi = true;
public:
	Killaura(Manager* mgr) : Module(mgr->categories[CategoryType::COMBAT], "Killaura") {

		registerEvent<GameModeTickEvent>([&](GameModeTickEvent* args) {

			auto gm = args->GM;
			auto player = gm->player;
			auto myPos = player->getPos();

			auto I = 0;
			forEachEntity([&](Actor* entity, bool isRegular) {

				if(I > (multi ? 1 : 0) || !isRegular || entity->runtimeId == player->runtimeId || !entity->isAlive())
					return;
				
				if(entity->getPos()->dist(*myPos) > this->range)
					return;

				I++;
				player->swing();
				gm->attack(entity);

			},
				[&](Actor* first, Actor* second) {
					return first->getPos()->dist(*myPos) < second->getPos()->dist(*myPos);
				}
			);

		});

	};
};