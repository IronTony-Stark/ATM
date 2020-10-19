#include "MainWindow.h"

#include <QApplication>
#include <logics/utils/Money.h>
#include <iostream>

int main(int argc, char* argv[]) {
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return QApplication::exec();
}
