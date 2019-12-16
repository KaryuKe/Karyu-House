#pragma once

#include <QtWidgets/QWidget>
#include "ui_camera.h"
#include<QWidget>
#include<QImage>
#include<QTimer>
#include <highgui.h>
#include<cv.h>
namespace Ui {
	class camera;
}
class camera : public QWidget
{
	Q_OBJECT

public:
	explicit camera(QWidget *parent = Q_NULLPTR);
	~camera();

private slots:
	void openCamera();
	void readFrame();
	void closeCamera();
	void capture();
private:
	Ui::camera * ui;
	QTimer * timer;
	QImage * imag;
	CvCapture * cam;
	IplImage * frame;
};
