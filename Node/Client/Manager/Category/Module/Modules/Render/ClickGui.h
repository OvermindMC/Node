#pragma once
#include "../../Module.h"

class ClickGui : public Module {
public:
	bool setWindow = false;
public:
	int currCategory = 0;
public:
	ClickGui(Manager* mgr) : Module(mgr->categories[CategoryType::RENDER], "ClickGui", "Interact with Modules via Mouse", VK_INSERT) {

		registerEvent<ImGuiEvent>([&](ImGuiEvent* args) {

			if (!setWindow) {

				auto displaySize = ImGui::GetIO().DisplaySize;

				ImGui::SetNextWindowSize(ImVec2(displaySize.x / 2.f, displaySize.y / 2.f));
				setWindow = true;

			};
			
			auto mgr = this->category->manager;
			auto categories = std::vector<std::string>();

			for (auto [type, category] : mgr->categories)
				categories.push_back(category->getName());

			ImVec4 window_color = ImGui::GetStyle().Colors[ImGuiCol_WindowBg];
			window_color.w = 0.7f;

			ImGui::PushStyleColor(ImGuiCol_WindowBg, window_color);

			if (ImGui::Begin("ClickGui", NULL, ImGuiWindowFlags_NoCollapse || ImGuiWindowFlags_NoTitleBar)) {

				if (ImGui::BeginChild("Categories", ImVec2(120.f, 0.f), true, ImGuiWindowFlags_NoScrollWithMouse)) {

					for (auto I = 0; I < categories.size(); I++) {

						auto c = categories[I];

						if (ImGui::Button(c.c_str(), ImVec2(100.f, 30.f))) {

							currCategory = (I + 1);

						};

					};

					ImGui::EndChild();

				}; ImGui::SameLine();

				if (ImGui::BeginChild("Modules", ImVec2(ImGui::GetWindowWidth() - 110.f, 0.f), true, ImGuiWindowFlags_NoScrollWithMouse)) {

					auto category = mgr->categories.find(reinterpret_cast<CategoryType&>(currCategory));
					auto modules = (category != mgr->categories.end() ? category->second->modules : std::vector<Module*>());

					for (auto mod : modules) {

						if (ImGui::Button(mod->name.c_str(), ImVec2(ImGui::GetWindowWidth() - 50.f, 30.f))) {

							mod->isEnabled = !mod->isEnabled;

						};

					};

					ImGui::EndChild();

				};
				
				ImGui::End();

			};

			ImGui::PopStyleColor();

		});

	};
};