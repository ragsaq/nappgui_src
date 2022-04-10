#pragma once

#include "nappgui.h"

class NappString
{
protected:
	String* handle{ nullptr };

public:
	NappString() = default;
	explicit NappString(String* handle_) : handle(handle_) {}
	~NappString()
	{
		if (handle)
			str_destroy(&handle);
	}

	NappString(const NappString&) = delete;
	NappString& operator=(const NappString&) = delete;
	NappString(NappString&&) = default;
	NappString& operator=(NappString&&) = default;

	operator String*() const { return handle; }
	operator const char_t*() const { return tc(handle); }

	auto Handle() const { return handle; }

	template<typename... Args>
	static NappString printf(const char_t* format, Args... args)
	{
		return NappString(str_printf(format, args...));
	}
};
