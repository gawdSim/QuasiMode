#include "../CBMVisualInclude/actspatialview.h"
#include "../CBMVisualInclude/moc/moc_actspatialview.h"

using namespace std;
ActSpatialView::ActSpatialView(vector<int> xDims, vector<int> yDims,
		vector<int> sizes, vector<QColor> colors, string pathP, QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);



	cellXDims=xDims;
	cellYDims=yDims;
	cellColors=colors;
	cellPaintSizes=sizes;

	maxXDim=0;
	maxYDim=0;

	frameCounter=0;

	pathPrefix=pathP;

	for(int i=0; i<cellXDims.size(); i++)
	{
		if(cellXDims[i]>maxXDim)
		{
			maxXDim=cellXDims[i];
		}

		if(cellYDims[i]>maxYDim)
		{
			maxYDim=cellYDims[i];
		}
	}

	cerr<<cellXDims.size()<<" "<<cellYDims.size()<<endl;
	gridScaleX.resize(cellXDims.size());
	gridScaleY.resize(cellXDims.size());

	for(int i=0; i<cellXDims.size(); i++)
	{
		gridScaleX[i]=((float)cellXDims[i])/maxXDim;
		gridScaleY[i]=((float)cellYDims[i])/maxYDim;
	}

	backBuf=new QPixmap(maxXDim, maxYDim);

	cerr<<maxXDim<<endl;
	cerr<<maxYDim<<endl;

	this->setFixedSize(backBuf->width(), backBuf->height());
	this->setAutoFillBackground(true);

//	this->show();
//	this->update();
//	cerr<<"here3"<<endl;
}

ActSpatialView::~ActSpatialView()
{
	delete backBuf;
}

void ActSpatialView::drawActivity(vector<ct_uint8_t> aps, int cellT, bool refresh)
{
	QPainter p;
	if(refresh)
	{
		backBuf->fill(Qt::black);
	}

	p.begin(backBuf);
	p.setPen(cellColors[cellT]);

	if(cellPaintSizes[cellT]<2)
	{
		for(int i=0; i<aps.size(); i++)
		{
			if(aps[i])
			{
				p.drawPoint((int)(((i%cellXDims[cellT])+0.5)/gridScaleX[cellT]+1),
						(int)(((i/cellXDims[cellT])+0.5)/gridScaleY[cellT]+1));
			}
		}
	}
	else
	{
		for(int i=0; i<aps.size(); i++)
		{
			if(aps[i])
			{
				p.fillRect((int)(((i%cellXDims[cellT])+0.5)/gridScaleX[cellT]+1),
						(int)(((i/cellXDims[cellT])+0.5)/gridScaleY[cellT]+1),
						cellPaintSizes[cellT], cellPaintSizes[cellT], cellColors[cellT]);
			}
		}
	}

	p.end();
	this->update();
}

void ActSpatialView::saveBuf()
{
	QImage copied, original;
	fileName.str("");

	fileName<<pathPrefix<<frameCounter<<".png";

	original=backBuf->toImage();
	copied=original.copy(0, 0, 1024, 512);

	frameCounter++;

	copied.save(fileName.str().c_str(), 0, 100);
}

void ActSpatialView::paintEvent(QPaintEvent *event)
{
	QPainter p(this);

	p.drawPixmap(event->rect(), *backBuf, event->rect());
}

