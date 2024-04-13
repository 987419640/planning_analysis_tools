#include "planning_uviz.h"

void
planningUviz::drawEgoState(QPainter &painter)
{
    QPen pen;

    pen.setColor(Qt::green);
    pen.setWidthF(3);
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);

    postion_t point[4], local_point[4];
    int vertex_size;

    generate_rect_polygon_by_pos_and_head(
            point, &vertex_size, &uviz_data->uviz_ego);

    for (int i = 0; i < vertex_size; i++)
    {
        local_point[i].x = convertXCoordinateUsingMapCenterPoint(point[i]);
        local_point[i].y = convertYCoordinateUsingMapCenterPoint(point[i]);
    }

    mGuiPainter.drawPolygon(painter, local_point, vertex_size);
}
