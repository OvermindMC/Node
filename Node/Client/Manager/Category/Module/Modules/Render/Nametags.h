#pragma once
#include "../../Module.h"

class Nametags : public Module {
public:
	int ctxFrames = 0;
public:
	Nametags(Manager* mgr) : Module(mgr->categories[CategoryType::RENDER], "Nametags") {

		registerEvent<RenderCtxEvent>([&](RenderCtxEvent* args) {

			ctxFrames++;

			if (ctxFrames < 3)
				return;
			else
				ctxFrames = 0;

			auto ctx = args->ctx;
			auto instance = ctx->instance;
			auto player = instance->getPlayer();
			auto font = (instance->getMcGame() ? instance->getMcGame()->mcFont : nullptr);

			if (player && font) {

				auto I = 0;
				auto fontSize = 1.f;
				auto myPos = *player->getPos();

				forEachEntity([&](Actor* entity, bool isRegular) {

					if (!isRegular || entity->getEntityTypeId() != ActorType::player || entity->runtimeId == player->runtimeId)
						return;
					
					auto pos = *entity->getPos();
					auto dist = pos.dist(myPos);

					if (dist >= 100.f || I >= 20)
						return;

					auto username = Utils::sanitize(entity->username);

					if (username.length() <= 0)
						username = Utils::sanitize(entity->getNameTag());

					if (username.length() <= 0 || Utils::toLower(username) == "name")
						return;

					auto text = username.rfind("\n") != std::string::npos ? Utils::splitStringBy(username, "\n").front() : username;

					text += std::string(" [" + std::to_string(entity->getHealth()) + "]");
					auto len = ctx->getTextLength(font, &text, fontSize, false);
					auto screenPos = args->ctx->gameToScreenPos(entity->renderPosition.add(0.f, 1.f, 0.f));

					if (screenPos.x <= 0 && screenPos.y <= 0)
						return;

					auto textPos = screenPos.sub(Vec2<float>(len / 2.f, 0.f));
					auto textRect = Rect(textPos.x - 2.f, textPos.y - 2.f, (textPos.x + 2.f) + len, (textPos.y + 2.f) + (fontSize * 10.f));

					args->ctx->fillRectangle(textRect, Color(12.f, 12.f, 12.f, 0.2f));
					args->ctx->drawText(font, text, textPos, Color(255.f, 255.f, 255.f), fontSize);
					args->ctx->flushText(0.f);
					I++;

				}, [&](Actor* first, Actor* second){
					return first->getPos()->dist(myPos) < second->getPos()->dist(myPos);
				});

			};

		});

	};
};