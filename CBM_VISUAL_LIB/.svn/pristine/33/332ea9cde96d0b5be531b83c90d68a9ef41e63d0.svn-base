/*
 * spatialview.cpp
 *
 *  Created on: Jan 8, 2013
 *      Author: consciousness
 */

#include "../CBMVisualInclude/spatialview.h"
#include "../CBMVisualInclude/moc/moc_spatialview.h"

using namespace std;

SpatialView::SpatialView(unsigned int windowWidth, unsigned int windowHeight,
		QColor backgroundColor, QString windowTitle, QObject *parent)
	:QObject(parent)
{
	buf=new QPixmap(10, 10);
	disp=new BufDispWindow(buf, "");

	updateWindowSize(windowWidth, windowHeight);
	blankView(backgroundColor);
	updateWindowTitle(windowTitle);
}

SpatialView::~SpatialView()
{
	disp->close();
	delete disp;
}

void SpatialView::updateView(unsigned int dispGridX, unsigned int dispGridY,
		vector<ct_uint32_t> cellInds, unsigned int dispSize, QColor dispColor)
{
	QTransform paintTM;
	QPainter p;

	disp->show();

	paintTM.reset();
	paintTM.scale(wW/((float)dispGridX), wH/((float) dispGridY));

	p.begin(buf);

	p.setWorldTransform(paintTM);
	for(int i=0; i<cellInds.size(); i++)
	{
		unsigned int x;
		unsigned int y;

		x=cellInds[i]%dispGridX;
		y=cellInds[i]/dispGridX;
		p.fillRect(x, y, dispSize, dispSize, dispColor);
	}
	p.end();

	disp->update();
}

void SpatialView::updateWindowSize(unsigned int windowWidth, unsigned int windowHeight)
{
	wW=windowWidth;
	wH=windowHeight;

	buf=new QPixmap(wW, wH);

	disp->switchBuf(buf);
	disp->show();
	disp->update();
}

void SpatialView::blankView()
{
	buf->fill(bgColor);
	disp->show();
	disp->update();
}

void SpatialView::blankView(QColor backgroundColor)
{
	bgColor=backgroundColor;

	blankView();
}

void SpatialView::updateWindowTitle(QString windowTitle)
{
	wt=windowTitle;

	disp->setWindowTitle(wt);
	disp->show();
	disp->update();
}
