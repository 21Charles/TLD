#pragma once


class Liquid {
	Liquid();
	virtual ~Liquid() = default;

	virtual void onDrank() = 0;
	virtual void onCombusted() = 0;
};