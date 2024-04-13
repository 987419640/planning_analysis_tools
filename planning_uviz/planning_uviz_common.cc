#include "planning_uviz.h"

double
planningUviz::convertXCoordinateUsingMapCenterPoint(const pose_t &pose)
{
    return (pose.pos.x - mMapCenterX + mWinXBias) * mScale + mWinWidth / 2.0;
}

double
planningUviz::convertXCoordinateUsingMapCenterPoint(const postion_t &pos)
{
    return (pos.x - mMapCenterX + mWinXBias) * mScale + mWinWidth / 2.0;
}

double
planningUviz::convertYCoordinateUsingMapCenterPoint(const pose_t &pose)
{
    return (-1.0 * (pose.pos.y - mMapCenterY) + mWinYBias) * mScale
            + mWinHeight / 2.0;
}

double
planningUviz::convertYCoordinateUsingMapCenterPoint(const postion_t &pos)
{
    return (-1.0 * (pos.y - mMapCenterY) + mWinYBias) * mScale
            + mWinHeight / 2.0;
}