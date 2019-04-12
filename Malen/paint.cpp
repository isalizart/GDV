#include <QPushButton> 
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include "paint.h"
#include "canvas.h"


/** c'tor */
Paint::Paint(QWidget *parent)
	: QWidget(parent)
{
	// instantiate Canvas and button
	viewport = new Canvas();

	btnClearCanvas = new QPushButton("&Clear Canvas");

	cobPrimModes = new QComboBox();
	cobPrimModes->addItem(tr("Line"), Canvas::LINE);
	cobPrimModes->addItem(tr("Triangle"), Canvas::TRIANGLE);
	cobPrimModes->addItem(tr("Rectangle"), Canvas::RECTANGLE);
	cobPrimModes->addItem(tr("Polygon"), Canvas::POLYGON);
	cobPrimModes->addItem(tr("Circle"), Canvas::CIRCLE);
	cobPrimModes->addItem(tr("Freehand"), Canvas::FREE_HAND);

	lblPrimModes = new QLabel("Primitive Mode");
	lblPrimModes->setBuddy(cobPrimModes);

	// create layout and add gui elements to it
	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->setColumnStretch(0, 3);

	mainLayout->addWidget(viewport, 0, 0, 1, 3);
	mainLayout->addWidget(lblPrimModes, 1, 1, Qt::AlignRight);
	mainLayout->addWidget(cobPrimModes, 1, 2);
	mainLayout->addWidget(btnClearCanvas, 2, 1, 1, 2, Qt::AlignRight);

	// add layout to this widget instance
	setLayout(mainLayout);
	
	// connect button click event to draw handler
	connect(btnClearCanvas, SIGNAL(clicked()), this, SLOT(clearBtnPressed()));
	// connect list view to event handler
	connect(cobPrimModes, SIGNAL(activated(int)), this, SLOT(primModeChanged()));
}

/** d'tor */
Paint::~Paint()
{
}

/** method for handling button clicked event */
void Paint::clearBtnPressed()
{
	viewport->clearCanvas();

	// force redraw
	update();
}

void Paint::primModeChanged()
{
	int mode = cobPrimModes->itemData(
			   cobPrimModes->currentIndex(), Qt::UserRole).toInt();
	viewport->setPrimitiveMode(mode);
}
