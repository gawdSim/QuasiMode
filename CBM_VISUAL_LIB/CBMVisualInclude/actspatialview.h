#ifndef ACTSPATIALVIEW_H
#define ACTSPATIALVIEW_H

#include <vector>
#include <iostream>
#include <string>
#include <sstream>

#include <QtGui/QWidget>
#include <QtGui/QPainter>
#include <QtGui/QPaintEvent>
#include <QtGui/QColor>
#include <QtGui/QPixmap>

#include <CXXToolsInclude/stdDefinitions/pstdint.h>

#include "uic/ui_actspatialview.h"

class ActSpatialView : public QWidget
{
    Q_OBJECT

public:
    ActSpatialView(std::vector<int> xDims, std::vector<int> yDims,
    		std::vector<int> sizes, std::vector<QColor> colors, std::string pathP,
    		QWidget *parent = 0);
    ~ActSpatialView();

public slots:
	void drawActivity(std::vector<ct_uint8_t> aps, int cellT, bool refresh);
	void saveBuf();

private:
    Ui::ActSpatialViewClass ui;

    QPixmap *backBuf;
    std::vector<float> gridScaleX;
    std::vector<float> gridScaleY;
    std::vector<int> cellXDims;
    std::vector<int> cellYDims;

    std::vector<QColor> cellColors;
    std::vector<int> cellPaintSizes;

    int maxXDim;
    int maxYDim;

    int frameCounter;

    std::stringstream fileName;
    std::string pathPrefix;

    ActSpatialView();

protected:
    void paintEvent(QPaintEvent *);
};

#endif // ACTSPATIALVIEW_H
