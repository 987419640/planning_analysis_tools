#include "base.h"

bool
generate_rect_polygon_by_pos_and_head(
        postion_t *point, int *vertex_size, const pose_t *ego_pose)
{
    ego_param_t param;

    param.height = 1.8;
    param.front_edge_to_center = 3.6;
    param.back_edge_to_center = 1.025;
    param.left_edge_to_center = 0.9;
    param.right_edge_to_center = 0.9;

    point[0].x = ego_pose->pos.x
            + param.front_edge_to_center * cos(ego_pose->theta)
            - param.left_edge_to_center * sin(ego_pose->theta);
    point[0].y = ego_pose->pos.y
            + param.front_edge_to_center * sin(ego_pose->theta)
            + param.left_edge_to_center * cos(ego_pose->theta);

    point[1].x = ego_pose->pos.x
            + param.front_edge_to_center * cos(ego_pose->theta)
            + param.right_edge_to_center * sin(ego_pose->theta);
    point[1].y = ego_pose->pos.y
            + param.front_edge_to_center * sin(ego_pose->theta)
            - param.right_edge_to_center * cos(ego_pose->theta);

    point[2].x = ego_pose->pos.x
            - param.back_edge_to_center * cos(ego_pose->theta)
            + param.right_edge_to_center * sin(ego_pose->theta);
    point[2].y = ego_pose->pos.y
            - param.back_edge_to_center * sin(ego_pose->theta)
            - param.right_edge_to_center * cos(ego_pose->theta);

    point[3].x = ego_pose->pos.x
            - param.back_edge_to_center * cos(ego_pose->theta)
            - param.left_edge_to_center * sin(ego_pose->theta);
    point[3].y = ego_pose->pos.y
            - param.back_edge_to_center * sin(ego_pose->theta)
            + param.left_edge_to_center * cos(ego_pose->theta);

    *vertex_size = 4;

    return true;
}