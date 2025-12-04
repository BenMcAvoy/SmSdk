#pragma once

#include "SmSdk/Util/Memory.hpp"

#include <cstddef>
#include <cstdint>

template <typename T, std::uintptr_t uStaticOffset>
class StaticVariable
{
public:
	StaticVariable() = default;

	StaticVariable(const T& val)
	{
		Memory::WriteMemory<T>(uStaticOffset, val);
	}

	inline void operator=(const T& val) noexcept
	{
		Memory::WriteMemory<T>(uStaticOffset, val);
	}

	//Be careful when writing data to the pointer, the data might be protected
	inline const T* operator&() noexcept
	{
		return Memory::ReadPtr<T>(uStaticOffset);
	}

	inline operator T()
	{
		return *Memory::ReadPtr<T>(uStaticOffset);
	}
};