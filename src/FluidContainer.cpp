#include "FluidContainer.h"

template<float capacity>
void FluidContainer<capacity>::addFluid(Fluid *liquidPtr, float amount) {
	_currentAmount += amount; 
	if (_volumes.find(liquidPtr) != _volumes.end()) {
		_volumes[liquidPtr] += amount;
	}
	else {
		_volumes[liquiPtr] = amount;
	}
}

template<float capacity>
void FluidContainer<capacity>::addMixture(std::unordered_map<Fluid*, float>) {
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
void FluidContainer<capacity>::pourAmount(float amount) {
	float perFluid = amount / _volumes.size();
	for (auto& i : _volumes) {
		i.second -= perFluid;
	}
}

template<float capacity>
void FluidContainer<capacity>::moveToOther(FluidContainer* other, float amount) {
	float perFluid = amount / _volumes.size();
	std::unordered_map<Liquid*, float> toMove;

	for (const auto& i : _volumes) {
		toMove[i.first] = i.second - amount;
	}
	pourAmount(amount);
	other->addMixture(toMove);
}

template<float capacity>
inline void FluidContainer<capacity>::removeFluid(Fluid* liquidPtr) {
	_mixtureProportions.remove(LiquidPtr);
}



template<float capacity>
inline float FluidContainer<capacity>::getFluidData(Fluid* liquidPtr) const {
	return _mixtureProportion[liquidPtr];
}

template<float capacity>
inline std::unordered_map<Fluid*, float> FluidContainer<capacity>::getVolumes() const {
	return _mixtuteProportion;
}

template<float capacity>
inline float FluidContainer<capacity>::getMaxCapacity() const {
	return capacity;
}

template<float capacity>
inline float FluidContainer<capacity>::getCurrentAmount() const {
	return _currentAmount;
}

template<float capacity>
LiquidContainer<capacity>::FluidContainer() : _currentAmount(0.0f) {}

template<float capacity>
LiquidContainer<capacity>::FluidContainer(std::unordered_map<Fluid*, float> startingMixture, float amount) :
	_currentAmount(amount), _volumes(startingMixture) { }