#include "../CBMVisualInclude/bufdispwindow.h"
#include "../CBMVisualInclude/moc/moc_bufdispwindow.h"

BufDispWindow::BufDispWindow(QPixmap *buf, QString wt, QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);

	this->setWindowTitle(wt);

	backBuf=buf;

	this->setFixedSize(backBuf->width(), backBuf->height());
	this->setAutoFillBackground(true);

	this->show();
	this->update();
}

BufDispWindow::~BufDispWindow()
{
	delete backBuf;
}

void BufDispWindow::switchBuf(QPixmap *newBuf)
{
	delete backBuf;
	backBuf=newBuf;

	this->setFixedSize(newBuf->width(), newBuf->height());
	this->update();
}

void BufDispWindow::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	if(backBuf==0)
	{
		this->close();
		return;
	}

	painter.drawPixmap(event->rect(), *backBuf, event->rect());
}
