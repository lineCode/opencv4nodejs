#include "macros.h"
#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>
#include "Size.h"

#ifndef __FF_HOGDESCRIPTOR_H__
#define __FF_HOGDESCRIPTOR_H__

class HOGDescriptor : public Nan::ObjectWrap {
public:
	cv::HOGDescriptor hog;

	static FF_GETTER_JSOBJ(HOGDescriptor, winSize, hog.winSize, FF_UNWRAP_SIZE_AND_GET, Size::constructor);
	static FF_GETTER_JSOBJ(HOGDescriptor, blockSize, hog.blockSize, FF_UNWRAP_SIZE_AND_GET, Size::constructor);
	static FF_GETTER_JSOBJ(HOGDescriptor, blockStride, hog.blockStride, FF_UNWRAP_SIZE_AND_GET, Size::constructor);
	static FF_GETTER_JSOBJ(HOGDescriptor, cellSize, hog.cellSize, FF_UNWRAP_SIZE_AND_GET, Size::constructor);
	static FF_GETTER(HOGDescriptor, nbins, hog.nbins);
	static FF_GETTER(HOGDescriptor, derivAperture, hog.derivAperture);
	static FF_GETTER(HOGDescriptor, histogramNormType, hog.histogramNormType);
	static FF_GETTER(HOGDescriptor, nlevels, hog.nlevels);
	static FF_GETTER(HOGDescriptor, winSigma, hog.winSigma);
	static FF_GETTER(HOGDescriptor, L2HysThreshold, hog.L2HysThreshold);
	static FF_GETTER(HOGDescriptor, gammaCorrection, hog.gammaCorrection);
	static FF_GETTER(HOGDescriptor, signedGradient, hog.signedGradient);

	static NAN_MODULE_INIT(Init);
	static NAN_METHOD(New);

	struct ComputeWorker;
	static NAN_METHOD(Compute);
	static NAN_METHOD(ComputeAsync);

	struct ComputeGradientWorker;
	static NAN_METHOD(ComputeGradient);
	static NAN_METHOD(ComputeGradientAsync);

	struct DetectWorker;
	static NAN_METHOD(Detect);
	static NAN_METHOD(DetectAsync);

	struct DetectROIWorker;
	static NAN_METHOD(DetectROI);
	static NAN_METHOD(DetectROIAsync);

	struct DetectMultiScaleWorker;
	static NAN_METHOD(DetectMultiScale);
	static NAN_METHOD(DetectMultiScaleAsync);

	struct DetectMultiScaleROIWorker;
	static NAN_METHOD(DetectMultiScaleROI);
	static NAN_METHOD(DetectMultiScaleROIAsync);

	struct GroupRectanglesWorker;
	static NAN_METHOD(GroupRectangles);
	static NAN_METHOD(GroupRectanglesAsync);

	static NAN_METHOD(GetDaimlerPeopleDetector);
	static NAN_METHOD(GetDefaultPeopleDetector);
	static NAN_METHOD(CheckDetectorSize);
	static NAN_METHOD(SetSVMDetector);
	static NAN_METHOD(Save);
	static NAN_METHOD(Load);

	static Nan::Persistent<v8::FunctionTemplate> constructor;

	cv::HOGDescriptor* getNativeObjectPtr() { return &hog; }
	cv::HOGDescriptor getNativeObject() { return hog; }

	typedef InstanceConverter<HOGDescriptor, cv::HOGDescriptor> Converter;

	static const char* getClassName() {
		return "HOGDescriptor";
	}
};

#endif