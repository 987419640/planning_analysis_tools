#pragma once

#include "../base.h"

typedef struct Uviz_Data
{
    pose_t uviz_ego;
    pose_t uviz_obj_pose[2];
} uviz_data_t;


#ifdef __cplusplus
extern "C" {
#endif

const uviz_data_t *
get_uviz_data();

void
set_uviz_ego_pose(pose_t *pose);

void
set_uviz_obj_pose(pose_t *pose);

#ifdef __cplusplus
}
#endif