#include "../CBMVisualInclude/acttemporalview.h"
#include "../CBMVisualInclude/moc/moc_acttemporalview.h"

using namespace std;

ActTemporalView::ActTemporalView(int nCells, int pixelHPerCell, int nTSteps,
		int wW, int wH, QColor pColor, QString title, QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);

	vector<int> vts;
	vector<QColor> vcs;

	vts.clear();
	vcs.clear();

	construct(nCells, pixelHPerCell, nTSteps, wW, wH, vts, vcs, pColor, title, parent);
}

ActTemporalView::ActTemporalView(int nCells, int pixelHPerCell, int nTSteps, int wW, int wH,
		std::vector<int> vertLineTs, std::vector<QColor> vertLineColors,
		QColor pColor, QString title, QWidget *parent)
{
	ui.setupUi(this);

	construct(nCells, pixelHPerCell, nTSteps, wW, wH, vertLineTs, vertLineColors,
			pColor, title, parent);
}

ActTemporalView::~ActTemporalView()
{
	delete backBuf;
}

void ActTemporalView::setVertLines(vector<int> vertLineTs, vector<QColor> vertLineColors)
{
	vLineTs=vertLineTs;
	vLineColors=vertLineColors;
}

void ActTemporalView::drawRaster(vector<ct_uint8_t> aps, int t)
{
	QPainter p;
	t=t%numTimeSteps;

	p.begin(backBuf);
	p.setWorldTransform(logicalToPaintTrans);

	p.setPen(paintColor);
	for(int i=0; i<numCells; i++)
	{
		if(aps[i])
		{
			p.drawPoint(t, i);
		}
	}
	p.end();

	scrollUpdate(t);
}

void ActTemporalView::drawVmRaster(vector<ct_uint8_t> aps, vector<float> vmScaled, int t)
{
	QPainter p;
	t=t%numTimeSteps;

	p.begin(backBuf);
	p.setWorldTransform(logicalToPaintTrans);
	p.setPen(paintColor);


	for(int i=0; i<numCells; i++)
	{
		p.drawPoint(t, (i+vmScaled[i])*pixelHeightPerCell);
		if(aps[i])
		{
			p.fillRect(t, (i+vmScaled[i])*pixelHeightPerCell,
					logicalToWindowRatio, pixelHeightPerCell, paintColor);
		}
	}

	scrollUpdate(t);
}

void ActTemporalView::drawPoint(int t, float percentHeight, QColor pointColor)
{
	QPainter p;
	t=t%numTimeSteps;

	p.begin(backBuf);
	p.setWorldTransform(logicalToPaintTrans);

	p.setPen(pointColor);

	p.drawPoint(t, percentHeight * windowHeight);

	p.end();

	scrollUpdate(t);
}

void ActTemporalView::drawVertLine(int t, QColor lineColor)
{
	QPainter p;
	t=t%numTimeSteps;

	p.begin(backBuf);
	p.setWorldTransform(logicalToPaintTrans);

	p.setPen(lineColor);

	p.drawLine(t%numTimeSteps, 0, t%numTimeSteps, logicalHeight);

	p.end();

	scrollUpdate(t);
}

void ActTemporalView::toggleVisible()
{
    if (isVisible())
        hide();
    else 
        show();
}

void ActTemporalView::drawBlank(QColor blankColor)
{
	backBuf->fill(blankColor);

	for(int i=0; i<vLineTs.size(); i++)
	{
		drawVertLine(vLineTs[i], vLineColors[i]);
	}

	this->update();
}

void ActTemporalView::scrollUpdate(int t)
{
	QRect updateArea(logicalToPaintTrans.mapRect(QRect(t%numTimeSteps, 0, 1, windowHeight)));

	if(updateArea.width()<1)
	{
//		updateArea.setX((t%numTimeSteps)-1);
		updateArea.setWidth(2);
	}

	this->update(updateArea);
}

void ActTemporalView::paintEvent(QPaintEvent *event)
{
	QPainter p(this);

	p.drawPixmap(event->rect(), *backBuf, event->rect());
}

void ActTemporalView::construct(int nCells, int pixelHPerCell, int nTSteps, int wW, int wH,
    		std::vector<int> vertLineTs, std::vector<QColor> vertLineColors,
    		QColor pColor, QString title, QWidget *parent)
{
	numCells=nCells;
	pixelHeightPerCell=pixelHPerCell;
	numTimeSteps=nTSteps;
	windowWidth=wW;
	windowHeight=wH;

	logicalWidth=numTimeSteps;
	logicalHeight=numCells*pixelHeightPerCell;

	logicalToWindowRatio=ceil(logicalWidth/((float)windowWidth));

	paintColor=pColor;

	backBuf=new QPixmap(windowWidth, windowHeight);
	logicalToPaintTrans.translate(0, windowHeight);
	logicalToPaintTrans.scale(1, -1);
	logicalToPaintTrans.scale(windowWidth/((float)logicalWidth), windowHeight/((float)logicalHeight));
	QString baseTitle = "CBM";

	setVertLines(vertLineTs, vertLineColors);

	this->setFixedSize(windowWidth, windowHeight);
	this->setAutoFillBackground(true);
	this->setWindowTitle(baseTitle.append(title));
}

