/********************************************************************
Filename:VideoFrame.cpp
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
#include "VideoFrame.h"

/******************************************************************
Function name : VideoFrame::CalculateFrameResource()
Purpose:calculate frame size and print out
In parameters :none
Out parameters :none
for successful executionVersion : 1.1
Author : Dongxu Jiang
**********************************************************************/
void VideoFrame::CalculateFrameResource() {
	double fileSize[8];
	
	for (int i = 0; i < 8; i++)
		fileSize[i] = size / (COMPRESSION_RATIO*BITDEPTH_FACTOR[i]);
	cout << "Lempel - Ziv - Welch Lossless Compression" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "colours:        | 2" << setiosflags(ios::right) << setw(10) << " | 4"<< setw(10) << " | 8" << setw(11) << "| 16" << setw(10) << "| 32" << setw(10) << "| 64" << setw(11) << "| 128" << setw(10) << "| 256" << setw(10) << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << fixed;
	cout << setprecision(2);
	cout << "file size(MB) : | " << setiosflags(ios::right) << fileSize[0]  << setw(6) << "| " << fileSize[1] << setw(5) << "| " << fileSize[2]  << setw(5) << "| " << fileSize[3] << setw(5) << "| " << fileSize[4] << setw(5) << "| " << fileSize[5]  << setw(5) << "| " << fileSize[6] <<  setw(5) << "| " << fileSize[7] << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
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
ostream& operator<<(ostream& os, VideoFrame& vfm) {
	return os;
}