#pragma once

#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <sstream>
#include <fstream>
#include <functional>

#ifdef PLATFORM_WINDOWS
	#ifdef BUILD_DLL
		#define	H_API __declspec(dllexport)
	#else 
		#define H_API __declspec(dllimport)
	#endif
#endif

#define BIND_EVENT_FUNCTION(func) [this](auto&&... args) -> decltype(auto) { return this->func(std::forward<decltype(args)>(args)...); }

namespace Hydrogen {
	template <typename t>
	using Ref = std::shared_ptr<t>;
	template<typename T, typename ... Args>
	constexpr Ref<T> createRef(Args&& ... args) {
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> createScope(Args&& ... args) {
		return std::make_unique<T>(std::forward<Args>(args)...);
	}
}