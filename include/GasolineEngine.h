#pragma once

#include "Engine.h"

class GasolineEngine : public Engine {
public:
	virtual inline Fluid* Fuel() const noexcept override {
		return FluidRegistry::getInstance()->getFluid("Gasoline");
	}

	GasolineEngine(glm::vec3 position, glm::vec3 scale, glm::quat rotation) : 
		Engine(position, scale, rotation) {}
};