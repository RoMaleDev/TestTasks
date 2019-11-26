#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <cctype>
#include <iterator>
#include <list>
#include <map>

using namespace std;

vector<string> combine_cities(vector<string> available_cities);
vector<string> read_available_cities();
int write_to_file(vector<string> cities_list);

int main()
{
	vector<string> available_cities = read_available_cities();

	vector<string> cities_list = combine_cities(available_cities); // TODO implement this function

	return write_to_file(cities_list);
}

vector<string> combine_cities(vector<string> available_cities) {
	// TODO replace with your solution!

	std::map<std::int16_t, std::size_t> countOfFirstLastLetter;
	std::multimap<std::int8_t, std::string> firstLastEqualLetter;
	std::map<std::int8_t, std::size_t> sizeOfFirstLastEqualLetter;
	using pair_typeInt16Size = decltype(countOfFirstLastLetter)::value_type;
	using pair_typeInt8Size = decltype(sizeOfFirstLastEqualLetter)::value_type;

	std::list<std::string> temp;




	std::sort(available_cities.begin(), available_cities.end(), [](const std::string& a, const std::string& b) {
		return a.size() > b.size();
		});

	for (std::vector<std::string>::const_iterator c_it = available_cities.cbegin(); c_it != available_cities.cend(); ++c_it) {
		std::int16_t t;
		void* p = &t;

		if ((*c_it).front() == std::toupper((*c_it).back())) {
			firstLastEqualLetter.emplace((*c_it).front(), *c_it);
			sizeOfFirstLastEqualLetter[(*c_it).front()] += (*c_it).size();
		}
		else {
			*(static_cast<int8_t*>(p) + 1) = *(*c_it).cbegin();
			*(static_cast<int8_t*>(p)) = *(*c_it).crbegin();
			countOfFirstLastLetter[t] += (*c_it).size();
			temp.push_back(*c_it);
		}
	}

	available_cities.clear();
	std::list<std::string>::iterator it = temp.begin();
	std::list<std::string>::iterator firstFaundWord;
	std::list<std::string>::iterator secondFoundWord;
	std::int8_t currentLastLetter = *(*it).crbegin();
	std::int8_t nextFirsLetter;
	std::int16_t neededFirstLastLetter; void *pointer = &neededFirstLastLetter;
	std::int8_t* ptrLastLetter = static_cast<int8_t*>(pointer);  
	std::int8_t* ptrFirstLetter = static_cast<int8_t*>(pointer) + 1;

	auto faundMaxSize = std::max_element(sizeOfFirstLastEqualLetter.begin(), sizeOfFirstLastEqualLetter.end(), [](const pair_typeInt8Size& p1, const pair_typeInt8Size& p2) {
		return p1.second < p2.second;
		});

	auto sizeBefore = sizeOfFirstLastEqualLetter.find((*it).front());
	auto sizeAfter = sizeOfFirstLastEqualLetter.find(std::toupper((*it).back()));

	std::size_t secondFaundMaxSize = (sizeBefore != sizeOfFirstLastEqualLetter.end() ? (*sizeBefore).second : 0) + (*it).size() + (sizeAfter != sizeOfFirstLastEqualLetter.end() ? (*sizeAfter).second : 0);

	if (faundMaxSize != sizeOfFirstLastEqualLetter.end() && (*faundMaxSize).second > secondFaundMaxSize ) {
		auto faundWord = it; std::advance(faundWord, 1);

		faundWord = std::find_if(temp.begin(), temp.end(), [&faundMaxSize](const string& a) {
			return (*faundMaxSize).first == *a.cbegin();
			});
		if (faundWord != temp.end()) {
			temp.insert(it, *faundWord);
			temp.erase(faundWord);
			it = temp.begin();
			auto iStart = firstLastEqualLetter.lower_bound(std::toupper((*it).front()));
			auto iFinish = firstLastEqualLetter.upper_bound(std::toupper((*it).front()));
			for (; iStart != iFinish; std::advance(iStart, 1)) {
				available_cities.push_back((*iStart).second);
			}
			firstLastEqualLetter.erase((*it).front());
			sizeOfFirstLastEqualLetter.erase((*it).front());
			currentLastLetter = (*it).back();
		}
	}

	do {
		secondFoundWord = it; std::advance(secondFoundWord, 1);
		if ((temp.front()).back() != std::tolower((*secondFoundWord).front())) {
			*(static_cast<int8_t*>(ptrFirstLetter)) = std::toupper(currentLastLetter);
			
			auto foundMaxCountOfFLLetter = std::max_element(countOfFirstLastLetter.begin(), countOfFirstLastLetter.end(), [currentLastLetter, &countOfFirstLastLetter](const pair_typeInt16Size& p1, const pair_typeInt16Size& p2) {
				auto p1First = p1.first; void* ptrP1First = &p1First;
				auto p2First = p2.first; void* ptrP2First = &p2First;
				auto currentLL = std::toupper(currentLastLetter);

				if (currentLL == *(static_cast<int8_t*>(ptrP1First) + 1) && currentLL == *(static_cast<int8_t*>(ptrP2First) + 1)) {
					auto countFirstPair = 0;
					auto countSecondPair = 0;

					for (const auto &i : countOfFirstLastLetter) {
						auto iF = i.first; void* ptrIF = &iF;

						if (std::toupper(*(static_cast<int8_t*>(ptrP1First))) == *(static_cast<int8_t*>(ptrIF) + 1)) {
							countFirstPair += i.second;
						}
						if (std::toupper(*(static_cast<int8_t*>(ptrP2First))) == *(static_cast<int8_t*>(ptrIF) + 1)) {
							countSecondPair += i.second;
						}
					}

					return countFirstPair < countSecondPair;
				}
				return  currentLL == *(static_cast<int8_t*>(ptrP2First) + 1);
				});

			auto currentLL = std::toupper(currentLastLetter);
			neededFirstLastLetter = (*foundMaxCountOfFLLetter).first;
				
			if (foundMaxCountOfFLLetter != countOfFirstLastLetter.end() && *ptrFirstLetter == currentLL) {


				firstFaundWord = it; std::advance(firstFaundWord, 1);
				firstFaundWord = std::find_if(firstFaundWord, temp.end(), [&nextFirsLetter, &ptrLastLetter](const string& a) {
					nextFirsLetter = *a.cbegin();
					return std::toupper(*ptrLastLetter) == nextFirsLetter;
					});
			} else {
				firstFaundWord = temp.end();
			}
			if (firstFaundWord != temp.end()) {
				auto i = it;  std::advance(i, 1);

				temp.insert(i, *firstFaundWord);
				temp.erase(firstFaundWord);

				secondFoundWord = it; std::advance(secondFoundWord, 2);

				secondFoundWord = std::find_if(secondFoundWord, temp.end(), [currentLastLetter, nextFirsLetter](const string& a) {
					return *a.cbegin() == std::toupper(currentLastLetter) && *a.crbegin() == std::tolower(nextFirsLetter);
					});
			} else {
				auto i = temp.begin(); std::advance(i, 1);

				i = std::find_if(i, temp.end(), [&it, &available_cities](const string& a) {
					return *a.begin() == std::toupper(*(*available_cities.rbegin()).rbegin()) && !(a.front() == (*it).front() && a.back() == (*it).back());
					});

				if (i != temp.end()) {
					temp.push_front(*i);
					temp.erase(i);
					it = temp.begin();
					currentLastLetter /*= *static_cast<int8_t*>(ptrLastLetter)*/ = *(*it).rbegin();
					continue;
				}
				else {
					if (*(*temp.begin()).begin() == std::toupper(*(*available_cities.rbegin()).rbegin())) {
						available_cities.push_back(temp.front());
					}
					break; //it = i;
				}
			}
		}

		available_cities.push_back(*it);

		auto isPresent = sizeOfFirstLastEqualLetter.find(std::toupper((*it).back()));
		
		if ( isPresent != sizeOfFirstLastEqualLetter.end() ) {
			auto iStart = firstLastEqualLetter.lower_bound(std::toupper((*it).back()));
			auto iFinish = firstLastEqualLetter.upper_bound(std::toupper((*it).back()));
			for (; iStart != iFinish; std::advance(iStart, 1)) {
				available_cities.push_back((*iStart).second);
			}
			firstLastEqualLetter.erase(std::toupper((*it).back()));
			sizeOfFirstLastEqualLetter.erase(std::toupper((*it).back()));
		}
		
		available_cities.push_back(*secondFoundWord);

		*static_cast<int8_t*>(ptrFirstLetter) = *(*it).begin();
		*static_cast<int8_t*>(ptrLastLetter) = *(*it).rbegin();
		countOfFirstLastLetter[neededFirstLastLetter] -= (*it).size();
		if ( countOfFirstLastLetter[neededFirstLastLetter] == 0 ) {
			countOfFirstLastLetter.erase(neededFirstLastLetter);
		}

		*static_cast<int8_t*>(ptrFirstLetter) = *(*secondFoundWord).begin();
		*static_cast<int8_t*>(ptrLastLetter) = *(*secondFoundWord).rbegin();
		countOfFirstLastLetter[neededFirstLastLetter] -= (*secondFoundWord).size();
		if ( countOfFirstLastLetter[neededFirstLastLetter] == 0 ) {
			countOfFirstLastLetter.erase(neededFirstLastLetter);
		}

		temp.erase(it);
		temp.erase(secondFoundWord);
		it = temp.begin();

		if ( (*it).front() != std::toupper((available_cities.back()).back()) ) {
			std::advance(it, 1);
			it = std::find_if(it, temp.end(), [&available_cities](const string& a) {
					return std::toupper((available_cities.back()).back()) == a.front();
				});
			if ( it != temp.end() ) {
				temp.insert(temp.begin(), *it);
				temp.erase(it);
				it = temp.begin();
			} else break;
		}
		
		if ( sizeOfFirstLastEqualLetter.size() ) {
			faundMaxSize = std::max_element(sizeOfFirstLastEqualLetter.begin(), sizeOfFirstLastEqualLetter.end(), [](const pair_typeInt8Size& p1, const pair_typeInt8Size& p2) {
				return p1.second < p2.second;
				});

			auto sizeAfter = sizeOfFirstLastEqualLetter.find(std::toupper((*it).back()));

			secondFaundMaxSize = (*it).size() + ( sizeAfter != sizeOfFirstLastEqualLetter.end() ? (*sizeAfter).second : 0 );

			if (faundMaxSize != sizeOfFirstLastEqualLetter.end() && (*faundMaxSize).second > secondFaundMaxSize) {
				auto faundWord = it; /* std::advance(faundWord, 1);*/

				faundWord = std::find_if(temp.begin(), temp.end(), [&available_cities, &faundMaxSize](const string& a) {
					return (*faundMaxSize).first == std::toupper(a.back()) && available_cities.back().back() == std::tolower(a.front());
					});
				if (faundWord != temp.end()) {
					temp.insert(it, *faundWord);
					temp.erase(faundWord);
					it = temp.begin();
				}
			}
		}
		currentLastLetter = *(*it).rbegin();
	} while (it != temp.end());
	return available_cities /*vector<string>()*/;
}

vector<string> read_available_cities() {
	string line;
	ifstream input_file("input.txt");
	vector<string> available_cities;
	while (getline(input_file, line))
	{
		available_cities.push_back(line);
	}
	input_file.close();

	return available_cities;
}

int write_to_file(vector<string> cities_list) {
	ofstream output_file("./output.txt");
	ostream_iterator<string> output_iterator(output_file, "\n");
	copy(cities_list.begin(), cities_list.end(), output_iterator);

	return 0;
}
