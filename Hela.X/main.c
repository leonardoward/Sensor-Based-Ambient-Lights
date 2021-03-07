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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1768
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

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include "LCD_Lib.h"          // include LCD driver source file


//**Function to send one byte of date to UART**//
void UART_send_char(char bt)  
{
    while(!TXIF);  // hold the program till TX buffer is free
    TXREG = bt; //Load the transmitter buffer with the received value
}
//_____________End of function________________//

//**Function to convert string to byte**//
void UART_send_string(char* st_pt)
{
    while(*st_pt) //if there is a char
        UART_send_char(*st_pt++); //process it as a byte data
}

//**Function to print an integer number into serial monitor**//
void printInt(int number, char * description)
{
    char str[10];
    sprintf(str, "%d", number);
    UART_send_string(description);
    UART_send_string(": ");
    UART_send_string(str);
    UART_send_string("\r\n");
}



//___________End of function______________//
/*
                         Main application
 */


void Delay_Seconds(unsigned char z)
{
    unsigned char x,y;
    for (y=0; y<z; y++)
    {
        for(x=0; x<100; x++)__delay_ms(10);
    }
}


void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    //ADC_Initialize();
    
    //uint16_t convertedValue;
    
    LCD_Initialize();       // initialize LCD module
 
    
    LCDPutStr(" Hello World!");
    LCDGoto(8, 1);           // go to column 4, row 1
    LCDPutChar("1");
    Delay_Seconds(1);
    LCDGoto(8, 1);           // go to column 4, row 1
    LCDPutChar("2");
    Delay_Seconds(1);
    LCDGoto(8, 1);           // go to column 4, row 1
    LCDPutChar("3");
    Delay_Seconds(1);
    DisplayClr();
    
    LCDPutStr("LCD Display");
    LCDGoto(0,1);           // go to column 3, row 2
    LCDPutStr("LCD Example");
    Delay_Seconds(1);
    while (1)
    {
        /*
               ADC
         * 
         *  Voltage values range are: 0V - 2.06V
         *  It is an 10 bits ADC, goes from 0 to 1024 bits
         *  As the main voltage source is 5V, the bit relationship would be
         *  0     -> 0 bits
         *  2.06V -> 421 bits
         *  
        */
        // Read ADC value from sensor
        //convertedValue = ADC_GetConversion(0x2);
        
        
        
  
        
        
        
    }
}
/**
 End of File
*/