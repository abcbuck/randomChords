//original creation a long time ago
//revised on 29.10.2023, 18.03.2025

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <Windows.h>
using namespace std;

const char* charFill(char c, int n) {
	char* ret = new char[n+1];
	ret[n]=0;
	for(int i=0; i<n; i++)
		ret[i]=c;
	return ret;
}

void moveCaretBack(int n) {
	cout << charFill('\b', n);
}

void clearChars(int n) {
	moveCaretBack(n);
	cout << charFill(' ', n);
	moveCaretBack(n);
}

bool pleasePressEnter(){
	//pressing ENTER or ESC only works when the program isn't locked. The program can be locked by pressing the PAUSE key.
	bool locked = false;
	cout << "Please press ENTER..."; //21 chars
	for(;;){
		if(GetAsyncKeyState(VK_RETURN) && locked == false){
			clearChars(4), moveCaretBack(17);
			cout << "Please release..."; //17 chars
			while(GetAsyncKeyState(VK_RETURN));
			clearChars(17);
			return 1;
		}
		else if(GetAsyncKeyState(VK_ESCAPE) && locked == false)
			return 0;
		else if(GetAsyncKeyState(VK_PAUSE)){
			while(GetAsyncKeyState(VK_PAUSE));
			(locked)?(locked = false):(locked = true);
		}
	}
}

int main(){
	const char* base;
	const char* mode;

	srand(time(NULL));

	for(;;){
		
		cout << "\t\t\t"; //advances the caret position by 24 chars

		if(!pleasePressEnter())
			break;

		switch(rand()%12){
		case 0:
			base = "C";
			break;
		case 1:
			base = "C#/Db";
			break;
		case 2:
			base = "D";
			break;
		case 3:
			base = "D#/Eb";
			break;
		case 4:
			base = "E";
			break;
		case 5:
			base = "F";
			break;
		case 6:
			base = "F#/Gb";
			break;
		case 7:
			base = "G";
			break;
		case 8:
			base = "G#/Ab";
			break;
		case 9:
			base = "A";
			break;
		case 10:
			base = "A#/Bb";
			break;
		case 11:
			base = "B";
			break;
		}

		moveCaretBack(24);
		cout << "Determined base.\t"; //16 chars + tab
		
		if(!pleasePressEnter())
			break;
		
		switch(rand()%2){
		case 0:
			mode = "Major";
			break;
		case 1:
			mode = "Minor";
			break;
		}

		moveCaretBack(24); //overwrite instead of clearing every char in the line beforehand
		cout << "Determined mode.\t"; //16 chars + tab

		if(!pleasePressEnter())
			break;

		clearChars(17), moveCaretBack(7);
		cout << base << " " << mode << endl << endl;

	}
	
	return 0;
}