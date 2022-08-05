#ifndef BUFDISPWINDOW_H
#define BUFDISPWINDOW_H

#include <QtGui/QPaintEvent>
#include <QtGui/QPixmap>
#include <QtGui/QPainter>
#include <QtCore/QString>

#include <CXXToolsInclude/stdDefinitions/pstdint.h>

#include <QtGui/QWidget>
#include "./uic/ui_bufdispwindow.h"

class BufDispWindow : public QWidget
{
    Q_OBJECT

public:
    BufDispWindow(QPixmap *buf, QString wt, QWidget *parent = 0);
    ~BufDispWindow();

    void switchBuf(QPixmap *newBuf);

private:
    Ui::BufDispWindowClass ui;
    QPixmap *backBuf;

    BufDispWindow();

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // BUFDISPWINDOW_H
