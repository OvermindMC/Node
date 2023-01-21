#pragma once
#include "../../Module.h"

class TestMod : public Module {
public:
	TestMod(Manager* mgr) : Module(mgr->categories[CategoryType::MISC], "TestMod") {};
};