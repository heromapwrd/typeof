#ifndef __TYPEOF_H_
#define __TYPEOF_H_
#include <typeinfo.h>

#define __AUTO_REGISTER__

template <const std::type_info& type_id>
struct TypeID{};

#define type_id(...) TypeID<typeid(__VA_ARGS__)>

#ifdef __AUTO_REGISTER__

struct empty_t {};

template<typename ID, typename T = empty_t>
struct Extract;

template<typename ID>
struct Extract<ID, empty_t>
{
	template <bool>
	struct id2type;
};

template<typename ID, typename T>
struct Extract : Extract<ID, empty_t>
{
	template <>
	struct id2type<true> { typedef T type_t; };
};

#define REGISTER_TYPE(type)

#define type_extract(...) \
    Extract<type_id(__VA_ARGS__) >::id2type<true>::type_t

template<typename T, typename ID>
struct Register : Extract<ID, T>
{
	typedef typename id2type<true>::type_t type_t;
};

template <typename T>
struct Encode
{
	typedef T* enc_type_t;
	typedef Register<enc_type_t, type_id(enc_type_t)> reg_type;
	typedef typename reg_type::type_t type_t;
};

#else

template<typename ID>
struct Extract;

#define REGISTER_TYPE(type)	\
	template<>	\
	struct Extract<type_id(type*)> { typedef type* type_t;};

#define type_extract(...) \
	Extract<type_id(__VA_ARGS__)>::type_t

template<typename T>
struct Encode { typedef T* type_t; };

#endif


template<typename T>
typename Encode<T>::type_t encode(const T&);
template<typename T>
typename Encode<T>::type_t encode(T&);

template <typename T>
struct Decode;
template<typename T>
struct Decode<T*> { typedef T type_t; };	

#define type_of(...) \
	Decode<type_extract(encode((__VA_ARGS__)))>::type_t

#endif
