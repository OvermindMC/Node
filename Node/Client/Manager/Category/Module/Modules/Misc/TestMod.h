#pragma once
#include "../../Module.h"

class TestMod : public Module {
public:
	bool setWindow = false;
public:
	TestMod(Manager* mgr) : Module(mgr->categories[CategoryType::MISC], "TestMod") {

		registerEvent<ModuleEvent>([&](ModuleEvent* args) {

			if (args->isTicking)
				return;

			auto instance = MC::getClientInstance();
			auto player = (instance != nullptr ? instance->getPlayer() : nullptr);

			if (!player)
				return;
			
			if (args->isEnabled) {

				std::ostringstream o;
				o << "Player: " << std::hex << player << std::endl;

				Utils::debugOutput(o.str());

			};

		});

		registerEvent<ImGuiEvent>([&](ImGuiEvent* args) {

			if(!setWindow) {

				ImGui::SetNextWindowSize(ImVec2(200.f, 200.f));
				setWindow = true;

			};
			
			if(ImGui::Begin("Test")) {

				ImGui::End();

			};

		});

	};
};