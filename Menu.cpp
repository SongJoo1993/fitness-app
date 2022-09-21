#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"

namespace sdds {
	//MenuItem Class Functions
	MenuItem& MenuItem::setEmpty()
	{
		m_content = new char[1];
		m_content[0] = 0;
		m_length = 0;
		return *this;
	}

	MenuItem::MenuItem(const char* cstr) 
	{
		if (cstr != nullptr)
		{
			m_content = ut.alcpy(cstr);
		}
		else
		{
			setEmpty();
		}
	}

	MenuItem::operator bool() const
	{
		return m_length != 0;
	}

	MenuItem::operator const char* () const
	{
		return m_content;
	}

	void MenuItem::display(std::ostream& os) const
	{
		if (m_length != 0) {
			os << m_content;
		}
	}

	MenuItem::~MenuItem()
	{
		delete[] m_content;
	}

	//Menu Class Functions

	Menu::Menu()
	{
		m_title = nullptr;
		m_items[0] = 0;
		m_itemNo = 0;
	}

	Menu::Menu(const char* title)
	{
		if (title != nullptr)
		{
			m_title = ut.alcpy(title);
		}
	}

	Menu::~Menu()
	{
		delete[] m_title;
		for (int i = 0; i < m_itemNo; i++) delete[] m_items[i];
		m_itemNo = 0;
	}

	void Menu::displayTitle() const
	{
		if (m_title != nullptr)
		{
			std::cout << m_title;
		}
	}

	void Menu::displayItems() const
	{
		if (m_title != nullptr || m_items != nullptr) {
			int lineNum = 0;
			if (m_title) {
				std::cout << m_title << std::endl;
			}
			
			do {
				std::cout.width(2);
				std::cout << lineNum + 1;
				std::cout << ". ";
				m_items[lineNum]->display(std::cout);
				std::cout << std::endl;
				lineNum++;
				if (lineNum == m_itemNo) {
					std::cout << " 0. Exit" << std::endl << "> ";
				}
			} while (lineNum != m_itemNo);
		}
	}

	unsigned Menu::run()
	{
		unsigned selectNumb{};
		displayItems();
		selectNumb = ut.validSelection(m_itemNo);
		return selectNumb;
	}

	int Menu::operator~()
	{
		unsigned selectNumb{};
		displayItems();
		selectNumb = ut.validSelection(m_itemNo);
		return selectNumb;
	}

	Menu& Menu::setTitle(const char* title)
	{
		if (title != nullptr) m_title = ut.alcpy(title);
		return *this;
	}

	Menu& Menu::operator<<(const char* contentStr)
	{
		if (m_itemNo < SDDS_MAX_MENU_ITEMS)
		{
			MenuItem* newItem = new MenuItem(contentStr);
			m_items[m_itemNo++] = newItem;
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Menu& M)
	{
		if (M.m_title != nullptr) os << M.m_title;
		return os;
	}

	Menu::operator int() const
	{
		return m_itemNo;
	}

	Menu::operator unsigned int() const
	{
		return m_itemNo;
	}

	Menu::operator bool() const
	{
		return m_itemNo > 0;
	}

	const char* Menu::operator[](int index) const
	{
		return (const char*)(*m_items[index % m_itemNo]);
	}
}