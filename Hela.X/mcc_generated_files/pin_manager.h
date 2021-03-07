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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1768
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
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

// get/set FOTORESISTENCIA aliases
#define FOTORESISTENCIA_TRIS                 TRISAbits.TRISA2
#define FOTORESISTENCIA_LAT                  LATAbits.LATA2
#define FOTORESISTENCIA_PORT                 PORTAbits.RA2
#define FOTORESISTENCIA_WPU                  WPUAbits.WPUA2
#define FOTORESISTENCIA_OD                   ODCONAbits.ODA2
#define FOTORESISTENCIA_ANS                  ANSELAbits.ANSA2
#define FOTORESISTENCIA_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define FOTORESISTENCIA_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define FOTORESISTENCIA_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define FOTORESISTENCIA_GetValue()           PORTAbits.RA2
#define FOTORESISTENCIA_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define FOTORESISTENCIA_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define FOTORESISTENCIA_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define FOTORESISTENCIA_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define FOTORESISTENCIA_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define FOTORESISTENCIA_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define FOTORESISTENCIA_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define FOTORESISTENCIA_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set D4_LCD aliases
#define D4_LCD_TRIS                 TRISCbits.TRISC0
#define D4_LCD_LAT                  LATCbits.LATC0
#define D4_LCD_PORT                 PORTCbits.RC0
#define D4_LCD_WPU                  WPUCbits.WPUC0
#define D4_LCD_OD                   ODCONCbits.ODC0
#define D4_LCD_ANS                  ANSELCbits.ANSC0
#define D4_LCD_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define D4_LCD_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define D4_LCD_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define D4_LCD_GetValue()           PORTCbits.RC0
#define D4_LCD_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define D4_LCD_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define D4_LCD_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define D4_LCD_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define D4_LCD_SetPushPull()        do { ODCONCbits.ODC0 = 0; } while(0)
#define D4_LCD_SetOpenDrain()       do { ODCONCbits.ODC0 = 1; } while(0)
#define D4_LCD_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define D4_LCD_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set D5_LCD aliases
#define D5_LCD_TRIS                 TRISCbits.TRISC1
#define D5_LCD_LAT                  LATCbits.LATC1
#define D5_LCD_PORT                 PORTCbits.RC1
#define D5_LCD_WPU                  WPUCbits.WPUC1
#define D5_LCD_OD                   ODCONCbits.ODC1
#define D5_LCD_ANS                  ANSELCbits.ANSC1
#define D5_LCD_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define D5_LCD_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define D5_LCD_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define D5_LCD_GetValue()           PORTCbits.RC1
#define D5_LCD_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define D5_LCD_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define D5_LCD_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define D5_LCD_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define D5_LCD_SetPushPull()        do { ODCONCbits.ODC1 = 0; } while(0)
#define D5_LCD_SetOpenDrain()       do { ODCONCbits.ODC1 = 1; } while(0)
#define D5_LCD_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define D5_LCD_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set D6_LCD aliases
#define D6_LCD_TRIS                 TRISCbits.TRISC2
#define D6_LCD_LAT                  LATCbits.LATC2
#define D6_LCD_PORT                 PORTCbits.RC2
#define D6_LCD_WPU                  WPUCbits.WPUC2
#define D6_LCD_OD                   ODCONCbits.ODC2
#define D6_LCD_ANS                  ANSELCbits.ANSC2
#define D6_LCD_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define D6_LCD_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define D6_LCD_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define D6_LCD_GetValue()           PORTCbits.RC2
#define D6_LCD_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define D6_LCD_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define D6_LCD_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define D6_LCD_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define D6_LCD_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define D6_LCD_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define D6_LCD_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define D6_LCD_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set D7_LCD aliases
#define D7_LCD_TRIS                 TRISCbits.TRISC3
#define D7_LCD_LAT                  LATCbits.LATC3
#define D7_LCD_PORT                 PORTCbits.RC3
#define D7_LCD_WPU                  WPUCbits.WPUC3
#define D7_LCD_OD                   ODCONCbits.ODC3
#define D7_LCD_ANS                  ANSELCbits.ANSC3
#define D7_LCD_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define D7_LCD_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define D7_LCD_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define D7_LCD_GetValue()           PORTCbits.RC3
#define D7_LCD_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define D7_LCD_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define D7_LCD_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define D7_LCD_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define D7_LCD_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define D7_LCD_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define D7_LCD_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define D7_LCD_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set E_LCD aliases
#define E_LCD_TRIS                 TRISCbits.TRISC4
#define E_LCD_LAT                  LATCbits.LATC4
#define E_LCD_PORT                 PORTCbits.RC4
#define E_LCD_WPU                  WPUCbits.WPUC4
#define E_LCD_OD                   ODCONCbits.ODC4
#define E_LCD_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define E_LCD_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define E_LCD_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define E_LCD_GetValue()           PORTCbits.RC4
#define E_LCD_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define E_LCD_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define E_LCD_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define E_LCD_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define E_LCD_SetPushPull()        do { ODCONCbits.ODC4 = 0; } while(0)
#define E_LCD_SetOpenDrain()       do { ODCONCbits.ODC4 = 1; } while(0)

// get/set RS_LCD aliases
#define RS_LCD_TRIS                 TRISCbits.TRISC5
#define RS_LCD_LAT                  LATCbits.LATC5
#define RS_LCD_PORT                 PORTCbits.RC5
#define RS_LCD_WPU                  WPUCbits.WPUC5
#define RS_LCD_OD                   ODCONCbits.ODC5
#define RS_LCD_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RS_LCD_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RS_LCD_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RS_LCD_GetValue()           PORTCbits.RC5
#define RS_LCD_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RS_LCD_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RS_LCD_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define RS_LCD_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define RS_LCD_SetPushPull()        do { ODCONCbits.ODC5 = 0; } while(0)
#define RS_LCD_SetOpenDrain()       do { ODCONCbits.ODC5 = 1; } while(0)

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