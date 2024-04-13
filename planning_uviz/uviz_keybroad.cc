#include "planning_uviz.h"

#define modifiers_str(state) \
    (state == Qt::NoModifier ? "None" : \
     state == Qt::ShiftModifier ? "Shift" : \
     state == Qt::ControlModifier ? "Ctrl" : \
     state == Qt::AltModifier ? "Alt" : "Unknown")

void
planningUviz::keyPressEvent(QKeyEvent *event)
{
    printf("modifiers:%s, press key: (%d)\n",
            modifiers_str(event->modifiers()), event->key());
    switch (event->modifiers())
    {
    case Qt::NoModifier:
        normalKeyPressEvent(event);
        break;
    case Qt::ShiftModifier:
        keyWithShiftPressEvent(event);
        break;
    case Qt::ControlModifier:
        keyWithCtrlPressEvent(event);
        break;
    case Qt::AltModifier:
        break;
    default:
        break;
    }
}

void
planningUviz::normalKeyPressEvent(QKeyEvent *event)
{
    printf("== normal Key==\n");
    bool is_update = false;
    switch (event->key())
    {
    case Qt::Key_Minus: // -
        mScale /= 2.0;
        is_update = true;
        printf(" Qt::Key_Less scale :%lf\n", mScale);
        break;
    case Qt::Key_Space:
        mScale = 1.0;
        mWinXBias = 0.0;
        mWinYBias = 0.0;
        is_update = true;
    default:
        break;
    }

    if (is_update) updateWin();
}

void
planningUviz::keyWithShiftPressEvent(QKeyEvent *event)
{
    bool is_update = false;
    switch (event->key())
    {
    case Qt::Key_Plus: // + (shift + =)
        mScale *= 2.0;
        is_update = true;
        printf("Qt::Key_Equal scale :%lf\n", mScale);
        break;

    default:
        break;
    }

    if (is_update) updateWin();
}

void
planningUviz::keyWithCtrlPressEvent(QKeyEvent *event)
{
    bool is_update = false;
    switch (event->key())
    {
    case Qt::Key_Space: // (ctrl + =)
        break;
    default:
        break;
    }

    if (is_update) updateWin();
}