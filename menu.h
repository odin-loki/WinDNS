#pragma once

#include <string>


///Write the Menu Here. Local Specific.
class menu
{
public:

	class Header
	{
	public:
		///Returns an MenuHeader Object from a Private Constructor.
		static Header DrawHeader(wchar_t* title, wchar_t* statement, wchar_t* author, wchar_t* licence);

	private:
		wchar_t side = '-';
		wchar_t fill = ' ';
		int width = 100;
		int halfwidth = width / 2;
		

		///Draws Border for Header.
		void DrawTopOrBottom();

		///Draws Menu Text on Centre.
		void DrawString(wchar_t* text);

		///Draws Entire Header.
		void PrivateDrawHeader(wchar_t* title, wchar_t* statement, wchar_t* author, wchar_t* licence);

		///Constructor that draws Menu.
		Header(wchar_t* title, wchar_t* statement, wchar_t* author, wchar_t* licence);
	};


	class MyClass
	{
	public:
		MyClass();
		~MyClass();

	private:

	};




private:

	//Consider What to Put here.





};

