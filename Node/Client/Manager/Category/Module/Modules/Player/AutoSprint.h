#pragma once
#include "../../Module.h"

class AutoSprint : public Module {
public:
	AutoSprint(Manager* mgr) : Module(mgr->categories[CategoryType::PLAYER], "AutoSprint") {

		registerEvent<GameModeTickEvent>([&](GameModeTickEvent* args) {

			auto gm = args->GM;
			auto player = gm->player;

			player->setSprinting(true);

		});

	};
};