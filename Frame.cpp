/********************************************************************
Filename:Frame.cpp
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
Purpose : print info of a frame
*********************************************************************/
#include <string>
#include <iostream>
#include <forward_list>
#include <vector>
using namespace std;
#include "Frame.h"
#include "AudioFrame.h"
#include "VideoFrame.h"

ostream& operator<<(ostream& os, Frame& frm) {
		if (AudioFrame* temp = dynamic_cast<AudioFrame*>(&frm)) {
			os << "AudioFrame: frameName ="<<frm.frameName<< endl;
		}
		else if (VideoFrame * temp = dynamic_cast<VideoFrame*>(&frm)) {
			os << "VideoFrame: frameName =" << frm.frameName << endl;
		}
	return os;
}; 