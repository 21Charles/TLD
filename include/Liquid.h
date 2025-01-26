#pragma once

#include <string>

class Liquid {
public:
	virtual std::string getName() const = 0;
	virtual float coolingLevel() const = 0;
	virtual float weightPerLiter() const = 0;
	virtual void onDrank() const = 0;
	virtual void onCombusted() const = 0;
protected:
	Liquid() {}
	virtual ~Liquid() = default;
};