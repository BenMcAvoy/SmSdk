#pragma once

#include "SmSdk/config.hpp"

#if defined(SMSDK_ENABLE_BOOST)
#include <boost/uuid/uuid.hpp>
#else
namespace boost
{
namespace uuids
{
class uuid
{
public:
	typedef uint8_t value_type;
    typedef uint8_t& reference;
    typedef uint8_t const& const_reference;
    typedef uint8_t* iterator;
    typedef uint8_t const* const_iterator;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;

    static constexpr boost::uuids::uuid::size_type static_size()
	{
		return 16;
    }

	boost::uuids::uuid::iterator begin();
    boost::uuids::uuid::iterator end();
    boost::uuids::uuid::const_iterator begin() const;
    boost::uuids::uuid::const_iterator end() const;

    boost::uuids::uuid::size_type size() const;

    bool is_nil() const;
    
    enum variant_type {
        variant_ncs,       // NCS backward compatibility
        variant_rfc_4122,  // defined in RFC 4122 document
        variant_microsoft, // Microsoft Corporation backward compatibility
        variant_future     // future definition
    };
	boost::uuids::uuid::variant_type variant() const;

    enum version_type {
        version_unknown = -1,
        version_time_based = 1,
        version_dce_security = 2,
        version_name_based_md5 = 3,
        version_random_number_based = 4,
        version_name_based_sha1 = 5
    };
	boost::uuids::uuid::version_type version() const;

    // Swap function
	void swap(boost::uuids::uuid& rhs);

    value_type data[16];
};
bool operator==(uuid const& lhs, uuid const& rhs);
bool operator!=(uuid const& lhs, uuid const& rhs);
bool operator<(uuid const& lhs, uuid const& rhs);
bool operator>(uuid const& lhs, uuid const& rhs);
bool operator<=(uuid const& lhs, uuid const& rhs);
bool operator>=(uuid const& lhs, uuid const& rhs);

void swap(uuid& lhs, uuid& rhs);

std::size_t hash_value(uuid const& u);
}
}

#endif