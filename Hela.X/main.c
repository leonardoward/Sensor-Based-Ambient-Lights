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

#include "i2c.h"
#include"stdutils.h"


/***************************************************************************************************
                                 Struct/Enums used
***************************************************************************************************/
typedef struct
{
  uint8_t sec;
  uint8_t min;
  uint8_t hour;
  uint8_t weekDay;
  uint8_t date;
  uint8_t month;
  uint8_t year;  
}rtc_t;

/***************************************************************************************************
                             Commonly used Ds1307 macros/Constants
***************************************************************************************************
  Below values are fixed and should not be changed. Refer Ds1307 DataSheet for more info*/

#define C_Ds1307ReadMode_U8   0xD1u  // DS1307 ID
#define C_Ds1307WriteMode_U8  0xD0u  // DS1307 ID

#define C_Ds1307SecondRegAddress_U8   0x00u   // Address to access Ds1307 SEC register
#define C_Ds1307DateRegAddress_U8     0x04u   // Address to access Ds1307 DATE register
#define C_Ds1307ControlRegAddress_U8  0x07u   // Address to access Ds1307 CONTROL register
/**************************************************************************************************/
///////////////////////////////////////////
//
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

/***************************************************************************************************
                         void RTC_Init(void)
****************************************************************************************************
 * I/P Arguments: none.
 * Return value    : none

 * description :This function is used to Initialize the Ds1307 RTC.
***************************************************************************************************/
void RTC_Init(void)
{
    I2C_Init();                             // Initialize the I2c module.
    printStr("I2C_Init", "Descripcion: ");
    I2C_Start();
    
    printStr("I2C_Start", "Descripcion: ");
    I2C_Write(C_Ds1307WriteMode_U8);        // Connect to DS1307 by sending its ID on I2c Bus
    printStr("I2C_Write", "Descripcion: ");
    I2C_Write(C_Ds1307ControlRegAddress_U8);// Select the Ds1307 ControlRegister to configure Ds1307
    printStr("I2C_Write", "Descripcion: ");

    I2C_Write(0x00);                        // Write 0x00 to Control register to disable SQW-Out

    I2C_Stop();                             // Stop I2C communication after initializing DS1307
    printStr("I2C_Stop", "Descripcion: ");
    
}
/***************************************************************************************************
                    void RTC_SetDateTime(rtc_t *rtc)
****************************************************************************************************
 * I/P Arguments: rtc_t *: Pointer to structure of type rtc_t. Structure contains hour,min,sec,day,date,month and year 
 * Return value    : none

 * description  :This function is used to update the Date and time of Ds1307 RTC.
                 The new Date and time will be updated into the non volatile memory of Ds1307.
        Note: The date and time should be of BCD format, 
             like 0x12,0x39,0x26 for 12hr,39min and 26sec.    
                  0x15,0x08,0x47 for 15th day,8th month and 47th year.                 
***************************************************************************************************/
void RTC_SetDateTime(rtc_t *rtc)
{
    I2C_Start();                          // Start I2C communication

    I2C_Write(C_Ds1307WriteMode_U8);      // connect to DS1307 by sending its ID on I2c Bus
    I2C_Write(C_Ds1307SecondRegAddress_U8); // Request sec RAM address at 00H

    I2C_Write(rtc->sec);                    // Write sec from RAM address 00H
    I2C_Write(rtc->min);                    // Write min from RAM address 01H
    I2C_Write(rtc->hour);                    // Write hour from RAM address 02H
    I2C_Write(rtc->weekDay);                // Write weekDay on RAM address 03H
    I2C_Write(rtc->date);                    // Write date on RAM address 04H
    I2C_Write(rtc->month);                    // Write month on RAM address 05H
    I2C_Write(rtc->year);                    // Write year on RAM address 06h

    I2C_Stop();                              // Stop I2C communication after Setting the Date
}
/***************************************************************************************************
                     void RTC_GetDateTime(rtc_t *rtc)
****************************************************************************************************
 * I/P Arguments: rtc_t *: Pointer to structure of type rtc_t. Structure contains hour,min,sec,day,date,month and year 
 * Return value    : none

 * description  :This function is used to get the Date(d,m,y) from Ds1307 RTC.

    Note: The date and time read from Ds1307 will be of BCD format, 
          like 0x12,0x39,0x26 for 12hr,39min and 26sec.    
               0x15,0x08,0x47 for 15th day,8th month and 47th year.              
***************************************************************************************************/
void RTC_GetDateTime(rtc_t *rtc)
{
    I2C_Start();                            // Start I2C communication
    printStr("I2C_Start", "Descripcion: ");
    I2C_Write(C_Ds1307WriteMode_U8);        // connect to DS1307 by sending its ID on I2c Bus
    I2C_Write(C_Ds1307SecondRegAddress_U8); // Request Sec RAM address at 00H
    printStr("I2C_Write", "Descripcion: ");
    I2C_Stop();                                // Stop I2C communication after selecting Sec Register
    printStr("I2C_Stop", "Descripcion: ");
    I2C_Start();                            // Start I2C communication
    I2C_Write(C_Ds1307ReadMode_U8);            // connect to DS1307(Read mode) by sending its ID
    printStr("I2C_Write", "Descripcion: ");
    rtc->sec = I2C_Read(1);                // read second and return Positive ACK
    printStr("I2C_Read", "Descripcion: ");
    rtc->min = I2C_Read(1);                 // read minute and return Positive ACK
    rtc->hour= I2C_Read(1);               // read hour and return Negative/No ACK
    rtc->weekDay = I2C_Read(1);           // read weekDay and return Positive ACK
    rtc->date= I2C_Read(1);              // read Date and return Positive ACK
    rtc->month=I2C_Read(1);            // read Month and return Positive ACK
    rtc->year =I2C_Read(0);             // read Year and return Negative/No ACK
    printStr("I2C_Read", "Descripcion: ");
    I2C_Stop();                              // Stop I2C communication after reading the Date
}


/********************** I2C functions **************************/
 
//void I2C_Init(uint32_t i2c_clk_freq)
//{
//  SSPCON  = 0x28;  // configure MSSP module to work in I2C mode
//  SSPADD  = (_XTAL_FREQ/(4 * i2c_clk_freq)) - 1;  // set I2C clock frequency
//  SSPSTAT = 0;
//}
// 
//void I2C_Start()
//{
//  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
//  SEN = 1;  // initiate start condition
//}
// 
//void I2C_Repeated_Start()
//{
//  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
//  RSEN = 1;  // initiate repeated start condition
//}
// 
//void I2C_Stop()
//{
//  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  
//  PEN = 1;  // initiate stop condition
//}
// 
//void I2C_Write(uint8_t i2c_data)
//{
//  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
//  SSPBUF = i2c_data;  // update buffer
//}
// 
//uint8_t I2C_Read(uint8_t ack)
//{
//  uint8_t _data;
//  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
//  RCEN = 1;
//  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
//  _data = SSPBUF;  // read data from buffer
//  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
//  // send acknowledge pulse ? (depends on ack, if 1 send, otherwise don't send)
//  ACKDT = !ack;
//  ACKEN = 1;
//  return _data;  // return data read
//}

/********************** end I2C functions **********************/

/********************** RTC chip functions *********************/
// variables declaration


// convert BCD to decimal function
uint8_t bcd_to_decimal(uint32_t number) {
  return((number >> 4) * 10 + (number & 0x0F));
}

// convert decimal to BCD function
uint8_t decimal_to_bcd(uint32_t number) {
  return(((number / 10) << 4) + (number % 10));
}

uint8_t  second, minute, hour, m_day, month, year;

// display time and date function
void RTC_time_date_conversion()
{
  static char Time[] = "TIME: 00:00:00";
  static char Date[] = "DATE: 00/00/2000";
 
  // convert data from BCD format to decimal format
  second = bcd_to_decimal(second);
  minute = bcd_to_decimal(minute);
  hour   = bcd_to_decimal(hour);
  m_day  = bcd_to_decimal(m_day);
  month  = bcd_to_decimal(month);
  year   = bcd_to_decimal(year);
  // end conversion
 
  // update time
  Time[6]  = hour   / 10 + '0';
  Time[7]  = hour   % 10 + '0';
  Time[9]  = minute / 10 + '0';
  Time[10] = minute % 10 + '0';
  Time[12] = second / 10 + '0';
  Time[13] = second % 10 + '0';
  // update date
  Date[6]  = m_day  / 10 + '0';
  Date[7]  = m_day  % 10 + '0';
  Date[9]  = month  / 10 + '0';
  Date[10] = month  % 10 + '0';
  Date[14] = year   / 10 + '0';
  Date[15] = year   % 10 + '0';
  
  printStr(Time,"This is the time: ");
  printStr(Date,"This is the date: ");
}

// Edit time and date function
uint8_t rtc_edit(uint8_t x, uint8_t y, uint8_t parameter)
{
//  while(debounce());  // call debounce function (wait for B1 to be released)
// 
//  while(1) {
// 
//    while(!button2)    // if button B2 is pressed
//    {
//      parameter++;
//      if(i == 0 && parameter > 23)   // if hours > 23 ==> hours = 0
//        parameter = 0;
//      if(i == 1 && parameter > 59)   // if minutes > 59 ==> minutes = 0
//        parameter = 0;
//      if(i == 2 && parameter > 31)   // if date > 31 ==> date = 1
//        parameter = 1;
//      if(i == 3 && parameter > 12)   // if month > 12 ==> month = 1
//        parameter = 1;
//      if(i == 4 && parameter > 99)   // if year > 99 ==> year = 0
//        parameter = 0;
// 
//      LCD_Goto(x, y);
//      LCD_PutC(parameter / 10 + '0');
//      LCD_PutC(parameter % 10 + '0');
//      __delay_ms(200);
// 
//    }
// 
//    LCD_Goto(x, y);
//    LCD_Print("  ");  // print 2 spaces
//    blink();
// 
//    LCD_Goto(x, y);
//    LCD_PutC(parameter / 10 + '0');
//    LCD_PutC(parameter % 10 + '0');
//    blink();
// 
//    if(!button1)     // if button B1 is pressed
//    if(debounce())   // call debounce function (make sure if B1 is pressed)
//    {
//      i++;   // increment 'i' for the next parameter
//      return parameter;     // return parameter value and exit
//    }
// 
//  }
 
}

/********************** END RTC chip functions *********************/




//___________End of function______________//
/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

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
    
    ADC_Initialize();
    
    uint16_t convertedValue;
    printStr("SYSTEM INIT", "Descripcion: ");
    
//    I2C_Init(100000);
    
    rtc_t rtc;
    
    rtc.hour = 0x10; //  10:40:20 am
    rtc.min =  0x40;
    rtc.sec =  0x00;

    rtc.date = 0x01; //1st Jan 2016
    rtc.month = 0x01;
    rtc.year = 0x16;
    rtc.weekDay = 5; // Friday: 5th day of week considering monday as first day.
    
    I2C_Initialize();
    I2C_Open(0x68);// Start I2C communication
    printStr("Set Date Time", "Descripcion: ");
    
    RTC_Init();
    /*##### Set the time and Date only once. Once the Time and Date is set, comment these lines
     and reflash the code. Else the time will be set every time the controller is reset*/
    RTC_SetDateTime(&rtc);  //  10:40:20 am, 1st Jan 2016
   
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
        printStr("ADC", "Descripcion: ");
        convertedValue = ADC_GetConversion(0x2);
        
        
//        // Testing RTC
//        printStr("inicio RTC", "Descripcion: ");
//        // Write data to DS3231 RTC
//        I2C_Start();         // start I2C
//        printStr("start RTC", "Descripcion: ");
//        I2C_Write(0xD0);     // RTC chip address DS1307
//        printStr("DS1307 write address", "Descripcion: ");
//        I2C_Write(0);        // send register address

        printStr("GET Date Time", "Descripcion: ");
        RTC_GetDateTime(&rtc);
        
        printStr((uint16_t)rtc.hour, "hour: ");
        printStr((uint16_t)rtc.min, "Min: ");
        printStr((uint16_t)rtc.sec, "Sec: ");
        printStr((uint16_t)rtc.date, "Date: ");
        printStr((uint16_t)rtc.month, "Month: ");
        printStr((uint16_t)rtc.year, "Year: ");
        

    }
}
/**
 End of File
*/



