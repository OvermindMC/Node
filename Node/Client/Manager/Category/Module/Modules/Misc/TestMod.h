#pragma once
#include "../../Module.h"

class TestMod : public Module {
public:
	bool setWindow = false;
public:
	TestMod(Manager* mgr) : Module(mgr->categories[CategoryType::MISC], "TestMod") {

		registerEvent<ModuleEvent>([&](ModuleEvent* args) {

			if (!args->isTicking && args->isEnabled) {

				auto instance = MC::getClientInstance();
				auto player = (instance != nullptr ? instance->getPlayer() : nullptr);

				if (player) {

					std::ostringstream o;
					o << std::hex << player;
#
					Utils::debugOutput("Player: " + o.str());

				};

			};

		});

		registerEvent<ImGuiEvent>([&](ImGuiEvent* args) {

			auto io = args->io;

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