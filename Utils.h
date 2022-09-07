#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds {

	class Utils {
	public:
		int validSelection(int maxNum);
		int strlen(const char* str) const;
		char* strcpy(char* des, const char* src) const;
		char* alcpy(const char* name);
		char* dynread(std::istream& istr, char del = '\n');
		int strcmp(const char* s1, const char* s2) const;
		int strcmp(const char* s1, const char* s2, int len) const;
		const char* strstr(const char* str, const char* find) const;
		std::ostream& readToWidth(std::ostream&, const char*, int);
	};

	extern Utils ut;
}
#endif
