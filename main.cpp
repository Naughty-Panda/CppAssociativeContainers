//////////////////////////////////////////
//	C++ STL Associative Containers
//	Naughty Panda @ 2021
//////////////////////////////////////////

#include <iostream>
#include <sstream>
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

struct Message {

public:
	std::string _data{ "" };

	Message(const std::string& str) : _data(str) {}

	bool operator < (const Message& other) const { return _data.length() < other._data.length(); }
	friend std::ostream& operator << (std::ostream& ostr, const Message& message) { return ostr << message._data; }
};

void TextSort() {

	std::multiset<Message> result;

	// Receiving user input
	std::string sInput{ "" };
	std::getline(std::cin, sInput);

	std::string token;
	std::string delimiter{ ". " };
	size_t start = 0U;
	size_t end = sInput.find(delimiter);

	//	 Iterating tokens
	while (end != std::string::npos) {

		end = sInput.find(delimiter);
		token = sInput.substr(start, end - start);

		result.emplace(token);

		end = sInput.find(delimiter, start);
		sInput.erase(start, end + delimiter.size());
	}

	// Printing results
	std::cout << "\nEntered messages:\n";
	std::copy(result.begin(), result.end(), std::ostream_iterator<Message>(std::cout, "\n"));
}


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

	TextSort();

	return 0;
}
