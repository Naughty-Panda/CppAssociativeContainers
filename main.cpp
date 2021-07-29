//////////////////////////////////////////
//	C++ STL Associative Containers
//	Naughty Panda @ 2021
//////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <list>
#include <array>
#include <string_view>

//////////////////////////////////////////
// 5.1
//////////////////////////////////////////

template <class T>
void PrintUnique(const T& begin, const T& end) {

	std::set<std::string_view> result;
	std::for_each(begin, end, [&](const auto& i) { result.insert(i); });

	// Printing results
	std::copy(std::begin(result), std::end(result), std::ostream_iterator<std::string_view>(std::cout, " "));
	std::cout << '\n';
}

//////////////////////////////////////////
// 5.2
//////////////////////////////////////////


int main() {

	//////////////////////////////////////////
	// 5.1
	//////////////////////////////////////////

	std::array<std::string, 10> arr{ "begin", "end", "hello", "world", "array", "string", "end", "world" };
	std::vector<std::string> vec{ "begin", "end", "hello", "world", "array", "string", "end", "world" };
	std::list<std::string> list{ "begin", "end", "hello", "world", "array", "string", "end", "world" };

	std::cout << "Array of strings: ";
	PrintUnique(std::begin(arr), std::end(arr));
	std::cout << "Vector of strings: ";
	PrintUnique(std::begin(vec), std::end(vec));
	std::cout << "List of strings: ";
	PrintUnique(std::begin(list), std::end(list));

	//////////////////////////////////////////
	// 5.2
	//////////////////////////////////////////

	return 0;
}
