#include <iostream>
#include <string>
#include "Utils.h"
using namespace std;


namespace sdds {
	Utils ut;

	int Utils::validSelection(int maxNum)
	{
		int selectNo{};
		bool done{};
		do {
			done = true;
			std::cin >> selectNo;
			if (std::cin.fail() || selectNo < 0 || selectNo > maxNum) {
				done = false;
				std::cout << "Invalid Selection, try again: ";
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
		} while (!done);
		return selectNo;
	}

	int Utils::strlen(const char* str) const
	{
		int len;
		for (len = 0; str[len]; len++);
		return len;
	}

	char* Utils::strcpy(char* des, const char* src) const
	{
		int i;
		for (i = 0; src[i]; i++) des[i] = src[i];
		des[i] = char(0);
		return des;
	}

	char* Utils::alcpy(const char* name)
	{
		char* tmp;
		tmp = new char[strlen(name) + 1];
		strcpy(tmp, name);
		return tmp;
	}
	char* Utils::dynread(std::istream& istr, char del)
	{
		char* tmp{};
		string sts;
		getline(istr, sts, del);
		if (istr) tmp = alcpy(sts.c_str());
		return tmp;
	}

	int Utils::strcmp(const char* s1, const char* s2) const
	{
		int i;
		for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
		return s1[i] - s2[i];
	}

	int Utils::strcmp(const char* s1, const char* s2, int len) const {
		int i = 0;
		while (i < len - 1 && s1[i] && s2[i] && s1[i] == s2[i]) {
			i++;
		}
		return s1[i] - s2[i];
	}

	const char* Utils::strstr(const char* str, const char* find)  const {
		const char* faddress = nullptr;
		int i, flen = strlen(find), slen = strlen(str);
		for (i = 0; i <= slen - flen && strcmp(&str[i], find, flen); i++);
		if (i <= slen - flen) faddress = &str[i];
		return faddress;
	}

	std::ostream& Utils::readToWidth(std::ostream& os, const char* str, int width)
	{
		for (int i = 0; i < width; i++) {
			os << str[i];
		}

		return os;
	}
}