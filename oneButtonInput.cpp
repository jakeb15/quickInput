// oneButtonInput.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include "KeyPress.h"
#include <string>

using namespace std;

void EnterFileNumber(int fileNumber);


int _tmain(int argc, _TCHAR* argv[])
{
	int count = 2100;

	while(true){
		if (GetAsyncKeyState(VK_F2)){
			EnterFileNumber(count);
			Sleep(100);
			pressKey_static(0x0D);
			count++;
		}
	
	}
	
	return 0;
}

void EnterFileNumber(int fileNumber){
	cout << fileNumber <<endl;
	string s = std::to_string(fileNumber);
	cout << "string conversion: "  << s <<endl;
	cout << s.length() << endl;
	cout << "S: "<<s[0] << endl;
	Sleep(1000);
	for(int x=0; x < s.length();x++){
		if(s[x] =='0')
			pressKey_static(0x30);
		if(s[x] == '1')
			pressKey_static(0x31);
		if(s[x] == '2')
			pressKey_static(0x32);
		if(s[x] == '3')
			pressKey_static(0x33);
		if(s[x] == '4')
			pressKey_static(0x34);
		if(s[x] == '5')
			pressKey_static(0x35);
		if(s[x] == '6')
			pressKey_static(0x36);
		if(s[x] == '7')
			pressKey_static(0x37);
		if(s[x] == '8')
			pressKey_static(0x38);
		if(s[x] == '9')
			pressKey_static(0x39);

		cout << "if loop" <<endl;
	}	
}