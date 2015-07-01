// Hough.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2\opencv.hpp>
#include <iostream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	const char *img_name = "F:\\图片\\002.jpg";
	IplImage *img = cvLoadImage(img_name, 1);
	IplImage *dst = 0;
	IplImage *color_dst = 0;
	CvMemStorage *storage = cvCreateMemStorage(0);
	CvSeq *lines = 0;
	int i;

	if (!img)
	{
		return -1;
	}

	dst = cvCreateImage(cvGetSize(img), 8, 1);
	color_dst = cvCreateImage(cvGetSize(img), 8, 3);

	cvCanny(img, dst, 50, 200, 3);

	cvCvtColor(dst, color_dst, CV_GRAY2BGR);

	lines = cvHoughLines2(dst, storage, CV_HOUGH_STANDARD, 1, CV_PI / 180, 100, 0, 0);
	for (i = 0;i < MIN(lines->total,100), ++i)
	{
		float *line = (float*)cvGetSeqElem(lines, i);
		float rho = line[0];
		float theta = line[1];
		CvPoint pt1, pt2;

	}
	return 0;
}

