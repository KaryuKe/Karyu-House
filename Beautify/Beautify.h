#pragma once

#include <QtWidgets/QWidget>
#include "ui_Beautify.h"

class Beautify : public QWidget
{
	Q_OBJECT

public:
	Beautify(QWidget *parent = Q_NULLPTR);

private:
	Ui::BeautifyClass ui;
};
