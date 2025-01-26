#pragma once

#include "Liquid.h"
#include <string>
#include <unordered_map>
#include "Liquid/Water.h"
#include "Liquid/Gasoline.h"

class LiquidRegistry {
public:

	inline void registerLiquid(const std::string&, Liquid*);

	Liquid* getLiquid(const std::string&) const;

	static LiquidRegistry* getInstance();

	LiquidRegistry(const LiquidRegistry &other) = delete;
	void operator=(const LiquidRegistry& other) = delete;

	void initializeRegistry() {
		registerLiquid(Water::getInstance()->getName(), Water::getInstance());
		registerLiquid(Gasoline::getInstance()->getName(), Gasoline::getInstance());
	}
	
	~LiquidRegistry() {
		delete Instance;
	}

private:
	std::unordered_map<std::string, Liquid*> _registry;
	static LiquidRegistry* Instance;
	LiquidRegistry() {}
};


inline void LiquidRegistry::registerLiquid(const std::string& name, Liquid* liquidPointer) {
	_registry[name] = liquidPointer;
}

Liquid* LiquidRegistry::getLiquid(const std::string &name) const {
	auto it = _registry.find(name);
	if (it == _registry.end()) {
		return nullptr;
	}
	return it->second;
}

LiquidRegistry* LiquidRegistry::getInstance() {
	if (Instance == nullptr) {
		Instance = new LiquidRegistry();
	}
	return Instance;
}