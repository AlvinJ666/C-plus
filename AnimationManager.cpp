/********************************************************************
Filename:AnimationManger.cpp
Version : 1.1
Author : Dongxu Jiang
Student No : 040 920 915
Course Name / Number : CST8219 C++ Programming
Lab Sect : 311
Assignment # : 2
Assignment name : Animation in C++ using Container Classes and Overloaded Operators, using inheritance
Due Date : Nov 30 2019
Submission Date : Nov 30 2019
Professor : M. Abouseif
Purpose : Manage animations in a vector
*********************************************************************/
#include <string>
#include <iostream>
#include <forward_list>
#include <vector>

using namespace std;

#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"
/******************************************************************
Function name : AnimationManager::EditAnimation()
Purpose:Edit one of the existing animations
In parameters : none
Out parameters : none
for successful executionVersion : 1.1
Author : Dongxu Jiang
**********************************************************************/
void AnimationManager::EditAnimation(){
	unsigned int input = 0, opt = 0;
	cout << "Which Animation do you wish to edit ? Please give the index(from 0 to " << (animations.size() - 1) << ") : ";
	cin >> input;
	if (input >= 0 && input < animations.size()) {//if input index is valid
		string opt;
		cout << "Editing Animation #" << input << endl;
		do {//loop to the sub-menu of handling with frames
			cout << "MENU\n 1. Insert a Frame\n 2. Delete a Frame\n 3. Edit a Frame\n 4. Quit" << endl;
			cin >> opt;
			switch (opt.at(0))//take one of those options in the menu
			{
			case '1':
				cout << "Insert a Frame in the Animation" << endl;
				cin >> animations.at(input);
				break;
			case '2':
				animations.at(input).DeleteFrame();
				break;
			case '3':
				cout << "Edit a Frame in the Animation" << endl;
				cout << "Editing Animation #" << input << endl;
				animations.at(input).EditFrame();
				break;
			case '4':
				cout << "Animation #" << input << " edit complete" << endl;
				break;
			default:cout << "Not a valid option" << endl;
			}
		} while (opt.at(0) != '4');//if opt is 4, return to main menu which handling with animations
	}
}
/******************************************************************
Function name : AnimationManager::DeleteAnimation()
Purpose:delete one of the existing animations
In parameters : none
Out parameters : none
for successful executionVersion : 1.1
Author : Dongxu Jiang
**********************************************************************/
void AnimationManager::DeleteAnimation() {
	if (animations.size() >= 1) {//if there are animations in side the vector
		unsigned int input;
		cout << "Delete an Animation from the Animation Manager\nWhich Animation do you wish to delete ? Please give the index in the range 0 to " << animations.size() - 1 << ") : ";
		cin >> input;
		if (input >= 0 && input < animations.size()) {//if input index to delete is valid 
			animations.erase(animations.begin() + input);
			cout << "Animation #" << input << " deleted" << endl;
		}
		else {
			cout << "Not in valid range" << endl;
		}
	}
	else {
		cout << "There is no Animation" << endl;
	}
}
/******************************************************************
Function name : operator>>(std::istream& is, AnimationManager& anmm)
Purpose:take user input to initilize one animation
In parameters : std::istream& is, AnimationManager& anmm
Out parameters : is:istream
for successful executionVersion : 1.1
Author : Dongxu Jiang
**********************************************************************/
istream& operator>>(istream& is,  AnimationManager& anmm){
	string name;
	cout << "Add an Animation to the Animation Manager\nPlease enter the Animation Name : ";
	is >> name;
	anmm.animations.reserve(20);//otherwise it will crash if continue to add one more animation, save time space at first
	Animation newone(name);
	anmm.animations.push_back(newone);
	cout << "Animation " << name << " added at the back of animations" << endl;
	return is;
}
/******************************************************************
Function name : operator>>(std::ostream& os, AnimationManager& anmm)
Purpose:report animations in vector
In parameters : std::ostream& is, AnimationManager& anmm
Out parameters : os:ostream
for successful executionVersion : 1.1
Author : Dongxu Jiang
**********************************************************************/
ostream& operator<<(ostream& os, AnimationManager& anmm) {
	if (anmm.animations.empty())
		return os;
	for (int unsigned i = 0; i < anmm.animations.size(); i++)
		os << "Aniamtion: " << i << "\n" << anmm.animations.at(i);
	return os;
}