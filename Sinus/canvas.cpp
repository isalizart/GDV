#include <QPainter>
#include <math.h>

#include "canvas.h"

Canvas::Canvas(QWidget *parent)
	: QFrame(parent),
	  wMin(0, 0), wMax(1, 1)
{
	setFrameStyle(QFrame::Box);
}

Canvas::~Canvas()
{
}

QSize Canvas::minimumSizeHint() const
{
	return QSize(200, 200);
}

QSize Canvas::sizeHint() const
{
	return QSize(640, 480);
}

void Canvas::setWorld(const QPointF &min, const QPointF &max)
{
	wMin.rx() = min.x();
	wMin.ry() = min.y();

	wMax.rx() = max.x();
	wMax.ry() = max.y();
}

void Canvas::paintEvent(QPaintEvent *event)
{
	QFrame::paintEvent(event);

	// TODO; implement the following drawing functionality!

	// first draw white background 
	
	// then draw axis of abscissas 

	// finally draw sine function

}

QPoint Canvas::WC_to_DC(const QPointF &wc)
{
	float wx0 = wMin.x(), 
		  wx1 = wMax.x(), 
		  wy0 = wMin.y(), 
		  wy1 = wMax.y();
	int dx0, dx1, dy0, dy1, x = 0, y = 0;

	// TODO; calculate window-viewport transformation for point (x, y)!

	return QPoint(x, y);
}

QPointF Canvas::DC_to_WC(const QPoint &dc)
{
	// TODO; calculate inverse transform (optional)
	return QPointF(0, 0);
}
