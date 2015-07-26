// KeyPress.cpp
#include "stdafx.h"

#include "KeyPress.h"


void pressKey(WORD t, int x){
	// This structure will be used to create the keyboard
    // input event.
    INPUT ip;
	bool checkFlag = false;
	time_t timerStart;
	time_t timerNow;
	time_t timerDiff;
	timerStart = time(NULL);

    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
 
    // Press the "A" key

	while(checkFlag==false){
			if(Skill_Status(x)==true){
				ip.ki.wVk = t; // virtual-key code for the "a" key
			    ip.ki.dwFlags = 0; // 0 for key press
                SendInput(1, &ip, sizeof(ip)); 
                // Release the "A" key
                ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
                SendInput(1, &ip, sizeof(ip));

				checkFlag = true; //key pressed exit loop
				std::cout << "key Pressed"<<std::endl;
				Sleep(250);
			}
			else{
				Sleep(500);
				//std::cout << "sleep key not ready"<<std::endl;
			}
			timerNow = time(NULL);
			timerDiff = difftime(timerNow,timerStart);
			std::cout <<"time: " <<timerDiff <<std::endl;

			if(timerDiff > 12){
				std::cout <<"taking to long: " << std::endl;
				checkFlag = true;
			}
	}
	

}

bool Skill_Status(WORD t){
	HDC _hdc = GetDC(NULL);
	COLORREF skill;
	bool onFlag = false;

	int	_red;
	int	_green;
	int	_blue;

	if(t>0){//skill 1 Carefullsynthesis 2
		skill = GetPixel(_hdc,603 ,717);
		_red = GetRValue(skill);
		_green = GetGValue(skill);
		_blue = GetBValue(skill);
		if(_red==205 && _green == 180 && _blue==230){
			onFlag = true;
			Sleep(200);
		}
		else{
			onFlag = false;
		}

	}
	
	std::cout << _red << std::endl; 
	std::cout << _green <<std::endl;
	std::cout << _blue <<std::endl;

	ReleaseDC(NULL,_hdc);
	return onFlag;

}

void pressKey_static(WORD t){


	INPUT ip;

    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
	
	ip.ki.wVk = t; // virtual-key code for the "a" key
	ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(ip)); 
    // Release the "A" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(ip));



}

void leftMouseClick(){
	INPUT mouseIn;
	mouseIn.type = INPUT_MOUSE;
	mouseIn.mi.time = 0;
	mouseIn.mi.dwExtraInfo = 0;
	mouseIn.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1,&mouseIn,sizeof(mouseIn));
	mouseIn.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	Sleep(75);
	SendInput(1,&mouseIn,sizeof(mouseIn));
}

void rightMouseClick(){
	INPUT mouseIn;
	mouseIn.type = INPUT_MOUSE;
	mouseIn.mi.time = 0;
	mouseIn.mi.dwExtraInfo = 0;
	mouseIn.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	SendInput(1,&mouseIn,sizeof(mouseIn));
	mouseIn.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	Sleep(75);
	SendInput(1,&mouseIn,sizeof(mouseIn));
}

void EnterString(string x){
	string temp = x;

	for(int y = 0; y<temp.length(); y++){
		Sleep(150);
		if(temp[y]=='a'){
			pressKey_static(0x41);
		}
		else if(temp[y]=='b'){
			pressKey_static(0x42);
		}
		else if(temp[y]=='c'){
			pressKey_static(0x43);
		}
		else if(temp[y]=='d'){
			pressKey_static(0x44);
		}
		else if(temp[y]=='e'){
			pressKey_static(0x45);
		}
		else if(temp[y]=='f'){
			pressKey_static(0x46);
		}
		else if(temp[y]=='g'){
			pressKey_static(0x47);
		}
		else if(temp[y]=='h'){
			pressKey_static(0x48);
		}
		else if(temp[y]=='i'){
			pressKey_static(0x49);
		}
		else if(temp[y]=='j'){
			pressKey_static(0x4A);
		}
		else if(temp[y]=='k'){
			pressKey_static(0x4B);
		}
		else if(temp[y]=='l'){
			pressKey_static(0x4C);
		}
		else if(temp[y]=='m'){
			pressKey_static(0x4D);
		}
		else if(temp[y]=='n'){
			pressKey_static(0x4E);
		}
		else if(temp[y]=='o'){
			pressKey_static(0x4F);
		}
		else if(temp[y]=='p'){
			pressKey_static(0x50);
		}
		else if(temp[y]=='q'){
			pressKey_static(0x51);
		}
		else if(temp[y]=='r'){
			pressKey_static(0x52);
		}
		else if(temp[y]=='s'){
			pressKey_static(0x53);
		}
		else if(temp[y]=='t'){
			pressKey_static(0x54);
		}
		else if(temp[y]=='u'){
			pressKey_static(0x55);
		}
		else if(temp[y]=='v'){
			pressKey_static(0x56);
		}
		else if(temp[y]=='w'){
			pressKey_static(0x57);
		}
		else if(temp[y]=='x'){
			pressKey_static(0x58);
		}else if(temp[y]=='y'){
			pressKey_static(0x59);
		}else if(temp[y]=='z'){
			pressKey_static(0x5A);
		}
		else if(temp[y]==' '){
			pressKey_static(0x20);
		}
		else
			y = y + temp.length(); /// exit on error

	}

}