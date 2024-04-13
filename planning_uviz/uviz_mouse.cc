#include "planning_uviz.h"

void
planningUviz::mousePressEvent(QMouseEvent *event)
{
    if (event->button()== Qt::LeftButton)        //左键
    {
        mIsLMousePress = true;
        mLMousePosX = event->x();
        mLMousePosY = event->y();
    }
    else if(event->button() == Qt::RightButton)  //右键
    {
        mIsRMousePress = true;
        mRMousePosX = event->x();
        mRMousePosY = event->y();
    }
    else if(event->button() == Qt::MidButton)    //滚轮键
    {
        mIsMMousePress = true;
        mMMousePosX = event->x();
        mMMousePosY = event->y();
    }
}

void
planningUviz::mouseReleaseEvent(QMouseEvent *event)
{
    bool is_update = false;
    if (event->button() == Qt::LeftButton)       //左键
    {
        if (INVALID_MOUSE_PIXEL_VALUE != mLMousePosX
                && INVALID_MOUSE_PIXEL_VALUE != mLMousePosY)
        {
            mWinXBias += (event->x() - mLMousePosX) / mScale;
            mWinYBias += (event->y() - mLMousePosY) / mScale;
            is_update = true;
        }
        mIsLMousePress = false;
        mLMousePosX = INVALID_MOUSE_PIXEL_VALUE;
        mLMousePosY = INVALID_MOUSE_PIXEL_VALUE;
    }
    else if (event->button() == Qt::RightButton) //右键
    {
        mIsRMousePress = false;
    }
    else if (event->button() == Qt::MidButton)   //滚轮键
    {
        mIsMMousePress = false;
    }

    if (is_update) updateWin();
}

void
planningUviz::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().y() > 0)
    {
        mScale /= 2.0;
        updateWin();
    }
    else if (event->angleDelta().y() < 0)
    {
        mScale *= 2.0;
        updateWin();
    }
}