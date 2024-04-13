#include "planning_uviz.h"
#include "ui_planning_uviz.h"

planningUviz::planningUviz(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::planningUviz)
{
    ui->setupUi(this);

    uviz_data = get_uviz_data();

    mScale = 5.0;
    mTimer = new QTimer();
    mTimer->setInterval(100);
    connect(mTimer, &QTimer::timeout, this, &planningUviz::timeoutfunc);
    mTimer->start(100);

    mWinXBias = 0.0;
    mWinYBias = 0.0;
    update_view_point();
}

planningUviz::~planningUviz()
{
    delete ui;
}

void
planningUviz::resizeEvent(QResizeEvent *event)
{
    mWinWidth = event->size().width();
    mWinHeight = event->size().height();
    printf("(%d, %d)\n", mWinWidth, mWinHeight);
}

void
planningUviz::update_view_point()
{
    mMapCenterX = uviz_data->uviz_ego.pos.x;
    mMapCenterY = uviz_data->uviz_ego.pos.y;
}

void
planningUviz::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    update_view_point();
    drawObstacles(painter);
    drawEgoState(painter);

#if 0
    // test code
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidthF(5);
    painter.setPen(pen);

    painter.drawLine(QPoint(0, 0), QPoint(100 * 4, 100 * 4));
    painter.drawText(100, 500, "Nine pineapples");
#endif
}

/* timeout func */
void
planningUviz::timeoutfunc()
{
    // printf(" timeout func exec \n");
    this->update();
}

void
planningUviz::updateWin()
{
    this->update();
}