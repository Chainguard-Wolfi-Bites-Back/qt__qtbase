# Copyright (C) 2022 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

if(QT_FEATURE_future)
    add_subdirectory(qfuture)
endif()
add_subdirectory(qmutex)
add_subdirectory(qreadwritelock)
add_subdirectory(qthreadstorage)
add_subdirectory(qthreadpool)
add_subdirectory(qwaitcondition)
