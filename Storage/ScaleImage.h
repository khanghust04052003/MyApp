#pragma once

#include <vector>
#ifdef MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport)
#else
#define MYDLL_API __declspec(dllimport)
#endif


class MYDLL_API ScaleImage {
private:
	//The function calculates the average value of pixels at "x" "y" and limits "maxX" "maxY" with the range in the direction "sX" "sY"
	static uint8_t calculationAverage(const std::vector<uint8_t> &data
		, const int maxX
		, const int maxY
		, const float x
		, const float y
		, const float scaleX
		, const float scaleY);
public:
	ScaleImage() = delete;
	~ScaleImage() = delete;
	//function to resize image with "newheight" "newwidth" and counterclockwise rotation angle "angle"
	static bool Rescale(std::vector<uint8_t> &data
		, int &width
		, int &height
		, const int newWidth
		, const int newHeight
		, const float angle);



};



