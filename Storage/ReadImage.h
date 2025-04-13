#pragma once
#include <chrono>       // For timing
#include <iostream>     // For output
#include <vector>
#include <thread>       // For multithreading
#define DLLEXPORT __declspec(dllexport)
using namespace std;
// BMP File Header (14 bytes)
#pragma pack(push, 1) // Ensure no padding
struct BMPFileHeader {
	uint16_t fileType;     // "BM" (0x4D42)
	uint32_t fileSize;
	uint16_t reserved1;
	uint16_t reserved2;
	uint32_t offsetData;   // image data start position
};
// BMP Info Header (40 bytes)
struct BMPInforHeader {
	uint32_t headerSize;
	int32_t width;
	int32_t height;
	uint16_t planes;
	uint16_t bitCount;    // number of bits each pixel
	uint32_t compression;
	uint32_t imageSize;
	int32_t xPixelsPerM;
	int32_t yPixelsPerM;
	uint32_t colorsUsed;
	uint32_t colorsImportant;
};
#pragma pack(pop)
namespace read
{
	class readImage
	{
		private:
		vector<uint8_t> matrixGrayStorage;
		int m_width, m_height;
		// Thread processing functions
		void processChunk24Bit(vector<uint8_t>& imageData, int startRow, int endRow, int rowSize);
		void processChunk32Bit(vector<uint8_t>& imageData, int startRow, int endRow);
		public:
		readImage() : m_width(0), m_height(0) {}
		readImage(int width, int height) : m_width(width), m_height(height) {
			matrixGrayStorage.resize(m_width * m_height);
		}
		DLLEXPORT virtual ~readImage() = default;
		DLLEXPORT bool inputImage(const char* fileName);
		DLLEXPORT int getWidth();
		DLLEXPORT int getHeight();
		//DLLEXPORT uint8_t* getMatrixGray();
		DLLEXPORT vector<uint8_t>& getMatrixGrayVector();
	};
}