/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1936
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

//todo disp_7seg if else modify to switch case 20250605
//todo disp_7seg temp over 100 disp dot 20250605



#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
void TMR0_timerHandler(void);

unsigned long milliseconds =0;
unsigned long current_time =0;
unsigned long last_time =0;
unsigned int T250ms =0;
unsigned int T500ms =0;
unsigned int T1000ms =0;
unsigned char temp_cnt =0;
unsigned char flag_Key_release=KEY_RELEASE;  //1:release 0:press

// unsigned long get_time_ms(void)
// {
//      return milliseconds; // 返回經過的毫秒數
// }




/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    TMR0_SetInterruptHandler(TMR0_timerHandler);

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
        // Add your application code
        // if(T1000ms > 1000){
        //   T1000ms =0;
        //   temp_cnt++;
        //   // if(temp_cnt > 25300){
        //   //   temp_cnt =0;
        //   // }

        // }
        key_debounce();
        if((SW1_STATUS==KEY_STATE_SHORT_PRESS)&&(flag_Key_release==KEY_RELEASE))
        {
            temp_cnt++;
            flag_Key_release = 0 ;
        }

        
        disp_sub(temp_cnt,DISP_TEMP);
        
    }
    

    return 0;
}

void TMR0_timerHandler(void){
    // add your TMR0 interrupt custom code
    // or set custom function using TMR0_SetInterruptHandler()
    milliseconds++;   
    T500ms++;   
    T250ms++;
    T1000ms++;
    if(T250ms > 250){
        T250ms =0;
        // Relay1_Toggle();
    }
    
    if(T500ms > 500){
        T500ms =0;
        // Relay2_Toggle();
    }
}

/**
 End of File
*/