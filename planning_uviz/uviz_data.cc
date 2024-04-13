#include "uviz_data.h"

static uviz_data_t uviz_data;

const uviz_data_t *
get_uviz_data()
{
    return &uviz_data;
}

void
set_uviz_ego_pose(pose_t *pose)
{
    uviz_data.uviz_ego = *pose;
}

void
set_uviz_obj_pose(pose_t *pose)
{
    uviz_data.uviz_obj_pose[0] = pose[0];
    uviz_data.uviz_obj_pose[1] = pose[1];
}