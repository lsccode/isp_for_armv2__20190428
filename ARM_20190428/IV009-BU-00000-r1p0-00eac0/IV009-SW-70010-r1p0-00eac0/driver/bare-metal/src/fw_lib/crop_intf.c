//----------------------------------------------------------------------------
//   The confidential and proprietary information contained in this file may
//   only be used by a person authorised under and to the extent permitted
//   by a subsisting licensing agreement from ARM Limited or its affiliates.
//
//          (C) COPYRIGHT [2018] ARM Limited or its affiliates.
//              ALL RIGHTS RESERVED
//
//   This entire notice must be reproduced on all copies of this file
//   and copies of this file may only be made by a person if such person is
//   permitted to do so under the terms of a subsisting license agreement
//   from ARM Limited or its affiliates.
//----------------------------------------------------------------------------

#include "acamera_fw.h"
#include "crop_fsm.h"

#ifdef LOG_MODULE
#undef LOG_MODULE
#define LOG_MODULE LOG_MODULE_CROP
#endif

/* Use static memory here to make it cross-platform */
static crop_fsm_t crop_fsm_ctxs[FIRMWARE_CONTEXT_NUMBER];

fsm_common_t *crop_get_fsm_common( uint8_t ctx_id )
{
    crop_fsm_t *p_fsm_ctx = NULL;

    if ( ctx_id >= FIRMWARE_CONTEXT_NUMBER ) {
        LOG( LOG_CRIT, "Invalid ctx_id: %d, greater than max: %d.", ctx_id, FIRMWARE_CONTEXT_NUMBER - 1 );
        return NULL;
    }

    p_fsm_ctx = &crop_fsm_ctxs[ctx_id];

    p_fsm_ctx->cmn.ctx_id = ctx_id;
    p_fsm_ctx->cmn.p_fsm = (void *)p_fsm_ctx;

    p_fsm_ctx->cmn.ops.init = crop_fsm_init;
    p_fsm_ctx->cmn.ops.deinit = NULL;
    p_fsm_ctx->cmn.ops.run = NULL;
    p_fsm_ctx->cmn.ops.get_param = crop_fsm_get_param;
    p_fsm_ctx->cmn.ops.set_param = crop_fsm_set_param;
    p_fsm_ctx->cmn.ops.proc_event = (FUN_PTR_PROC_EVENT)crop_fsm_process_event;
    p_fsm_ctx->cmn.ops.proc_interrupt = (FUN_PTR_PROC_INT)crop_fsm_process_interrupt;

    return &( p_fsm_ctx->cmn );
}
