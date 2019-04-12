#include <QPushButton> 
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>

#include "sinus.h"
#include "canvas.h"


/** c'tor */
Sinus::Sinus(QWidget *parent)
	: QWidget(parent)
{
	// instantiate Canvas and button
	viewport = new Canvas();
	btnDrawSin = new QPushButton("&Draw Sinus");

	// instantiate elements for setting world window
	ledMinX = new QLineEdit("0");
	lblMinX = new QLabel("World MinX");
	lblMinX->setBuddy(ledMinX);

	ledMinY = new QLineEdit("0");
	lblMinY = new QLabel("World MinY");
	lblMinY->setBuddy(ledMinY);

	ledMaxX = new QLineEdit("1");
	lblMaxX = new QLabel("World MaxX");
	lblMaxX->setBuddy(ledMaxX);

	ledMaxY = new QLineEdit("1");
	lblMaxY = new QLabel("World MaxY");
	lblMaxY->setBuddy(ledMaxY);

	// create layout and add gui elements to it
	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->setColumnStretch(0, 3);

	mainLayout->addWidget(viewport, 0, 0, 1, 3);
	mainLayout->addWidget(lblMinX, 2, 0, Qt::AlignRight);
	mainLayout->addWidget(ledMinX, 2, 2);
	mainLayout->addWidget(lblMinY, 3, 0, Qt::AlignRight);
	mainLayout->addWidget(ledMinY, 3, 2);
	mainLayout->addWidget(lblMaxX, 4, 0, Qt::AlignRight);
	mainLayout->addWidget(ledMaxX, 4, 2);
	mainLayout->addWidget(lblMaxY, 5, 0, Qt::AlignRight);
	mainLayout->addWidget(ledMaxY, 5, 2);
	mainLayout->addWidget(btnDrawSin, 7, 1, 1, 2, Qt::AlignRight);

	// add layout to this widget instance
	setLayout(mainLayout);
	
	// connect button click event to draw handler
	connect(btnDrawSin, SIGNAL(clicked()), this, SLOT(drawBtnPressed()));
}

/** d'tor */
Sinus::~Sinus()
{
}

/** method for handling button clicked event */
void Sinus::drawBtnPressed()
{
	QPointF min, max;

	min.setX(ledMinX->text().toFloat());
	min.setY(ledMinY->text().toFloat());

	max.setX(ledMaxX->text().toFloat());
	max.setY(ledMaxY->text().toFloat());

	// update world window in canvas instance
	viewport->setWorld(min, max);

	// force redraw
	update();
}
