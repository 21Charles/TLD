#include "LiquidRegistry.h"

inline void LiquidRegistry::registerLiquid(const std::string& name, Liquid* liquidPointer) {
	_registry[name] = liquidPointer;
}

Liquid* LiquidRegistry::getLiquid(const std::string& name) const {
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