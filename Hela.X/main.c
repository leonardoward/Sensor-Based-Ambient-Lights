///**
//  Generated Main Source File
//
//  Company:
//    Microchip Technology Inc.
//
//  File Name:
//    main.c
//
//  Summary:
//    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs
//
//  Description:
//    This header file provides implementations for driver APIs for all modules selected in the GUI.
//    Generation Information :
//        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
//        Device            :  PIC16F1768
//        Driver Version    :  2.00
//*/
//
///*
//    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
//    
//    Subject to your compliance with these terms, you may use Microchip software and any 
//    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
//    license terms applicable to your use of third party software (including open source software) that 
//    may accompany Microchip software.
//    
//    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
//    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
//    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
//    FOR A PARTICULAR PURPOSE.
//    
//    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
//    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
//    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
//    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
//    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
//    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
//    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
//    SOFTWARE.
//*/
//
//#include "mcc_generated_files/mcc.h"
//#include <stdio.h>

#include "LCD_Lib.h"       // include LCD driver source file
#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdlib.h>
#include "word_config.h" //Only here
#include "lcd.h"
#include "i2c.h"
#include "ds1307.h"

#define _XTAL_FREQ  16000000

///////////////////////////////////////////
//
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

//**Function to print an integer number into serial monitor**//
void printStr(char* parameter, char * description)
{
    UART_send_string(description);
    UART_send_string(": ");
    UART_send_string(parameter);
    UART_send_string("\r\n");
}

/************** P R O T O T Y P E S *******************************************/
void MCU_Init(void);
void MCU_HelloMessage(void);
void DisplayTimeToLCD( unsigned char* pTimeArray );
void DisplayDateOnLCD( unsigned char* pDateArray );


//___________End of function______________//
/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    MCU_Init();
    LCD_Init();
	InitI2C();	// Initialize i2c pins											
	// Set initial time
	Set_DS1307_RTC_Time(PM_Time, 11, 59, 55);	// Set time 11:30:00 PM
	// Set initial date
	Set_DS1307_RTC_Date(25, 07, 17, Tuesday); 	// Set 25-07-2017 @ Tuesday
    
    MCU_HelloMessage();
   
    while (1)
    {
        /*
         *      ADC
         * 
         *  Voltage values range are: 0V - 2.06V
         *  It is an 10 bits ADC, goes from 0 to 1024 bits
         *  As the main voltage source is 5V, the bit relationship would be
         *  0     -> 0 bits
         *  2.06V -> 421 bits
         *  
        */
        // Read ADC value from sensor
//        printStr("ADC", "Descripcion: ");
//        convertedValue = ADC_GetConversion(0x2);
//        Get_DS1307_RTC_Time();
        // Display RTC time on first line of LCD
		DisplayTimeToLCD(Get_DS1307_RTC_Time());
		// Display RTC date on second line of LCD
		DisplayDateOnLCD(Get_DS1307_RTC_Date());
		__delay_ms(1000);	// 1 second delay
        
    }
}

void MCU_Init(void){
    //Configura oscilador interno a 4MHz
    OSCCONbits.IRCF=0b110; 
    
    ADCON1=0xFF;    //Entradas digitales

    PORTB=0x00;
    TRISB=0x00;
}

void MCU_HelloMessage(void){
    LCD_Clear();
    LCD_Putrs("  MrChunckuee!  ",0,0);
    LCD_Putrs("RTC: DS1307 demo",0,1);
    __delay_ms(2000);	// 1 second delay
    LCD_Clear();
}

void DisplayTimeToLCD(unsigned char* pTimeArray){   // Displays time in HH:MM:SS AM/PM format  
	// Display Hour
	LCD_Putc_xy( (pTimeArray[2]/10)+0x30, 0, 0 );
    LCD_Putc_xy( (pTimeArray[2]%10)+0x30, 1, 0 );
	LCD_Putrs(":", 2, 0);
	//Display Minutes
	LCD_Putc_xy( (pTimeArray[1]/10)+0x30, 3, 0 );
	LCD_Putc_xy( (pTimeArray[1]%10)+0x30, 4, 0 );
	LCD_Putrs(":", 5, 0);
    //Display Seconds
	LCD_Putc_xy( (pTimeArray[0]/10)+0x30, 6, 0 );
	LCD_Putc_xy( (pTimeArray[0]%10)+0x30, 7, 0 );
	LCD_Putrs(" ", 8, 0 );
    // Display mode
	switch(pTimeArray[3]){
        case AM_Time:   LCD_Putrs("AM", 9, 0);  break;
        case PM_Time:   LCD_Putrs("PM", 9, 0);  break;
        default:        LCD_Putrs('H', 9, 0);   break;
	}
}




void DisplayDateOnLCD( unsigned char* pDateArray ){   // Displays Date in DD:MM:YY @ Day format
	// Display Date
	LCD_Putc_xy( (pDateArray[1]/10)+0x30, 0, 1 );
	LCD_Putc_xy( (pDateArray[1]%10)+0x30, 1, 1 );
	LCD_Putrs("/", 2, 1);
    //Display Month
	LCD_Putc_xy( (pDateArray[2]/10)+0x30, 3, 1 );
	LCD_Putc_xy( (pDateArray[2]%10)+0x30, 4, 1 );
	LCD_Putrs("/", 5, 1);
	//Display Year
	LCD_Putc_xy( (pDateArray[3]/10)+0x30, 6, 1 );
	LCD_Putc_xy( (pDateArray[3]%10)+0x30, 7, 1 );
	LCD_Putrs(" ", 8, 1);
	// Display Day
	switch(pDateArray[0]){
        case Monday:	LCD_Putrs("MON", 9, 1);	break;
        case Tuesday:	LCD_Putrs("TUE", 9, 1);	break;
        case Wednesday:	LCD_Putrs("WED", 9, 1);	break;
        case Thursday:	LCD_Putrs("THU", 9, 1);	break;
        case Friday:	LCD_Putrs("FRI", 9, 1);	break;
        case Saturday:	LCD_Putrs("SAT", 9, 1);	break;
        case Sunday:	LCD_Putrs("SUN", 9, 1);	break;
        default:        LCD_Putrs("???", 9, 1);	break;
	}
}


/**
 End of File
*/



