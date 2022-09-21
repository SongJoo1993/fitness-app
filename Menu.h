#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>
#include "FitMacros.h"

namespace sdds {

	class Menu;

	class MenuItem {
	private:
		char* m_content{};
		int m_length{};
		friend class Menu;
		MenuItem& setEmpty();
		MenuItem(const char* cstr = nullptr);

		MenuItem(const MenuItem& toCopy) = delete;
		MenuItem& operator =(const MenuItem& toAssign) = delete;

		operator bool() const;
		operator const char* () const;
		void display(std::ostream& os)const;
		~MenuItem();
	};

	class Menu {
	private:
		char* m_title{};
		MenuItem* m_items[SDDS_MAX_MENU_ITEMS]{};
		int m_itemNo{};
	public:
		Menu();
		Menu(const char* title);

		Menu(const Menu& toCopy) = delete;
		Menu& operator =(const Menu& toAssign) = delete;
		~Menu();

		void displayTitle()const;
		void displayItems()const;
		unsigned run();
		int operator~();
		Menu& setTitle(const char* title);

		Menu& operator<<(const char* contentStr);
		friend std::ostream& operator<<(std::ostream& os, const Menu& M);

		operator int()const;
		operator unsigned int()const;
		operator bool()const;
		const char* operator[](int index) const;
	};
}
#endif