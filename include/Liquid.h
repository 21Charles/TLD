#pragma once

#include <string>
#include "Engine.h"

class Liquid {
public:
	virtual std::string getName()		const noexcept = 0;
	virtual float coolingLevel()		const noexcept = 0;
	virtual float weightPerLiter()		const noexcept = 0;
	virtual void onDrank()				const noexcept = 0;
	virtual void onCombusted(Engine*)	const noexcept = 0;
protected:
	Liquid() {}
	virtual ~Liquid() = default;
};