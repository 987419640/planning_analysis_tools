#include "planning_uviz.h"

void
planningUviz::drawObstacles(QPainter &painter)
{
    QPen pen;

    pen.setColor(Qt::black);
    pen.setWidthF(3);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);

    postion_t point[4], local_point[4];
    int vertex_size;

    for (int i = 0; i < 2; i++)
    {
        generate_rect_polygon_by_pos_and_head(
                point, &vertex_size, &uviz_data->uviz_obj_pose[i]);

        for (int j = 0; j < vertex_size; j++)
        {
            local_point[j].x = convertXCoordinateUsingMapCenterPoint(point[j]);
            local_point[j].y = convertYCoordinateUsingMapCenterPoint(point[j]);
        }

        mGuiPainter.drawPolygon(painter, local_point, vertex_size);
    }

}