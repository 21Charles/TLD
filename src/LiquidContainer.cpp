#include "LiquidContainer.h"

template<float capacity>
void LiquidContainer<capacity>::addLiquid(Liquid *liquidPtr, float amount) {
	_currentAmount += amount; 
	if (_volumes.find(liquidPtr) != _volumes.end()) {
		_volumes[liquidPtr] += amount;
	}
	else {
		_volumes[liquiPtr] = amount;
	}
}

template<float capacity>
void LiquidContainer<capacity>::addMixture(std::unordered_map<Liquid*, float>) {
	for (const auto& i : _volumes) {
		_currentAmount = i.second;
		if (_volumes.find(i.first) != _volumes.end()) {
			_volumes[i.first] += i.second;
		}
		else {
			_volumes[i.first] = i.second;
		}
	}
}

template<float capacity>
void LiquidContainer<capacity>::pourAmount(float amount) {
	float perFluid = amount / _volumes.size();
	for (auto& i : _volumes) {
		i.second -= perFluid;
	}
}

template<float capacity>
void LiquidContainer<capacity>::moveToOther(LiquidContainer* other, float amount) {
	float perFluid = amount / _volumes.size();
	std::unordered_map<Liquid*, float> toMove;

	for (const auto& i : _volumes) {
		toMove[i.first] = i.second - amount;
	}
	pourAmount(amount);
	other->addMixture(toMove);
}

template<float capacity>
inline void LiquidContainer<capacity>::removeLiquid(Liquid* liquidPtr) {
	_mixtureProportions.remove(LiquidPtr);
}



template<float capacity>
inline float LiquidContainer<capacity>::getLiquidData(Liquid* liquidPtr) const {
	return _mixtureProportion[liquidPtr];
}

template<float capacity>
inline std::unordered_map<Liquid*, float> LiquidContainer<capacity>::getMixtureProportion() const {
	return _mixtuteProportion;
}

template<float capacity>
inline float LiquidContainer<capacity>::getMaxCapacity() const {
	return capacity;
}

template<float capacity>
inline float LiquidContainer<capacity>::getCurrentAmount() const {
	return _currentAmount;
}

template<float capacity>
LiquidContainer<capacity>::LiquidContainer() : _currentAmount(0.0f) {}

template<float capacity>
LiquidContainer<capacity>::LiquidContainer(std::unordered_map<Liquid*, float> startingMixture, float amount) :
	_currentAmount(amount), _volumes(startingMixture) { }