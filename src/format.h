#ifndef FORMAT_H_GUARD_dkjaksdjsadksajdkjd
#define FORMAT_H_GUARD_dkjaksdjsadksajdkjd

#include <ostream>
#include <sstream>

template<typename T, typename U>
char const * format_consume(std::basic_ostream<T> & os, T const * str, U const & v1) {
	bool pending = false;
	auto pch = str;
	for( ; *pch ; ++pch ) {
		auto ch = *pch;
		if( pending ) {
			if( ch == '%' ) {
				os.put(ch);
				pending = false;
			} else {
				os << v1;
				++pch;
				break;
			}
		} else {
			if( ch == '%' ) {
				pending = true;
			} else {
				os.put(ch);
			}
		}
	}
	return pch;
}

template<typename T, typename U>
std::basic_ostream<T> & format(std::basic_ostream<T> & os, T const * str, U const & v1) {
	str = format_consume(os,str,v1);
	return os << str;
}

template<typename T, typename U>
std::basic_string<T> strformat(T const * str, U const & v1) {
	std::basic_stringstream<T> ss;
	format(ss,str,v1);
	return ss.str();
}

template<typename T, typename U, typename... V>
std::basic_ostream<T> & format(std::basic_ostream<T> & os, T const * str, U const & v1, V... rest) {
        str = format_consume(os,str,v1);
        return format(os,str,rest...);
}

template<typename T, typename U, typename... V>
std::basic_string<T> strformat(T const * str, U const & v1, V... rest) {
	std::basic_stringstream<T> ss;
	return format(ss,str,v1,rest...).str();
}

#endif
