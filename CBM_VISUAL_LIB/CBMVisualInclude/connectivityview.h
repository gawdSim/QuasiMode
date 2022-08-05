#ifndef CONNECTIVITYVIEW_H
#define CONNECTIVITYVIEW_H

#include <vector>

#include <QtGui/QWidget>
#include <QtGui/QPainter>
#include <QtGui/QPixmap>
#include <QtGui/QColor>
#include <QtCore/QString>
#include <QtGui/QTransform>

#include <CXXToolsInclude/stdDefinitions/pstdint.h>

#include "spatialview.h"
#include "bufdispwindow.h"

class ConnectivityView : public QObject
{
    Q_OBJECT

public:
    ConnectivityView(std::vector<unsigned int>gridXs, std::vector<unsigned int> gridYs,
    		std::vector<unsigned int> dispSizes, std::vector<QColor> dispColors,
    		unsigned int windowWidth, unsigned windowHeight, QColor backgroundColor,
    		QString windowTitle, QObject *parent=0);
    ~ConnectivityView();

public slots:
	void updateDisp(std::vector<std::vector<unsigned int> > cellInds, std::vector<unsigned int>cellTypes);


private:
    ConnectivityView();

    SpatialView *window;

    std::vector<unsigned int> gXs;
    std::vector<unsigned int> gYs;
    std::vector<unsigned int> dispSs;
    std::vector<QColor> dispCs;

    unsigned int wH;
    unsigned int wW;
    QColor bgC;
    QString wt;
};

#endif // CONNECTIVITYVIEW_H
