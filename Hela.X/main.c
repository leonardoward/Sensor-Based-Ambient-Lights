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
///////////////////////////////////////////
//
///////////////////////////////////////////
//
////**Function to send one byte of date to UART**//
//void UART_send_char(char bt)  
//{
//    while(!TXIF);  // hold the program till TX buffer is free
//    TXREG = bt; //Load the transmitter buffer with the received value
//}
////_____________End of function________________//
//
////**Function to convert string to byte**//
//void UART_send_string(char* st_pt)
//{
//    while(*st_pt) //if there is a char
//        UART_send_char(*st_pt++); //process it as a byte data
//}
//
////**Function to print an integer number into serial monitor**//
//void printInt(int number, char * description)
//{
//    char str[10];
//    sprintf(str, "%d", number);
//    UART_send_string(description);
//    UART_send_string(": ");
//    UART_send_string(str);
//    UART_send_string("\r\n");
//}
//
////**Function to print an integer number into serial monitor**//
//void printStr(char* parameter, char * description)
//{
//    UART_send_string(description);
//    UART_send_string(": ");
//    UART_send_string(parameter);
//    UART_send_string("\r\n");
//}
//
//
///********************** I2C functions **************************/
// 
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
//
///********************** end I2C functions **********************/
//
///********************** RTC chip functions *********************/
//// variables declaration
//
//
//// convert BCD to decimal function
//uint8_t bcd_to_decimal(uint32_t number) {
//  return((number >> 4) * 10 + (number & 0x0F));
//}
//
//// convert decimal to BCD function
//uint8_t decimal_to_bcd(uint32_t number) {
//  return(((number / 10) << 4) + (number % 10));
//}
//
//uint8_t  second, minute, hour, m_day, month, year;
//
//// display time and date function
//void RTC_time_date_conversion()
//{
//  static char Time[] = "TIME: 00:00:00";
//  static char Date[] = "DATE: 00/00/2000";
// 
//  // convert data from BCD format to decimal format
//  second = bcd_to_decimal(second);
//  minute = bcd_to_decimal(minute);
//  hour   = bcd_to_decimal(hour);
//  m_day  = bcd_to_decimal(m_day);
//  month  = bcd_to_decimal(month);
//  year   = bcd_to_decimal(year);
//  // end conversion
// 
//  // update time
//  Time[6]  = hour   / 10 + '0';
//  Time[7]  = hour   % 10 + '0';
//  Time[9]  = minute / 10 + '0';
//  Time[10] = minute % 10 + '0';
//  Time[12] = second / 10 + '0';
//  Time[13] = second % 10 + '0';
//  // update date
//  Date[6]  = m_day  / 10 + '0';
//  Date[7]  = m_day  % 10 + '0';
//  Date[9]  = month  / 10 + '0';
//  Date[10] = month  % 10 + '0';
//  Date[14] = year   / 10 + '0';
//  Date[15] = year   % 10 + '0';
//  
//  printStr(Time,"This is the time: ");
//  printStr(Date,"This is the date: ");
//}
//
//// Edit time and date function
//uint8_t rtc_edit(uint8_t x, uint8_t y, uint8_t parameter)
//{
////  while(debounce());  // call debounce function (wait for B1 to be released)
//// 
////  while(1) {
//// 
////    while(!button2)    // if button B2 is pressed
////    {
////      parameter++;
////      if(i == 0 && parameter > 23)   // if hours > 23 ==> hours = 0
////        parameter = 0;
////      if(i == 1 && parameter > 59)   // if minutes > 59 ==> minutes = 0
////        parameter = 0;
////      if(i == 2 && parameter > 31)   // if date > 31 ==> date = 1
////        parameter = 1;
////      if(i == 3 && parameter > 12)   // if month > 12 ==> month = 1
////        parameter = 1;
////      if(i == 4 && parameter > 99)   // if year > 99 ==> year = 0
////        parameter = 0;
//// 
////      LCD_Goto(x, y);
////      LCD_PutC(parameter / 10 + '0');
////      LCD_PutC(parameter % 10 + '0');
////      __delay_ms(200);
//// 
////    }
//// 
////    LCD_Goto(x, y);
////    LCD_Print("  ");  // print 2 spaces
////    blink();
//// 
////    LCD_Goto(x, y);
////    LCD_PutC(parameter / 10 + '0');
////    LCD_PutC(parameter % 10 + '0');
////    blink();
//// 
////    if(!button1)     // if button B1 is pressed
////    if(debounce())   // call debounce function (make sure if B1 is pressed)
////    {
////      i++;   // increment 'i' for the next parameter
////      return parameter;     // return parameter value and exit
////    }
//// 
////  }
// 
//}
//
///********************** END RTC chip functions *********************/
//
//
//
//
//
////___________End of function______________//
///*
//                         Main application
// */
//void main(void)
//{
//    // initialize the device
//    SYSTEM_Initialize();
//
//    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
//    // Use the following macros to:
//
//    // Enable the Global Interrupts
//    //INTERRUPT_GlobalInterruptEnable();
//
//    // Enable the Peripheral Interrupts
//    //INTERRUPT_PeripheralInterruptEnable();
//
//    // Disable the Global Interrupts
//    //INTERRUPT_GlobalInterruptDisable();
//
//    // Disable the Peripheral Interrupts
//    //INTERRUPT_PeripheralInterruptDisable();
//    
//    ADC_Initialize();
//    
//    uint16_t convertedValue;
//    
//    I2C_Init(100000);
//    
//    // convert decimal to BCD
//    minute = decimal_to_bcd(12);
//    hour   = decimal_to_bcd(2);
//    m_day  = decimal_to_bcd(27);
//    month  = decimal_to_bcd(5);
//    year   = decimal_to_bcd(21);
//    // end conversion
//    
////    minute = bcd_to_decimal(minute);
////    hour   = bcd_to_decimal(hour);
////    m_day  = bcd_to_decimal(m_day);
////    month  = bcd_to_decimal(month);
////    year   = bcd_to_decimal(year);
////    
////    printInt(minute, "\r\n minuto: ");
////    printInt(hour, "\r\n hour: ");
////    printInt(m_day, "\r\n m_day: ");
////    printInt(month, "\r\n month: ");
////    printInt(year, "\r\n year: ");
//
//    while (1)
//    {
//        /*
//               ADC
//         * 
//         *  Voltage values range are: 0V - 2.06V
//         *  It is an 10 bits ADC, goes from 0 to 1024 bits
//         *  As the main voltage source is 5V, the bit relationship would be
//         *  0     -> 0 bits
//         *  2.06V -> 421 bits
//         *  
//        */
//        // Read ADC value from sensor
//        convertedValue = ADC_GetConversion(0x2);
//        
//        
//        // Testing RTC
//        printStr("inicio RTC", "Descripcion: ");
//        // Write data to DS3231 RTC
//        I2C_Start();         // start I2C
//        printStr("start RTC", "Descripcion: ");
//        I2C_Write(0xD0);     // RTC chip address DS1307
//        printStr("DS1307 write address", "Descripcion: ");
//        I2C_Write(0);        // send register address
//        I2C_Write(0);        // reset seconds and start oscillator
//        I2C_Write(minute);   // write minute value to RTC chip
//        I2C_Write(hour);     // write hour value to RTC chip
//        I2C_Write(1);        // write day value (not used)
//        I2C_Write(m_day);    // write date value to RTC chip
//        I2C_Write(month);    // write month value to RTC chip
//        I2C_Write(year);     // write year value to RTC chip
//        I2C_Stop();          // stop I2C
//
////        RTC_time_date_conversion();
//        __delay_ms(1000);   
//        printStr("Leyendo RTC", "Descripcion: ");
//        // read current time and date from the RTC chip
//        I2C_Start();           // start I2C
//        I2C_Write(0xD0);       // RTC chip address
//        I2C_Write(0);          // send register address
//        I2C_Repeated_Start();  // restart I2C
//        I2C_Write(0xD1);       // initialize data read
//        second = I2C_Read(1);  // read seconds from register 0
//        minute = I2C_Read(1);  // read minutes from register 1
//        hour   = I2C_Read(1);  // read hour from register 2
//        I2C_Read(1);           // read day from register 3 (not used)
//        m_day  = I2C_Read(1);  // read date from register 4
//        month  = I2C_Read(1);  // read month from register 5
//        year   = I2C_Read(0);  // read year from register 6
//        I2C_Stop();            // stop I2C
//        
//        printStr("Recibi datos RTC", "Descripcion: ");
//        RTC_time_date_conversion();
//        __delay_ms(1000);   
//        
//        minute = bcd_to_decimal(minute);
//        hour   = bcd_to_decimal(hour);
//        m_day  = bcd_to_decimal(m_day);
//        month  = bcd_to_decimal(month);
//        year   = bcd_to_decimal(year);
//        
//        printInt(minute, "\r\n minuto: ");
//        printInt(hour, "\r\n hour: ");
//        printInt(m_day, "\r\n m_day: ");
//        printInt(month, "\r\n month: ");
//        printInt(year, "\r\n year: ");
//        
//  
//        
//        
//        
//    }
//}
///**
// End of File
//*/

 
// set configuration words
#pragma config CONFIG1 = 0x2CD4
#pragma config CONFIG2 = 0x0700
 
// button definitions
#define button1      RB0   // button B1 is connected to RB0 pin
#define button2      RB1   // button B2 is connected to RB1 pin
 
//LCD module connections
#define LCD_RS       RD0
#define LCD_EN       RD1
#define LCD_D4       RD2
#define LCD_D5       RD3
#define LCD_D6       RD4
#define LCD_D7       RD5
#define LCD_RS_DIR   TRISD0
#define LCD_EN_DIR   TRISD1
#define LCD_D4_DIR   TRISD2
#define LCD_D5_DIR   TRISD3
#define LCD_D6_DIR   TRISD4
#define LCD_D7_DIR   TRISD5
//End LCD module connections
 
 
#include <xc.h>
#define _XTAL_FREQ 8000000
#include <stdint.h>        // include stdint header
#include "LCD_Lib.c"       // include LCD driver source file
 
// variables declaration
uint8_t  i, second, minute, hour, m_day, month, year;
 
/********************** I2C functions **************************/
 
void I2C_Init(uint32_t i2c_clk_freq)
{
  SSPCON  = 0x28;  // configure MSSP module to work in I2C mode
  SSPADD  = (_XTAL_FREQ/(4 * i2c_clk_freq)) - 1;  // set I2C clock frequency
  SSPSTAT = 0;
}
 
void I2C_Start()
{
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
  SEN = 1;  // initiate start condition
}
 
void I2C_Repeated_Start()
{
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
  RSEN = 1;  // initiate repeated start condition
}
 
void I2C_Stop()
{
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
  PEN = 1;  // initiate stop condition
}
 
void I2C_Write(uint8_t i2c_data)
{
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
  SSPBUF = i2c_data;  // update buffer
}
 
uint8_t I2C_Read(uint8_t ack)
{
  uint8_t _data;
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
  RCEN = 1;
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
  _data = SSPBUF;  // read data from buffer
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));  // wait for MSSP module to be free (not busy)
  // send acknowledge pulse ? (depends on ack, if 1 send, otherwise don't send)
  ACKDT = !ack;
  ACKEN = 1;
  return _data;  // return data read
}
 
/********************** end I2C functions **********************/
 
// a small function for button1 (B1) debounce
__bit debounce ()
{
  uint8_t count = 0;
  for(uint8_t i = 0; i < 5; i++) {
    if (button1 == 0)
      count++;
    __delay_ms(10);
  }
  if(count > 2)  return 1;
  else           return 0;
}
 
/********************** RTC chip functions *********************/
// convert BCD to decimal function
uint8_t bcd_to_decimal(uint8_t number) {
  return((number >> 4) * 10 + (number & 0x0F));
}
 
// convert decimal to BCD function
uint8_t decimal_to_bcd(uint8_t number) {
  return(((number / 10) << 4) + (number % 10));
}
 
// display time and date function
void RTC_display()
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
 
  LCD_Goto(1, 1);    // go to column 1, row 1
  LCD_Print(Time);   // print time
  LCD_Goto(1, 2);    // go to column 1, row 2
  LCD_Print(Date);   // print date
}
 
// make editing parameter blinks function
void blink()
{
  uint8_t j = 0;
  while(j < 100 && button1 && button2) {
    j++;
    __delay_ms(5);
  }
}
 
// Edit time and date function
uint8_t edit(uint8_t x, uint8_t y, uint8_t parameter)
{
  while(debounce());  // call debounce function (wait for B1 to be released)
 
  while(1) {
 
    while(!button2)    // if button B2 is pressed
    {
      parameter++;
      if(i == 0 && parameter > 23)   // if hours > 23 ==> hours = 0
        parameter = 0;
      if(i == 1 && parameter > 59)   // if minutes > 59 ==> minutes = 0
        parameter = 0;
      if(i == 2 && parameter > 31)   // if date > 31 ==> date = 1
        parameter = 1;
      if(i == 3 && parameter > 12)   // if month > 12 ==> month = 1
        parameter = 1;
      if(i == 4 && parameter > 99)   // if year > 99 ==> year = 0
        parameter = 0;
 
      LCD_Goto(x, y);
      LCD_PutC(parameter / 10 + '0');
      LCD_PutC(parameter % 10 + '0');
      __delay_ms(200);
 
    }
 
    LCD_Goto(x, y);
    LCD_Print("  ");  // print 2 spaces
    blink();
 
    LCD_Goto(x, y);
    LCD_PutC(parameter / 10 + '0');
    LCD_PutC(parameter % 10 + '0');
    blink();
 
    if(!button1)     // if button B1 is pressed
    if(debounce())   // call debounce function (make sure if B1 is pressed)
    {
      i++;   // increment 'i' for the next parameter
      return parameter;     // return parameter value and exit
    }
 
  }
 
}
/********************** end RTC chip functions *****************/
 
/*************************** main function *********************/
void main(void)
{
  OSCCON = 0X70;        // set internal oscillator to 8MHz
  ANSELH = 0;           // configure all PORTB pins as digital
  // enable RB0 and RB1 internal pull ups
  nRBPU  = 0;      // clear RBPU bit (OPTION_REG.7)
  WPUB   = 0x03;   // WPUB register = 0b00000011
 
  __delay_ms(1000);
 
  I2C_Init(100000);   // initialize I2C bus with clock frequency of 100kHz
 
  LCD_Begin();        // initialize LCD module
 
  while(1) {
 
    if(!button1)     // if button B1 is pressed
    if(debounce())   // call debounce function (make sure if B1 is pressed)
    {
      i = 0;
      hour   = edit(7,  1, hour);
      minute = edit(10, 1, minute);
      m_day  = edit(7,  2, m_day);
      month  = edit(10, 2, month);
      year   = edit(15, 2, year);
 
      while(debounce());  // call debounce function (wait for button B1 to be released)
 
      // convert decimal to BCD
      minute = decimal_to_bcd(minute);
      hour   = decimal_to_bcd(hour);
      m_day  = decimal_to_bcd(m_day);
      month  = decimal_to_bcd(month);
      year   = decimal_to_bcd(year);
      // end conversion
 
      // Write data to DS3231 RTC
      I2C_Start();         // start I2C
      I2C_Write(0xD0);     // RTC chip address
      I2C_Write(0);        // send register address
      I2C_Write(0);        // reset seconds and start oscillator
      I2C_Write(minute);   // write minute value to RTC chip
      I2C_Write(hour);     // write hour value to RTC chip
      I2C_Write(1);        // write day value (not used)
      I2C_Write(m_day);    // write date value to RTC chip
      I2C_Write(month);    // write month value to RTC chip
      I2C_Write(year);     // write year value to RTC chip
      I2C_Stop();          // stop I2C
 
      __delay_ms(200);
 
    }
 
    // read current time and date from the RTC chip
    I2C_Start();           // start I2C
    I2C_Write(0xD0);       // RTC chip address
    I2C_Write(0);          // send register address
    I2C_Repeated_Start();  // restart I2C
    I2C_Write(0xD1);       // initialize data read
    second = I2C_Read(1);  // read seconds from register 0
    minute = I2C_Read(1);  // read minutes from register 1
    hour   = I2C_Read(1);  // read hour from register 2
    I2C_Read(1);           // read day from register 3 (not used)
    m_day  = I2C_Read(1);  // read date from register 4
    month  = I2C_Read(1);  // read month from register 5
    year   = I2C_Read(0);  // read year from register 6
    I2C_Stop();            // stop I2C
 
    RTC_display();    // print time & date
 
    __delay_ms(50);   // wait 50 ms
 
  }
 
}
 