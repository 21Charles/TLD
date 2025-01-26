#pragma once

#include <type_traits>
#include <unordered_map>
#include "Liquid.h"
#include "GameObject.h"
#include <string>
#include <typeinfo>

template<float capacity>
class LiquidContainer {
public:
	// ADDERS
	
	void addLiquid(Liquid*, float);
	void addMixture(std::unordered_map<Liquid*, float>);

	// REMOVERS

	void pourAmount(float);
	void moveToOther(LiquidContainer* other, float);
	inline void removeLiquid(Liquid*);
	
	// GETTERS
	
	inline float getLiquidData(Liquid*) const;
	inline std::unordered_map<Liquid*, float> getMixtureProportion() const;
	inline float getMaxCapacity() const;
	inline float getCurrentAmount() const;

	LiquidContainer();
	LiquidContainer(std::unordered_map<Liquid*, float> startingMixture, float amount);
private:
	float _currentAmount;
	std::unordered_map<Liquid*, float> _volumes;
};
