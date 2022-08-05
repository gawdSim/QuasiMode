/*
 * spactialview.h
 *
 *  Created on: Jan 8, 2013
 *      Author: consciousness
 */

#ifndef SPATIALVIEW_H_
#define SPATIALVIEW_H_

#include <vector>

#include <QtGui/QWidget>
#include <QtGui/QPainter>
#include <QtGui/QPixmap>
#include <QtGui/QColor>
#include <QtCore/QString>
#include <QtGui/QTransform>

#include <CXXToolsInclude/stdDefinitions/pstdint.h>

#include "bufdispwindow.h"

class SpatialView : public QObject
{
	Q_OBJECT

public:
	SpatialView(unsigned int windowWidth, unsigned int windowHeight,
			QColor backgroundColor, QString windowTitle, QObject *parent=0);

	~SpatialView();

public slots:
	void updateView(unsigned int dispGridX, unsigned int dispGridY, std::vector<ct_uint32_t> cellInds,
			unsigned int dispSize, QColor dispColor);
	void updateWindowTitle(QString windowTitle);
	void blankView();
	void blankView(QColor backgroundColor);
	void updateWindowSize(unsigned int windowWidth, unsigned int windowHeight);
private:
	SpatialView();

	unsigned int wW;
	unsigned int wH;
	QColor bgColor;
	QString wt;

	BufDispWindow *disp;
	QPixmap *buf;
};

#endif /* SPATIALVIEW_H_ */
