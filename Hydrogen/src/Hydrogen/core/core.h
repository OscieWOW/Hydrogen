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

	template<typename T>
	class Handle {
		public:
			Handle() = default;
			Handle(const Ref<T>& shared):m_ptr(shared) {}
			Handle(const std::weak_ptr<T>& weak):m_ptr(weak) {}

			Handle& operator=(const Ref<T>& shared) {
				m_ptr = shared;
				return *this;
			}
			Handle& operator=(const std::weak_ptr<T>& weak) {
				m_ptr = weak;
				return *this;
			}
			T* operator->() const {
				auto shared = m_ptr.lock();
				//std::cout << shared << std::endl;
				return shared ? shared.get() : nullptr;
			}
			T& operator*() const {
				return *m_ptr.lock();
			}
			explicit operator bool() const {
				return !m_ptr.expired();
			}
			std::shared_ptr<T> lock() const {
				return m_ptr.lock();
			}

		private:
			std::weak_ptr<T> m_ptr;
	};

	class File {
		public:
			File(std::string source, std::ios_base::openmode mode) {
				file.open(source, mode);
				if(!file.is_open()) {
					std::cout << "[CORE] FILE NOT VALID" << std::endl;
					exit(-1);
				}
			}

			~File(){
				file.close();
			}

			void write(const std::string& msg) {
				file.write(msg.c_str(),msg.size());
			}
			std::string get(int count) {
				std::string buffer(count, '\0');
				file.read(&buffer[0], count);
				buffer.resize(file.gcount());
				return buffer;
			}
			std::string getLine() {
				std::string buffer;
				std::getline(file, buffer);
				return buffer;
			}
			std::string readAll() {
				file.seekg(0, std::ios::beg);
				std::string contents;
				contents.assign((std::istreambuf_iterator<char>(file)),
								std::istreambuf_iterator<char>());
				return contents;
			}

		private:
			std::fstream file;
			File(const File&) = delete;
			File& operator=(const File&) = delete;
	};
}