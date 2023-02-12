#pragma once
#include "../../Module.h"

class Killaura : public Module {
public:
	float range = 6.f;
	bool multi = true;
public:
	size_t renderFrame = 0;
public:
	Killaura(Manager* mgr) : Module(mgr->categories[CategoryType::COMBAT], "Killaura") {

		registerEvent<ClickGuiModConfigEvent>([&](auto) {

			ImGui::SliderFloat("Range", &range, 2.f, 12.f, "%.3f");

		});

		registerEvent<ImGuiEvent>([&](auto) {

			/* WIP */

		});

	};
};
