/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2023/12/29
 * Description        : Main program body.
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

/*
 *@Note
 *task1 and task2 alternate printing
 */

#include "debug.h"
#include "FreeRTOS.h"
#include "task.h"

/* Global define */
#define TASK1_TASK_PRIO     5
#define TASK1_STK_SIZE      256
#define TASK2_TASK_PRIO     5
#define TASK2_STK_SIZE      256

/* Global Variable */
static StaticTask_t rtos_task0_TCB;
static StackType_t rtos_task0_stack[configMINIMAL_STACK_SIZE];
static StaticTask_t rtos_task1_TCB;
static StackType_t rtos_task1_stack[configMINIMAL_STACK_SIZE];

/*********************************************************************
 * @fn      GPIO_Toggle_INIT
 *
 * @brief   Initializes GPIOA.0/1
 *
 * @return  none
 */
void GPIO_Toggle_INIT(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure={0};

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_4|GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  GPIO_SetBits(GPIOB, GPIO_Pin_1|GPIO_Pin_4|GPIO_Pin_5);
}


/*********************************************************************
 * @fn      task1_task
 *
 * @brief   task1 program.
 *
 * @param  *pvParameters - Parameters point of task1
 *
 * @return  none
 */
void task1_task(void *pvParameters)
{
    while(1)
    {
        GPIO_SetBits(GPIOB, GPIO_Pin_5);
        vTaskDelay(250);
        GPIO_ResetBits(GPIOB, GPIO_Pin_5);
        vTaskDelay(250);
    }
}

/*********************************************************************
 * @fn      task2_task
 *
 * @brief   task2 program.
 *
 * @param  *pvParameters - Parameters point of task2
 *
 * @return  none
 */
void task2_task(void *pvParameters)
{
    vTaskDelay(100);
    while(1)
    {
        GPIO_SetBits(GPIOB, GPIO_Pin_4);
        vTaskDelay(100);
        GPIO_ResetBits(GPIOB, GPIO_Pin_4);
        vTaskDelay(400);
    }
}

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */



int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();
    USART_Printf_Init(115200);
    printf("SystemClk:%d\r\n",SystemCoreClock);
    printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
    printf("FreeRTOS Kernel Version:%s\r\n",tskKERNEL_VERSION_NUMBER);

    GPIO_Toggle_INIT();
    /* create two task */

    xTaskCreateStatic(task2_task,
                            "task2",
                            configMINIMAL_STACK_SIZE,
                            NULL,
                            tskIDLE_PRIORITY+1,
                            &rtos_task0_stack[0],
                            &rtos_task0_TCB);


    xTaskCreateStatic(task1_task,
                               "task1",
                               configMINIMAL_STACK_SIZE,
                               NULL,
                               tskIDLE_PRIORITY+1,
                               &rtos_task1_stack[0],
                               &rtos_task1_TCB);

    vTaskStartScheduler();

    while(1)
    {
        printf("shouldn't run at here!!\n");
    }
}

