/**
 * @file       ble_timer.c
 * @copyright  Copyright (C) 2020 Fiot Co., Ltd. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    2.0.0
 * @date       2020-06-11
 * @author     Thuan Le
 *
 * @brief      Timer for smart gadget.
 *
 * @note
 */

/* Includes ----------------------------------------------------------- */
#include "ble_timer.h"
#include "OSAL.h"

/* Function definitions ----------------------------------------------- */
void ble_timer_1s_init(uint8_t task_id)
{
  osal_start_reload_timer(task_id, TIMER_1000_MS_EVT, 2000);
}

void ble_timer_stop(uint8_t task_id, uint16_t event_id)
{
  osal_stop_timerEx(task_id, event_id);
}

uint16_t ble_timer_process_event(uint8_t task_id, uint16_t events)
{
  if (events & TIMER_1000_MS_EVT)
  {
    periodic_1s_callback();
    return (events ^ TIMER_1000_MS_EVT);
  }
  return 0;
}

/* End of file -------------------------------------------------------- */