#include "camera.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	camera w;
	w.show();
	return a.exec();
}
