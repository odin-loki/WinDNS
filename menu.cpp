#include "menu.h"

#include <Windows.h>
#include <WinNls.h>

#include <cstdint>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

#pragma region Drawing

///*Keep object design pattern to be able to change menu later and customise colours and text etc.*/
///*Consider putting language layer over Menu Layers.*/
#pragma region Header
	///Returns an MenuHeader Object from a Private Constructor.
menu::Header menu::Header::DrawHeader(wchar_t* title, wchar_t* statement, wchar_t* author, wchar_t* licence)
{
	return Header(title, statement, author, licence);
}

///Draws Border for Header.
void menu::Header::DrawTopOrBottom()
{
	for (size_t i = 0; i < width; i++)
	{
		wcout << side;
	}
	wcout << endl;
}

///Draws Menu Text on Centre.
void menu::Header::DrawString(wchar_t* text)
{
	int txtLength = (int)wcslen(text);
	int offSetToDrawTextCentre = halfwidth - txtLength / 2;
	int drawlength = width - txtLength;

	for (size_t i = 0; i <= drawlength; i++)
	{
		if (i == 0 || i == drawlength)
		{
			wcout << side;
		}
		else if (i == offSetToDrawTextCentre)
		{
			wcout << text;
		}
		else
		{
			wcout << fill;
		}
	}
	wcout << endl;
}

///Draws Entire Header.
void menu::Header::PrivateDrawHeader(wchar_t* title, wchar_t* statement, wchar_t* author, wchar_t* licence)
{
	DrawTopOrBottom();
	DrawString(title);
	DrawString(statement);
	DrawString(author);
	DrawString(licence);
	DrawTopOrBottom();
}

///Constructor that builds Header Object.
menu::Header::Header(wchar_t* title, wchar_t* statement, wchar_t* author, wchar_t* licence)
{
	PrivateDrawHeader(title, statement, author, licence);
}
#pragma endregion Header

#pragma endregion Drawing




#pragma region Files

void ReadFile(string fileName)
{
	wfstream file;
	file.open(fileName + ".txt", fstream::in);

	if (!file.is_open())
	{
		throw new exception("Invalid Language File Name or File not found. Example: english.txt\n");
	}



	wstringstream wcharstream = wstringstream();
}

#pragma endregion




#pragma region Localisation

string SelectLanguage()
{
	//Get User Language. Extract Primary Language. 
	uint16_t primaryLang = PRIMARYLANGID(GetUserDefaultUILanguage());

	//Pick File based on Primary Language.
	switch (primaryLang)
	{
	case LANG_ARABIC:
		return "arabic";
		break;
	case LANG_BULGARIAN:
		return "bulgarian";
		break;
	case LANG_CHINESE:
		return "chinese";
		break;
	case LANG_ENGLISH:
		return "english";
		break;
	case LANG_FILIPINO:
		return "fillipino";
		break;
	case LANG_FRENCH:
		return "french";
		break;
	case LANG_GERMAN:
		return "german";
		break;
	case LANG_GREEK:
		return "greek";
		break;
	case LANG_HINDI:
		return "hindi";
		break;
	case LANG_ITALIAN:
		return "italian";
		break;
	case LANG_JAPANESE:
		return "japanese";
		break;
	case LANG_KOREAN:
		return "korean";
		break;
	case LANG_PERSIAN:
		return "persian";
		break;
	case LANG_RUSSIAN:
		return "russian";
		break;
	case LANG_THAI:
		return "thai";
		break;
	case LANG_TURKISH:
		return "turkish";
		break;
	case LANG_VIETNAMESE:
		return "vietnamese";
		break;

		//Error, Default to English.
	case LANG_NEUTRAL:
		return "english";
		break;
	case LANG_INVARIANT:
		return "english";
		break;
	default:
		throw new exception("Invalid Language detected. Try English.\n");
	}
}

#pragma endregion






