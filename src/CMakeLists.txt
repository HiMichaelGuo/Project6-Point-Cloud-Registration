set(SOURCE_FILES
    "registration.cu"
    "registration.h"
    "registrationTools.h"
    "pointcloud.cpp"
    "pointcloud.h"
    "kdtree.cpp"
    "kdtree.h"
    )

cuda_add_library(src
    ${SOURCE_FILES}
    OPTIONS -arch=sm_20
    )
