/********************************************************************
Filename:Animation.cpp
Version : 1.1
Author : Dongxu Jiang
Student No : 040 920 915
Course Name / Number : CST8219 C++ Programming
Lab Sect : 311
Assignment # : 3
Assignment name : Animation in C++ using Container Classes and Overloaded Operators, using inheritance
Due Date : Nov 30 2019
Submission Date : Nov 30 2019
Professor : M. Abouseif
Purpose : Manage frames in a forward list
*********************************************************************/
#include <string>
#include <iostream>
#include <forward_list>
#include <vector>
using namespace std;
#include "Frame.h"
#include "AudioFrame.h"
#include "VideoFrame.h"
#include "Animation.h"
#include "AnimationManager.h"
/******************************************************************
Function name : Animation::~Animation()
Purpose:free memeory in list freams
In parameters : none
Out parameters : none
for successful executionVersion : 1.1
Author : Dongxu Jiang
**********************************************************************/
Animation::~Animation() {
	if (frames.empty())
		return;
	for (auto frame : frames) {
		delete frame;
	}
}
/******************************************************************
Function name : Animation::EditFrame()
Purpose:edit one of the the frames which are existing in the animnation
In parameters : none
Out parameters : none
for successful executionVersion : 1.1
Author : Dongxu Jiang
**********************************************************************/
void Animation::EditFrame() {
	if (!frames.empty()) {//check is there is no frames in this animation
		int counter = 0, input = 0;
		forward_list<Frame*>::iterator it;
		for (it = frames.begin(); it != frames.end(); ++it)//loop to get frame numbers
			counter++;
		cout << "There are " << counter << " Frame(s) in the list.Please specify the index(<= "<<(counter-1)<<") to edit at : ";
		cin >> input;
		if (input >= 0 && input <= counter) {//if input is valid 

			counter = 0;//reset counter to 0
			for (it = frames.begin(); it != frames.end(); ++it) {//loop until you get the correct index
				if (counter == input) {//if get the frame at index "input"
					char name[255] = { NULL };
					double size;
					cout << "The name and size of this Frame are " << **it << ". What do you wish to replace them with ?" << endl;
					cin >> name;
					cin >> size;
					if (AudioFrame * adF = dynamic_cast<AudioFrame*>(*it)) {
						adF=new AudioFrame(name,size);
						delete (*it);
						(*it)=adF;
					}
					else if(VideoFrame * vdF = dynamic_cast<VideoFrame*>(*it)){
						vdF = new VideoFrame(name, size);
						delete (*it);
						(*it) = vdF;
					}
					cout << **it << endl;
					cout << "Frame #" << input << " edit completed" << endl;
					break;
				}
				counter++;
			}
		}
	}
}
/******************************************************************
Function name : Animation::DeleteFrame()
Purpose:delete the first one of the the frames which are existing in the animnation
In parameters : none
Out parameters : none
for successful executionVersion : 1.1
Author : Dongxu Jiang
**********************************************************************/
void Animation::DeleteFrame() {
	if (!frames.empty()) {//if there are frames in the list
		Frame* temp = *frames.begin();
		frames.pop_front();
		delete temp;		
		cout << "First Frame deleted" << endl;
	}
}
/******************************************************************
Function name : operator>>(istream& is, Animation& anm)
Purpose:take input from user to initilize a new frame and add it to the front of frames forward list
In parameters : istream& is, Animation& anm
Out parameters : is:istream
for successful executionVersion : 1.1
Author : Dongxu Jiang
**********************************************************************/
istream& operator>>(istream& is, Animation& anm) {
	string name;
	double size = 0;
	char type;
	cout << "Please enter the Frame frameName : ";
	is >> name;
	cout << "Please enter the Frame size(MB) : ";
	is >> size;
	
	cout << "Please enter the Frame type (AudioFrame = A, VideoFrame = V): ";
	cin >> type;
	if (type == 'A') {
		Frame* newAF = new AudioFrame(name,size);
		anm.frames.push_front(newAF);
	}
	else if (type == 'V') {
		Frame* newVF = new VideoFrame(name, size);
		anm.frames.push_front(newVF);
	}
	else {
		cout << "Please enter a valid type" << endl;
		return is;
	}
	cout << "Frame " << name << " Frame* added at the front of frames" << endl;
	return is;
}// Add a Frame as in cin >> A;
/******************************************************************
Function name : operator<<(ostream& os, Animation& anm)
Purpose:report existing frames in the forward list
In parameters : ostream& os, Animation& anm
Out parameters : os:ostream
for successful executionVersion : 1.1
Author : Dongxu Jiang
**********************************************************************/
ostream& operator<<(ostream& os, Animation& anm) {
	int count = 0;
	os << "\tAnimation name is " << anm.animationName << "\n\tReport the Animation" << endl;
	forward_list<Frame*>::iterator it;
	for (it = anm.frames.begin(); it != anm.frames.end(); ++it) {//loop through all the frames in the list
		os << "Frame #" << count << "\n" << **it;
		(*it)->CalculateFrameResource();
		count++;
	}
	if (count == 0)//if there is no frames
		os << "\tNo frames in the Animation" << endl;
	return os;
}// output the Frames as in cout << A;