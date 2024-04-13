#pragma once
#include <math.h>

typedef struct Postion
{
    double x;
    double y;
} postion_t;

typedef struct Pose
{
    postion_t pos;
    double theta;
} pose_t;


/*
   *                 front_edge
   *              A +---------+ B
   *                |         |
   *                /         /
   *                |         |
   *     left_edge  |         |  right_edge
   *                |         |
   *                |    X    |     x: center
   *                |--->.<---|
   *                |         |
   *              D +---------+ C
   *                 back_edge
*/
/* veh param */
typedef struct Ego_Param
{
    double height;
    double front_edge_to_center;
    double back_edge_to_center;
    double left_edge_to_center;
    double right_edge_to_center;
    double max_steer_angle;
} ego_param_t;

bool
generate_rect_polygon_by_pos_and_head(postion_t *point, int *vertex_size,
        const pose_t *ego_pose);