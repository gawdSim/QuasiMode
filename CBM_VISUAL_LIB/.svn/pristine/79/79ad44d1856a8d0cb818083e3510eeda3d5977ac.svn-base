#ifndef ACTTEMPORALVIEW_H
#define ACTTEMPORALVIEW_H

#include <vector>
#include <iostream>

#include <math.h>

#include <QtGui/QWidget>
#include <QtGui/QPainter>
#include <QtGui/QPaintEvent>
#include <QtGui/QColor>
#include <QtGui/QPixmap>
#include <QtCore/QRect>
#include <QtGui/QTransform>

#include <CXXToolsInclude/stdDefinitions/pstdint.h>

#include "uic/ui_acttemporalview.h"

class ActTemporalView : public QWidget
{
    Q_OBJECT

public:
    ActTemporalView(int nCells, int pixelHPerCell, int nTSteps, int wW, int wH, QColor pColor, QString title = "", QWidget *parent = 0);
    ActTemporalView(int nCells, int pixelHPerCell, int nTSteps, int wW, int wH,
    		std::vector<int> vertLineTs, std::vector<QColor> vertLineColors,
    		QColor pColor, QString title = "", QWidget *parent = 0);
    ~ActTemporalView();

public slots:
	void setVertLines(std::vector<int> ts, std::vector<QColor> lineColors);
	void drawRaster(std::vector<ct_uint8_t> aps, int t);
	void drawVmRaster(std::vector<ct_uint8_t> aps, std::vector<float> vmScaled, int t);
	void drawBlank(QColor blankColor);
	void drawPoint(int t, float percentHeight, QColor pointColor);
	void drawVertLine(int t, QColor lineColor);
        void toggleVisible();

protected:
	void paintEvent(QPaintEvent *);

private:
    Ui::ActTemporalViewClass ui;

    ActTemporalView();

    void scrollUpdate(int t);

    void construct(int nCells, int pixelhPerCell, int nTSteps, int wW, int wH,
    		std::vector<int> vertLineTs, std::vector<QColor> vertLineColors,
    		QColor pColor, QString title = "", QWidget *parent = 0);

    int pixelHeightPerCell;
    int numCells;
    int numTimeSteps;
    int windowWidth;
	int windowHeight;

    int logicalWidth;
    int logicalHeight;

    int logicalToWindowRatio;

    std::vector<int> vLineTs;
    std::vector<QColor> vLineColors;

    QColor paintColor;
    QPixmap *backBuf;
    QTransform logicalToPaintTrans;
};

#endif // ACTTEMPORALVIEW_H
