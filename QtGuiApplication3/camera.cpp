#include "camera.h"

camera::camera(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::camera)
{
	ui->setupUi(this);
}
