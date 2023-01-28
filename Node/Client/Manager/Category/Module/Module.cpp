#include "Module.h"

Module::Module(Category* c, std::string n) {
	this->category = c;
	this->name = n;

	this->category->modules.push_back(this);
};

auto Module::tick(void) -> void {

	if (this->wasEnabled != this->isEnabled) {

		this->wasEnabled = this->isEnabled;
		this->callEvent<ModuleEvent>(ModuleEvent{ this->isEnabled, false });
		
		
		ImGuiToastType type = ImGuiToastType_Success;
		ImGuiToast toast(type, 2500);

		toast.set_title(this->name.c_str());
		toast.set_content(this->isEnabled ? "Enabled" : "Disabled");

		ImGui::InsertNotification(toast);

	};

	if(this->isEnabled)
		this->callEvent<ModuleEvent>(ModuleEvent{ this->isEnabled, true });

};