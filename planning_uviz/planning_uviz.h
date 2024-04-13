#ifndef PLANNINGUVIZ_H
#define PLANNINGUVIZ_H

#include <QMainWindow>
#include <QtGui>
#include <QEvent>
#include <QAction>

// draw related
#include <QPainter>
#include <QPen>

#include "uviz_data.h"
#include "QPainter_wrapper.h"

#define INVALID_MOUSE_PIXEL_VALUE    (-1)

QT_BEGIN_NAMESPACE
namespace Ui { class planningUviz; }
QT_END_NAMESPACE

class planningUviz : public QMainWindow
{
    Q_OBJECT

public:
    planningUviz(QWidget *parent = nullptr);
    ~planningUviz();

    void timeoutfunc();

    const uviz_data_t *uviz_data;

    // draw func
    double
    convertXCoordinateUsingMapCenterPoint(const pose_t &pose);
    double
    convertXCoordinateUsingMapCenterPoint(const postion_t &pos);

    double
    convertYCoordinateUsingMapCenterPoint(const pose_t &pose);
    double
    convertYCoordinateUsingMapCenterPoint(const postion_t &pos);

    void
    drawEgoState(QPainter &painter);
    void
    drawObstacles(QPainter &painter);
    void
    update_view_point();
    void
    updateWin();

    // 多态函数
    void
    paintEvent(QPaintEvent *event);
    void
    resizeEvent(QResizeEvent *event);

    void
    keyPressEvent(QKeyEvent *event);
    void
    normalKeyPressEvent(QKeyEvent *event);
    void
    keyWithShiftPressEvent(QKeyEvent *event);
    void
    keyWithCtrlPressEvent(QKeyEvent *event);
    void
    mousePressEvent(QMouseEvent *event);
    void
    mouseReleaseEvent(QMouseEvent *event);
    void
    wheelEvent(QWheelEvent *event);

    /* time */
    QTimer *mTimer;

    double mMapCenterX;
    double mMapCenterY;
    double mScale;
    int mWinWidth;
    int mWinHeight;
    double mWinXBias;
    double mWinYBias;

    // mouse
    int32_t mLMousePosX;
    int32_t mLMousePosY;
    int32_t mRMousePosX;
    int32_t mRMousePosY;
    int32_t mMMousePosX;
    int32_t mMMousePosY;

    bool mIsLMousePress;
    bool mIsRMousePress;
    bool mIsMMousePress;

    /* GuiQPainter */
    GuiQPainter mGuiPainter;

private:
    Ui::planningUviz *ui;
};
#endif // PLANNINGUVIZ_H
