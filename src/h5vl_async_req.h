/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright (C) 2020, Lawrence Berkeley National Laboratory.                *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of AsyncVOL. The full AsyncVOL copyright notice,      *
 * including terms governing use, modification, and redistribution, is       *
 * contained in the file COPYING at the root of the source code distribution *
 * tree.                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* Async request callbacks */

#pragma once

#include <H5VLpublic.h>

typedef struct H5VL_async_req_t {
    int isReq;
    H5VL_async_t* async_obj;
    TW_Task_handle_t req_task;
    H5VL_async_req_stat_t req_stat;
    uint64_t op_exec_ts;
    uint64_t op_exec_time;
    hid_t error_stack;
} H5VL_async_req_t;
//typedef H5VL_async_t H5VL_async_req_t ;

herr_t H5VL_async_request_wait (void *req, uint64_t timeout, H5VL_request_status_t *status);
herr_t H5VL_async_request_notify (void *obj, H5VL_request_notify_t cb, void *ctx);
herr_t H5VL_async_request_cancel (void *req);
herr_t H5VL_async_request_specific (void *req,
									H5VL_request_specific_t specific_type,
									va_list arguments);
herr_t H5VL_async_request_optional (void *req, H5VL_request_optional_t opt_type, va_list arguments);
herr_t H5VL_async_request_free (void *req);
H5VL_async_req_t* H5VL_async_new_req(void *under_obj, hid_t under_vol_id);
