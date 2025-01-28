#pragma once

#include <type_traits>
#include <unordered_map>
#include "Fluid.h"
#include "GameObject.h"
#include <string>
#include <typeinfo>

template<float capacity>
class FluidContainer {
public:
	// ADDERS
	
	void addFluid(Fluid*, float);
	void addMixture(std::unordered_map<Fluid*, float>);

	// REMOVERS

	void pourAmount(float);
	void moveToOther(FluidContainer* other, float);
	inline void removeFluid(Fluid*);
	
	// GETTERS
	
	inline float getFluidData(Fluid*) const;
	inline std::unordered_map<Fluid*, float> getVolumes() const;
	inline float getMaxCapacity() const;
	inline float getCurrentAmount() const;

	FluidContainer();
	FluidContainer(std::unordered_map<Liquid*, float> startingMixture, float amount);
private:
	float _currentAmount;
	std::unordered_map<Liquid*, float> _volumes;
};
