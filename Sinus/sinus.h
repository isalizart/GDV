#ifndef SINUS_H
#define SINUS_H

#include <QWidget>

class QPushButton;
class QLabel;
class QLineEdit;
class Canvas;

class Sinus : public QWidget
{
	Q_OBJECT

public:
	Sinus(QWidget *parent = 0);
	~Sinus();

private slots:
	void drawBtnPressed();

private:
	Canvas *viewport;

	QPushButton *btnDrawSin;
	QLabel *lblMinX;
	QLabel *lblMaxX;
	QLabel *lblMinY;
	QLabel *lblMaxY;
	QLineEdit *ledMinX;
	QLineEdit *ledMaxX;
	QLineEdit *ledMinY;
	QLineEdit *ledMaxY;
};

#endif // SINUS_H
