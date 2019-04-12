#include <QtWidgets/QApplication>

#include "sinus.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	Sinus w;
	w.show();
	return app.exec();
}
