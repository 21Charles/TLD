#include "FluidRegistry.h"

inline void FluidRegistry::registerFluid(const std::string& name, Fluid* liquidPointer) {
	_registry[name] = liquidPointer;
}

Fluid* FluidRegistry::getFluid(const std::string& name) const {
	auto it = _registry.find(name);
	if (it == _registry.end()) {
		return nullptr;
	}
	return it->second;
}

FluidRegistry* FluidRegistry::getInstance() {
	if (Instance == nullptr) {
		Instance = new FluidRegistry();
	}
	return Instance;
}