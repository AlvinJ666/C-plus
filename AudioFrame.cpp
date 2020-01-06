/********************************************************************
Filename:AudioFrame.cpp
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
Purpose : calculate frame size and print frame info, inherited from Frame class
*********************************************************************/
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Frame.h"
#include "AudioFrame.h"
/******************************************************************
Function name : AudioFrame::CalculateFrameResource()
Purpose:calculate frame size and print out
In parameters :none
Out parameters :none
for successful executionVersion : 1.1
Author : Dongxu Jiang
**********************************************************************/
void AudioFrame::CalculateFrameResource() {
	double fileSize[3];
	
	for (int i = 0; i < RATES; i++) {		
		fileSize[i] = size / COMPRESSION_RATIO[i];
	}
	cout << "MP3 Lossy Compression\n-----------------------------------------------------------------" << endl;
	cout << "bitrate (kbits/s): | "  << BITRATE[0] << setiosflags(ios::right) << setw(9) << "| " << BITRATE[1] << setw(9) << "| " << BITRATE[2] << "\n-----------------------------------------------------------------" << endl;
	cout << fixed;
	cout << setprecision(2);
	cout << "file size (MB):    | "  << fileSize[0] << setiosflags(ios::right) << setw(7) << "| " << fileSize[1] << setw(7) << "| " << fileSize[2] << "\n-----------------------------------------------------------------" << endl;
	cout << setprecision(0);
}
/******************************************************************
Function name : operator>>(std::ostream& os, AnimationManager& anmm)
Purpose:report animations in vector
In parameters : std::ostream& os, AnimationManager& anmm
Out parameters : os:ostream
for successful executionVersion : 1.1
Author : Dongxu Jiang
**********************************************************************/
ostream& operator<<(ostream& os, AudioFrame& adF) {
	return os;
}