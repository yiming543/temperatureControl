/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1936
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_AN0 aliases
#define channel_AN0_TRIS                 TRISAbits.TRISA0
#define channel_AN0_LAT                  LATAbits.LATA0
#define channel_AN0_PORT                 PORTAbits.RA0
#define channel_AN0_ANS                  ANSELAbits.ANSA0
#define channel_AN0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_AN0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_AN0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_AN0_GetValue()           PORTAbits.RA0
#define channel_AN0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_AN0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_AN0_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define channel_AN0_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set channel_AN2 aliases
#define channel_AN2_TRIS                 TRISAbits.TRISA2
#define channel_AN2_LAT                  LATAbits.LATA2
#define channel_AN2_PORT                 PORTAbits.RA2
#define channel_AN2_ANS                  ANSELAbits.ANSA2
#define channel_AN2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define channel_AN2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define channel_AN2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define channel_AN2_GetValue()           PORTAbits.RA2
#define channel_AN2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define channel_AN2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define channel_AN2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define channel_AN2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISAbits.TRISA6
#define LED2_LAT                  LATAbits.LATA6
#define LED2_PORT                 PORTAbits.RA6
#define LED2_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define LED2_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define LED2_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define LED2_GetValue()           PORTAbits.RA6
#define LED2_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISAbits.TRISA7
#define LED1_LAT                  LATAbits.LATA7
#define LED1_PORT                 PORTAbits.RA7
#define LED1_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define LED1_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define LED1_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define LED1_GetValue()           PORTAbits.RA7
#define LED1_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)

// get/set SW1 aliases
#define SW1_TRIS                 TRISBbits.TRISB1
#define SW1_LAT                  LATBbits.LATB1
#define SW1_PORT                 PORTBbits.RB1
#define SW1_WPU                  WPUBbits.WPUB1
#define SW1_ANS                  ANSELBbits.ANSB1
#define SW1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define SW1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define SW1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define SW1_GetValue()           PORTBbits.RB1
#define SW1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define SW1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define SW1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define SW1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define SW1_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define SW1_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set SW2 aliases
#define SW2_TRIS                 TRISBbits.TRISB2
#define SW2_LAT                  LATBbits.LATB2
#define SW2_PORT                 PORTBbits.RB2
#define SW2_WPU                  WPUBbits.WPUB2
#define SW2_ANS                  ANSELBbits.ANSB2
#define SW2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define SW2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define SW2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define SW2_GetValue()           PORTBbits.RB2
#define SW2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define SW2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define SW2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define SW2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define SW2_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define SW2_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set SW3 aliases
#define SW3_TRIS                 TRISBbits.TRISB3
#define SW3_LAT                  LATBbits.LATB3
#define SW3_PORT                 PORTBbits.RB3
#define SW3_WPU                  WPUBbits.WPUB3
#define SW3_ANS                  ANSELBbits.ANSB3
#define SW3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define SW3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define SW3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define SW3_GetValue()           PORTBbits.RB3
#define SW3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define SW3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define SW3_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define SW3_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define SW3_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define SW3_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set LED3 aliases
#define LED3_TRIS                 TRISCbits.TRISC0
#define LED3_LAT                  LATCbits.LATC0
#define LED3_PORT                 PORTCbits.RC0
#define LED3_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LED3_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define LED3_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define LED3_GetValue()           PORTCbits.RC0
#define LED3_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set LED4 aliases
#define LED4_TRIS                 TRISCbits.TRISC1
#define LED4_LAT                  LATCbits.LATC1
#define LED4_PORT                 PORTCbits.RC1
#define LED4_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define LED4_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define LED4_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define LED4_GetValue()           PORTCbits.RC1
#define LED4_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define LED4_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set LED5 aliases
#define LED5_TRIS                 TRISCbits.TRISC2
#define LED5_LAT                  LATCbits.LATC2
#define LED5_PORT                 PORTCbits.RC2
#define LED5_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LED5_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LED5_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LED5_GetValue()           PORTCbits.RC2
#define LED5_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LED5_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

// get/set LED6 aliases
#define LED6_TRIS                 TRISCbits.TRISC3
#define LED6_LAT                  LATCbits.LATC3
#define LED6_PORT                 PORTCbits.RC3
#define LED6_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LED6_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LED6_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LED6_GetValue()           PORTCbits.RC3
#define LED6_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LED6_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set Relay2 aliases
#define Relay2_TRIS                 TRISCbits.TRISC4
#define Relay2_LAT                  LATCbits.LATC4
#define Relay2_PORT                 PORTCbits.RC4
#define Relay2_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define Relay2_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define Relay2_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define Relay2_GetValue()           PORTCbits.RC4
#define Relay2_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define Relay2_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set Relay1 aliases
#define Relay1_TRIS                 TRISCbits.TRISC5
#define Relay1_LAT                  LATCbits.LATC5
#define Relay1_PORT                 PORTCbits.RC5
#define Relay1_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define Relay1_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define Relay1_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define Relay1_GetValue()           PORTCbits.RC5
#define Relay1_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define Relay1_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/