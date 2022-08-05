#include "../CBMVisualInclude/connectivityview.h"
#include "../CBMVisualInclude/moc/moc_connectivityview.h"

using namespace std;

ConnectivityView::ConnectivityView(vector<unsigned int>gridXs, vector<unsigned int> gridYs,
		vector<unsigned int> dispSizes, vector<QColor> dispColors,
		unsigned int windowWidth, unsigned windowHeight, QColor backgroundColor, QString windowTitle, QObject *parent)
    : QObject(parent)
{
	wW=windowWidth;
	wH=windowHeight;
	bgC=backgroundColor;
	wt=windowTitle;

	window=new SpatialView(wW, wH, bgC, wt);

	gXs=gridXs;
	gYs=gridYs;
	dispSs=dispSizes;
	dispCs=dispColors;
}

ConnectivityView::~ConnectivityView()
{
	delete window;
}


void ConnectivityView::updateDisp(vector<vector<unsigned int> > cellInds, vector<unsigned int> cellTypes)
{
	window->blankView();

	for(int i=0; i<cellInds.size(); i++)
	{
		window->updateView(gXs[cellTypes[i]], gYs[cellTypes[i]], cellInds[i], dispSs[cellTypes[i]], dispCs[cellTypes[i]]);
	}
}

