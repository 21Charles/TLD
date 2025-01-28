#pragma once

#include "Engine.h"

class DieselEngine : public Engine {
public:
	virtual inline Fluid* Fuel() const noexcept override {
		return FluidRegistry::getInstance()->getFluid("Diesel");
	}

	DieselEngine(glm::vec3 position, glm::vec3 scale, glm::quat rotation) :
		Engine(position, scale, rotation) {
	}
};