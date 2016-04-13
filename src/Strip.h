/*
* PixelPusher
* Dec 2014
* nathan lachenmyer
* http://morphogen.cc/
*/

#pragma once

#include <memory>
#include <vector>
#include <string>
#include "Pixel.h"

namespace ofxPixelPusher {

	class Strip {
	public:
		Strip(short stripNumber, int length);
		~Strip();
		//bool isRGBOW();
		//void setRGBOW(bool rgbow);
		int getLength();
		bool isTouched();
		short getStripNumber();
		void setPixels(unsigned char r, unsigned char g, unsigned char b);
		void setPixelsHSB(float hue, float saturation, float brightness);
		//void setPixels(unsigned char r, unsigned char g, unsigned char b, unsigned char o, unsigned char w);
		void setPixels(std::vector<std::shared_ptr<Pixel> > p);
		void setPixel(int position, unsigned char r, unsigned char g, unsigned char b);
		void setPixelHSB(int position, float hue, float saturation, float brightness);
		//void setPixel(int position, unsigned char r, unsigned char g, unsigned char b, unsigned char o, unsigned char w);
		void setPixel(int position, std::shared_ptr<Pixel> pixel);
		std::vector<std::shared_ptr<Pixel> > getPixels();
		int getNumberOfPixels();
		void setPowerScale(double powerscale);
		void serialize();
		unsigned char* getPixelData(); //remove
		int getPixelDataLength(); //remove
		void setId(int id);
		int getId();
		std::vector<unsigned char>::iterator begin();
		std::vector<unsigned char>::iterator end();
	protected:
		std::vector<std::shared_ptr<Pixel> > mPixels;
		std::vector<unsigned char> mPixelData;
		short mStripNumber;
		int mId;
		bool mTouched;
		bool mIsRGBOW;
		double mPowerScale;
	};

}
