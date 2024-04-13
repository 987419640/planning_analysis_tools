#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include "base.h"
#include "planning_uviz/planning_uviz_interface.h"
#include "planning_uviz/uviz_data.h"

#include <stdlib.h>

using namespace std;
static pthread_t planning_uviz_tid;

pthread_mutex_t update_data_lock;

#ifdef __cplusplus
extern "C" {
#endif

void *
planning_uviz_func(void *);

void
pthread_create_for_planning_uviz();

void
pthread_join_for_planning_uviz();

#ifdef __cplusplus
}
#endif

void *
planning_uviz_func(void *)
{
    int argc = 0;
    char **argv = NULL;

    planning_uviz_main(argc, argv);

    return NULL;
}

void pthread_create_for_planning_uviz()
{
    int32_t err;
    err = pthread_create(&planning_uviz_tid, NULL, planning_uviz_func, NULL);

    if (err)
    {
        cout << "planning_uviz pthread create failed (" << strerror(err) << ")";
        exit(1);
    }
    else
    {
        cout << "planning_uviz pthread[" << planning_uviz_tid << "] create success!";
    }
}

void
pthread_join_for_planning_uviz()
{
    pthread_join(planning_uviz_tid, NULL);
    cout << "planning_uviz pthread exit success!";
}

int main(int argc, char *argv[])
{
    int i = 0;
    pose_t veh_pos = { {10000, 20000}, 0.0 },
           obj_pose[2] = { { {10000, 20010}, 0.0 }, { {10000, 19990}, 0.0 } };

    pthread_mutex_init(&update_data_lock, NULL);
    set_uviz_ego_pose(&veh_pos);
    set_uviz_obj_pose(obj_pose);

    pthread_create_for_planning_uviz();
    while (true) {
        if (i == 10)
        {
            pthread_mutex_lock(&update_data_lock);

            // Simulate updating vehicle and obstacle data
            veh_pos.pos.x += rand() / (RAND_MAX * 1.0);
            obj_pose[0].pos.x += rand() / (RAND_MAX * 1.0);
            obj_pose[1].pos.x += rand() / (RAND_MAX * 1.0);
            set_uviz_ego_pose(&veh_pos);
            set_uviz_obj_pose(obj_pose);

            i = 0;
            pthread_mutex_unlock(&update_data_lock);

#if 0
    printf("\n=========  vehicle info start output ========= \n");
    printf("ego: (%lf, %lf) \n", veh_pos.pos.x, veh_pos.pos.y);

    printf("obj info: (%lf, %lf), (%lf, %lf) \n", obj_pose[0].pos.x, obj_pose[0].pos.y,
            obj_pose[1].pos.x, obj_pose[1].pos.y);

    printf("=========  vehicle info end output ========= \n");
#endif
        }
        i++;

        usleep(100);
    }
    pthread_mutex_destroy(&update_data_lock);
    pthread_join_for_planning_uviz();

    return 0;
}