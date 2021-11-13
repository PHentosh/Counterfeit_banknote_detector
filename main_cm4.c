/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>

int main(void)
{
    __enable_irq(); /* Enable global interrupts. */
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    CapSense_Start();
    CapSense_ScanAllWidgets();
    int inp = 0;
    int i=0;
    for(;;)
    {
        if(!CapSense_IsBusy()){
            CapSense_ProcessAllWidgets();
            Cy_GPIO_Write(RED_PORT, RED_NUM, 0);
            if(CapSense_IsWidgetActive(CapSense_BUTTON0_WDGT_ID)){
                Cy_GPIO_Write(BLUE_PORT, BLUE_NUM, 0);
                i = 0;
            }
            if(CapSense_IsWidgetActive(CapSense_BUTTON1_WDGT_ID)){
                Cy_GPIO_Write(BLUE_PORT, BLUE_NUM, 1);
                i = 1;
            }
            
            if (i == 1){
                inp = Cy_GPIO_Read(INP_PORT, INP_NUM);
            }
            if(inp!=0){
                Cy_GPIO_Write(RED_PORT, RED_NUM, 1);
            }
            inp = 0;
            CapSense_UpdateAllBaselines();
            CapSense_ScanAllWidgets();
    }
    }
}

/* [] END OF FILE */
