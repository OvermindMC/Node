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
				o << std::hex << player;

				Utils::debugOutput("Player: " + o.str());

				player->setFieldOfViewModifier(0.7f);

			}
			else {

				player->setFieldOfViewModifier(1.f);

			};

		});

		registerEvent<RenderCtxEvent>([&](RenderCtxEvent* args) {

			auto ctx = args->ctx;
			auto instance = ctx->instance;
			auto player = instance->getPlayer();
			auto font = instance->getMcGame() ? instance->getMcGame()->mcFont : nullptr;

			if (font && player) {

				auto gamePos = Vec3<float>(0.f, -58.f, 0.f);
				auto dist = player->getPos()->dist(gamePos);

				std::ostringstream o;
				o << std::setprecision(4) << dist;

				auto fontSize = std::fmin(std::fmax(dist, 0.8f), 1.f);

				auto text = std::string(std::to_string((int)(gamePos.x)) + ", " + std::to_string((int)(gamePos.y)) + ", " + std::to_string((int)(gamePos.z)));
				text += " [ " + o.str() + " ]";

				auto screenPos = ctx->gameToScreenPos(gamePos);
				auto len = ctx->getTextLength(font, &text, fontSize, false);

				screenPos.x -= (len / 2.f);

				if (screenPos.x <= 0 && screenPos.y <= 0)
					return;

				ctx->fillRectangle(Rect(screenPos.x - 2.f, screenPos.y - fontSize, (screenPos.x + 2.f) + len, screenPos.y + (fontSize * 10.f)), Color(21.f, 21.f, 21.f, .8f));
				ctx->drawText(font, text, screenPos, Color(), fontSize);
				ctx->flushText(0.f);

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