#pragma once
#include "../../Module.h"

class TabGui : public Module {
public:
	bool selectedCategory = false, selectedMod = false;
	size_t currCategory = 0, currModule = 0;
public:
	float fontSize = 1.f, alpha = 0.f;
	int renderFrame = 0;
public:
	float selCatAnimOff = 0.f, selModAnimOff = 0.f;
	float animModifier = .7f;
public:
	std::vector<std::pair<CategoryType, Category*>> categories;
	std::vector<Module*> modules;
public:
	TabGui(Manager* mgr) : Module(mgr->categories[CategoryType::RENDER], "TabGui", "Toggle modules via arrow keys", VK_TAB) {

		registerEvent<ImGuiEvent>([&](auto) {

			/* WIP */

		});

	};
};