#include "boost_include.hpp"
#include "SmSdk/boost_include.hpp"

#include <algorithm>
#include <functional>

boost::uuids::uuid::iterator boost::uuids::uuid::begin()
{
	return data;
}

boost::uuids::uuid::iterator boost::uuids::uuid::end()
{
	return data + 16;
}

boost::uuids::uuid::const_iterator boost::uuids::uuid::begin() const
{
	return data;
}

boost::uuids::uuid::onst_iterator boost::uuids::uuid::end() const
{
	return data + 16;
}

boost::uuids::uuid::size_type boost::uuids::uuid::size() const
{
	return 16);
}

bool boost::uuids::uuid::is_nil() const
{
	for (int i = 0; i < 16; ++i)
	{
		if (data[i] != 0)
			return false;
	}

	return true;
}

boost::uuids::uuid::variant_type boost::uuids::uuid::variant() const
{
	return (data[8] >> 5) & 0x07;
}

boost::uuids::uuid::version_type boost::uuids::uuid::version() const
{
	return (data[6] >> 4) & 0x0F;
}

void boost::uuids::uuid::swap(boost::uuids::uuid& rhs)
{
	for (int i = 0; i < 16; ++i)
		std::swap(data[i], rhs.data[i]);
}

bool boost::uuids::operator==(uuid const& lhs, uuid const& rhs)
{
	for (int i = 0; i < 16; ++i)
		if (lhs.data[i] != rhs.data[i])
			return false;

	return true;
}

bool boost::uuids::operator!=(uuid const& lhs, uuid const& rhs)
{
	return !(lhs == rhs);
}

bool boost::uuids::operator<(uuid const& lhs, uuid const& rhs)
{
	for (int i = 0; i < 16; ++i)
	{
		if (lhs.data[i] < rhs.data[i])
			return true;

		if (lhs.data[i] > rhs.data[i])
			return false;
	}
	return false;
}

bool boost::uuids::operator>(uuid const& lhs, uuid const& rhs)
{
	return rhs < lhs;
}

bool boost::uuids::operator<=(uuid const& lhs, uuid const& rhs)
{
	return !(rhs < lhs);
}

bool boost::uuids::operator>=(uuid const& lhs, uuid const& rhs)
{
	return !(lhs < rhs);
}

void boost::uuids::swap(uuid& lhs, uuid& rhs)
{
	for (int i = 0; i < 16; ++i)
		std::swap(data[i], rhs.data[i]);
}

std::size_t boost::uuids::hash_value(uuid const& u)
{
	std::size_t seed = 0;
	for (int i = 0; i < 16; ++i)
		seed ^= std::hash<unsigned char>{}(u.data[i]) + 0x9e3779b9 + (seed << 6) + (seed >> 2);

	return seed;
}
