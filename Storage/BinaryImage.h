#pragma once
#ifdef MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport)
#else
#define MYDLL_API __declspec(dllimport)
#endif
#include <iostream>
#include <string>
#include <chrono> 
#include <windows.h>
#include "ReadImage.h"
#include "ScaleImage.h"

class MYDLL_API BinaryImage
{
public:
	static void ImageBinary(std::string input, int new_width, int new_height, float new_angle, std::string &output);
private:
};