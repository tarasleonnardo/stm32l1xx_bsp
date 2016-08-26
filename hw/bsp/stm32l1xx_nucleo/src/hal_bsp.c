/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include "stm32l1xx_hal.h"
#include "hal/hal_gpio.h"
#include "hal/hal_flash_int.h"
#include "mcu/stm32l152xe.h"
#include "mcu/stm32l1xx_hal_gpio_ex.h"
#include "mcu/stm32l1_bsp.h"
#include "bsp/bsp.h"
#include <assert.h>

static const struct stm32l1_uart_cfg uart_cfg[UART_CNT] = {
    [0] = {
        .suc_uart = USART3,
        .suc_rcc_reg = &RCC->APB1ENR,
        .suc_rcc_dev = RCC_APB1ENR_USART3EN,
        .suc_pin_tx = 42,
        .suc_pin_rx = 43,
        .suc_pin_rts = -1,
        .suc_pin_cts = -1,
        .suc_pin_af = GPIO_AF7_USART3,
        .suc_irqn = USART3_IRQn
    }
};

const struct stm32l1_uart_cfg *
bsp_uart_config(int port)
{
    assert(port < UART_CNT);
    return &uart_cfg[port];
}

#if 1
const struct hal_flash *
bsp_flash_dev(uint8_t id)
{
    /*
     * Internal flash mapped to id 0.
     */
    if (id != 0) {
        return NULL;
    }
    return &stm32l1_flash_dev;
}
#endif
