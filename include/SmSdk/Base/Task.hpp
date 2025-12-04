#pragma once

#include "SmSdk/unreferenced_params.hpp"

class Task
{
public:
	virtual ~Task() {}
	virtual std::int64_t update(float fDeltaTime)
	{
		SMSDK_UNREF(fDeltaTime);
		return 0;
	}
}; // Size: 0x8

static_assert(sizeof(Task) == 0x8, "Task: Incorrect Size");