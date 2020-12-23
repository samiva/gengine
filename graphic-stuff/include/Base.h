#ifndef __BASE_h__
#define __BASE_h__
#include <memory>

template<typename T>
using ScopedPtr = std::unique_ptr<T>;

template<typename T, typename ...Args>
constexpr ScopedPtr<T> CreateScopedPtr(Args&&... args) {
	return std::make_unique<T>(std::forward<Args>(args)...);
}

template <typename T>
using SharedPtr = std::shared_ptr<T>;

template <typename T, typename... Args>
constexpr SharedPtr<T> CreateSharedPtr(Args&&... args) {
	return std::make_shared<T>(std::forward<Args>(args)...);
}

#endif // __BASE_h__
