#ifndef PAINT_H
#define PAINT_H

#include <QWidget>

class QPushButton;
class QComboBox;
class QLabel;
class Canvas;

class Paint : public QWidget
{
	Q_OBJECT

public:
	Paint(QWidget *parent = 0);
	~Paint();

private slots:
	void clearBtnPressed();
	void primModeChanged();

private:
	Canvas *viewport;

	QPushButton *btnClearCanvas;
	QComboBox *cobPrimModes;
	QLabel *lblPrimModes;
};

#endif // PAINT_H
