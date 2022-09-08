#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__

#include <iostream>

namespace sdds {
	const unsigned MAX_MENU_ITEMS = 20;

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
		MenuItem* m_items[MAX_MENU_ITEMS]{};
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

		Menu& operator<<(const char* menuitemConent);
		friend std::ostream& operator<<(std::ostream& os, const Menu& M);

		operator int()const;
		operator unsigned int()const;
		operator bool()const;
		const char* operator[](int index) const;
	};
}
#endif