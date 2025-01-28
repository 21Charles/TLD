#pragma once

#include "Fluid.h"
#include <string>
#include <unordered_map>
#include "Fluids/Water.h"
#include "Fluids/Gasoline.h"

class FluidRegistry {
public:
	inline void registerFluid(const std::string&, Fluid*);

	Fluid* getFluid(const std::string&) const;

	static FluidRegistry* getInstance();

	FluidRegistry(const FluidRegistry &other) = delete;
	void operator=(const FluidRegistry& other) = delete;

	void initializeRegistry() {
		registerFluid(Water::getInstance()->getName(), Water::getInstance());
		registerFluid(Gasoline::getInstance()->getName(), Gasoline::getInstance());
	}
	
	~FluidRegistry() {
		delete Instance;
	}

private:
	std::unordered_map<std::string, Fluid*> _registry;
	static FluidRegistry* Instance;
	FluidRegistry() {}
};

