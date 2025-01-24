#pragma once

#include <type_traits>
#include <unordered_map>
#include "Liquid.h"
#include "GameObject.h"

template<float staticCapacity>
class LiquidContainer {
	/*static_assert(std::is_base_of<GameObject, LiquidContainer>::value, 
		"LiquidContainer must be used only with GameObject-derived classes!");*/
	LiquidContainer() {}

	int getMaxCapacity() {
		return staticCapacity;
	}
	
private:
	std::unordered_map<Liquid, float> mixture;
	float _currentValue;
};

template <>
class LiquidContainer<0.0f> {
	/*static_assert(std::is_base_of<GameObject, LiquidContainer>::value,
		"LiquidContainer must be used only with GameObject-derived classes!");*/

	LiquidContainer(float capacity) : _maxCapacity(capacity), _currentValue(0) {}

	float getCurrentValue() {

	}

private:
	std::unordered_map<Liquid, float> mixture;
	float _maxCapacity;
	float _currentValue;
};