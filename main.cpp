#include "views/main/MainWindow.h"

#include <QApplication>
#include <QtWidgets/QStyleFactory>
#include<QDebug>
#include <QStyle>
#include <logics/auth/Registrator.h>

int main(int argc, char* argv[]) {
	QApplication a(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    qDebug() << QApplication::style()->objectName();
	MainWindow w;
	w.show();
	return QApplication::exec();
}
