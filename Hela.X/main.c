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

#define max_adc_bit_value 421
#define min_adc_bit_value 0

unsigned char operationMode = 0;        // Variable to select the operation mode
unsigned char optionSelect = 0;         // Select an option inside an operation mode
unsigned char lastOM = 0;               // Last operation mode selected
unsigned char lastOS = 0;               // Last option selected

unsigned char setOnLights = 0;          // Force lights to set on

unsigned char currentHour = 0;          // Current time
unsigned char currentMinute = 0;
unsigned char currentSecond = 0;
unsigned char minHourRange = 0;         // Hours range for the lights to be set on
unsigned char minMinuteRange = 0;
unsigned char maxHourRange = 0;
unsigned char maxMinuteRange = 0;

unsigned char aux1 = 0;                 // Aux variables
unsigned char aux2 = 0;
unsigned char aux3 = 0;
unsigned char aux4 = 0;

unsigned char select = 0;               // Select button
unsigned char lastSelect = 0;           // Last select button state
unsigned char accept = 0;               // Accept button
unsigned char lastAccept = 0;           // Last accept button state
unsigned char cancel = 0;               // Cancel button
unsigned char lastCancel = 0;           // Last cancel button state

char actualTime[10] = "";                           // Actual time, given by RTC
char configuringTime[10] = "";                      // Time to configure RTC
char configuringRange[14] = "";                     // Time range for the leds to set on
char enviromentChoice = 0;                          // Determines if leds set on if low enviroment light
char lightValueText[5] = "";

uint16_t convertedValue;                            // ADC current value
uint8_t adc_percentage = 0;                         // ADC percentage value (0 to 100% of the sensor, not ADC)
uint16_t threshold = 0;                             // Configured calibration threshold in ADC value (0 to 1024)

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

//*Function to print string (UART)*//
void printString(char* d, char* description)
{    
    UART_send_string(description);
    UART_send_string(": ");
    UART_send_string(d);
    UART_send_string("\r\n");
}



//___________End of function______________//
/*
                         Main application
 */

//**Function to print in LCD (states machine)**//
void LCD_Main()
{    
    // Clear the screen if the option is different
    if (lastOM != operationMode || lastOS != optionSelect)
        DisplayClr();
    
    // Depending on the mode, it shows it
    switch (operationMode)
    {
        case 0:     // Steady state and selection menu
            
            switch (optionSelect)
            {
                case 0:     // Shows the actual time and time left for the leds to be on, if configured
                    
                    sprintf(actualTime, "");
                    
                    // Print current hour
                    if (currentHour < 10)
                        sprintf(actualTime, "0");
                    sprintf(actualTime, "%s%d:", actualTime, currentHour);
                    
                    // Print current minute
                    if (currentMinute < 10)
                        sprintf(actualTime, "%s0", actualTime);
                    sprintf(actualTime, "%s%d:", actualTime, currentMinute);
                    
                    // Print current second
                    if (currentSecond < 10)
                        sprintf(actualTime, "%s0", actualTime);
                    sprintf(actualTime, "%s%d", actualTime, currentSecond);                    
                    
                    LCDGoto(0, 0);
                    LCDPutStr(actualTime);
                    
                    LCDGoto(14, 1);
                    if (setOnLights)
                        LCDPutStr("ON");   
                    else
                        LCDPutStr("  ");
                   
                    break;
                
                case 1:     // Configure the RTC time menu option
                    
                    LCDGoto(1, 0);
                    LCDPutStr("CONFIGURE TIME");
                    break;
                 
                case 2:     // Configure the time range for the leds to be on menu option
                    
                    LCDGoto(2, 0);
                    LCDPutStr("AUTO ON/OFF");
                    break;
                
                case 3:     // Calibrate the light sensor menu option
                    
                    LCDGoto(2, 0);
                    LCDPutStr("NIGHT LIGHT");
                    break;
            }
            
            break;
         
        case 1:     // Configure RTC time option
            
            LCDGoto(1, 0);
            LCDPutStr("CONFIGURE TIME");
            
            sprintf(configuringTime, "");
            // Print hour
            if (aux1 < 10)
                sprintf(configuringTime, "0");            
            sprintf(configuringTime, "%s%d:", configuringTime, aux1);
            
            // Print minute
            if (aux2 < 10)
                sprintf(configuringTime, "%s0", configuringTime);            
            sprintf(configuringTime, "%s%d:", configuringTime, aux2);
            
            // Print second
            if (aux3 < 10)
                sprintf(configuringTime, "%s0", configuringTime);            
            sprintf(configuringTime, "%s%d", configuringTime, aux3);
            
            switch (optionSelect)
            {
                default:     // Select hour             
                    
                    LCDGoto(4, 1);
                    LCDPutStr(configuringTime);
                    break;                
            }
            break;
            
        case 2:     // Configure the time range for the leds to be on option  
            
            LCDGoto(2, 0);
            LCDPutStr("AUTO ON/OFF");
            
            sprintf(configuringRange, "");
            // Print min hour of range
            if (aux1 < 10)
                sprintf(configuringRange, "0");            
            sprintf(configuringRange, "%s%d:", configuringRange, aux1);
            
            // Print min minute of range
            if (aux2 < 10)
                sprintf(configuringRange, "%s0", configuringRange);            
            sprintf(configuringRange, "%s%d - ", configuringRange, aux2);
            
            // Print max hour of range
            if (aux3 < 10)
                sprintf(configuringRange, "%s0", configuringRange);            
            sprintf(configuringRange, "%s%d:", configuringRange, aux3);
            
            // Print max minute of range
            if (aux4 < 10)
                sprintf(configuringRange, "%s0", configuringRange);            
            sprintf(configuringRange, "%s%d", configuringRange, aux4);
            
            switch (optionSelect)
            {
                default:     // Select start hour             
                    
                    LCDGoto(1, 1);
                    LCDPutStr(configuringRange);
                    break;                
            }
            break;
        
        case 3:         // Calibrate the light sensor option
            
            LCDGoto(0, 0);
            LCDPutStr("NIGHT LIGHT: ");
            
            // Show selected option
            if (enviromentChoice)
                LCDPutStr("YES");
            else
                LCDPutStr("NO ");
            
            // Calculate the ADC percentage (sensor range)
            adc_percentage = (convertedValue - min_adc_bit_value) * (100) / (max_adc_bit_value - min_adc_bit_value);
            
            // Adjust the text and print
            if (adc_percentage < 10)
                sprintf(lightValueText, "  ");
            else if (adc_percentage < 100)
                sprintf(lightValueText, " ");
            else
                sprintf(lightValueText, "");
            
            sprintf(lightValueText, "%s%d%%", lightValueText, adc_percentage);
            LCDGoto(6, 1);
            LCDPutStr(lightValueText);
            break;
    }
}

void readButtons()
{
    // Get the buttons value
    select = SELECT_GetValue();
    accept = ACCEPT_GetValue();
    cancel = CANCEL_GetValue();
    
    // If cancel button is pressed (trailing edge))
    if (cancel != lastCancel)
    {
        if (!cancel)
        {
            
            operationMode = 0;
            optionSelect = 0;
            
            return;
        }
    }
    
    // If select button is pressed (trailing edge)
    if (select != lastSelect)
    {
        if (!select)
        {
            
            switch (operationMode)
            {
                case 0:             // Steady state and selection menu

                    switch (optionSelect)
                    {
                        case 3:     // Change menu option
                            
                            optionSelect = 0;
                            break;
                            
                        default:     // Change menu option
                            
                            optionSelect++;
                            break;                       
                        
                    }
                    break;
                    
                case 1:             // Configure time option

                    switch (optionSelect)
                    {
                        case 2:     // Back to main screen
                            
                            operationMode = 0;
                            optionSelect = 0;
                            currentHour = aux1;
                            currentMinute = aux2;
                            currentSecond = aux3;
                            break;
                            
                        default:     // Change to minute, second
                            
                            optionSelect++;
                            break;  

                    }
                    break;
                
                case 2:                     // Auto on/off option
                    
                    switch (optionSelect)
                    {
                        case 3:
                            
                            operationMode = 0;
                            optionSelect = 0;
                            minHourRange = aux1;
                            minMinuteRange = aux2;
                            maxHourRange = aux3;
                            maxMinuteRange = aux4;
                            break;
                            
                        default:             // Change to min minute of range
                            
                            optionSelect++;
                            break;
                        
                    }
                    break;
                    
                case 3:
                    
                    operationMode = 0;
                    optionSelect = 0;
                    threshold = convertedValue;
                    break;


            }
            
            return;
        }
    }
    
    // If accept button is pressed (trailing edge)
    if (accept != lastAccept)
    {
        if (!accept)
        {
            
            switch (operationMode)
            {
                case 0:             // Steady state, to adjust the time the leds are going to be on
                    
                    aux1 = 0;
                    aux2 = 0;
                    aux3 = 0;
                    aux4 = 0;
                    
                    switch (optionSelect)
                    {
                        case 0:
                            
                            if (setOnLights)
                                setOnLights = 0;
                            else
                                setOnLights = 1;
                            break;
                         
                        case 1:

                            operationMode = 1;      // Selects the configure time option
                            optionSelect = 0;
                            break;
                        
                        case 2:
                            
                            operationMode = 2;      // Selects the auto on/off option
                            optionSelect = 0;
                            break;
                        
                        case 3:
                            
                            operationMode = 3;      // Selects the night light option
                            optionSelect = 0;
                            break;

                    }
                    break;
                
                case 1:
                    
                    switch (optionSelect)
                    {
                        case 0:         // Add 1 to hours
                            
                            aux1++;
                            if (aux1 > 23)
                                aux1 = 0;
                            break;
                         
                        case 1:         // Add 1 to minutes

                            aux2++;
                            if (aux2 > 59)
                                aux2 = 0;
                            break;
                        
                        case 2:         // Add 1 to seconds
                            
                            aux3++;
                            if (aux3 > 59)
                                aux3 = 0;
                            break;
                    }   
                    break;
                    
                case 2:
                    
                    switch (optionSelect)
                    {
                        case 0:
                            
                            aux1++;
                            if (aux1 > 23)
                                aux1 = 0;
                            break;
                        
                        case 1:
                            
                            aux2++;
                            if (aux2 > 59)
                                aux2 = 0;
                            break;
                        
                        case 2:
                            
                            aux3++;
                            if (aux3 > 23)
                                aux3 = 0;
                            break;
                          
                        case 3:
                            
                            aux4++;
                            if (aux4 > 59)
                                aux4 = 0;
                            break;
                    }
                    break;
                
                case 3:
                    
                    switch (optionSelect)
                    {
                        case 0:
                            
                            if (enviromentChoice)
                                enviromentChoice = 0;                            
                            else
                                enviromentChoice = 1;
                            break;
                    }
                    break;
            }
        }
    }
    
}

/* Function used to compare the times of the RTC and verify if they belong to a given range*/
//Returns 1 if the Current Hour and minutes belong in the rang [Hour1:Min1, Hour2:Min2], 
//If the conditions are not met, it returns 0
char timeInRange(unsigned char CurrentH, unsigned char CurrentM, unsigned char Range1H, unsigned char Range1M, unsigned char Range2H, unsigned char Range2M)
{   
    char result = 0;
    char HighInterval_H;
    char HighInterval_M;
    char LowInterval_H;
    char LowInterval_M;
    
    if (Range1H > Range2H)
    {
        HighInterval_H = Range1H;
        HighInterval_M = Range1M;
        LowInterval_H = Range2H;
        LowInterval_M = Range2M;
    } 
    else 
    {
        if (Range1H < Range2H) 
        {
            HighInterval_H = Range2H;
            HighInterval_M = Range2M;
            LowInterval_H = Range1H;
            LowInterval_M = Range1M; 
        
        } 
        else 
        {
            if (Range1M >= Range2M) {
                HighInterval_H = Range1H;
                HighInterval_M = Range1M;
                LowInterval_H = Range2H;
                LowInterval_M = Range2M; 
            } 
            else
            {
                HighInterval_H = Range2H;
                HighInterval_M = Range2M;
                LowInterval_H = Range1H;
                LowInterval_M = Range1M; 
          
            }
        }
    }
    
    bool comp1 = (CurrentH >= LowInterval_H) && (CurrentM >= LowInterval_M);
    bool comp2 = (CurrentH <= HighInterval_H) && (CurrentM <= HighInterval_M);    
    if (comp1 && comp2)
        result = 1;
    
    return result;
}

//*Function to determine if the lights need to be set on*//
void verifyLights()
{
    // Because are forced to
    if (setOnLights)
        RELAY_SetHigh();
    
    // Because current time is in the range configured as for the lights to set on
    else if ((minHourRange || minMinuteRange || maxHourRange || maxMinuteRange)
        && timeInRange(currentHour, currentMinute, minHourRange, minMinuteRange, maxHourRange, maxMinuteRange))
        RELAY_SetHigh();
    
    // Because of the low enviroment light level
    else if(enviromentChoice && convertedValue <= threshold)
        RELAY_SetHigh();
    
    else
        RELAY_SetLow();
}

void debbuging()
{
    printString(actualTime, "Current time is");
    
    sprintf(lightValueText, "%d", convertedValue);
    printString(lightValueText, "Current sensor value is");
}


void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    // Initialize the ADC
    ADC_Initialize();
    
    // initialize LCD module
    LCD_Initialize();        
    
    // Set RC6 (cancel button) as input
    CANCEL_SetDigitalInput();
    
    // Initial screen
    LCDPutStr("      HELA");
    LCDGoto(2, 1);           // go to column 4, row 1
    LCDPutStr("INITIALIZING");
    __delay_ms(3000);
    DisplayClr();
    
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
        // Read ADC channel 2 value from sensor
        convertedValue = ADC_GetConversion(0x2);
        
        // Read all the buttons state
        readButtons();
        
        // Show the correct screen
        LCD_Main();
        
        // Verify if the lights need to be set on
        verifyLights();
        
        // Print debug values (UART)
        debbuging();
        
        // Update control variables
        lastOM = operationMode;
        lastOS = optionSelect;
        
        lastSelect = select;
        lastAccept = accept;
        lastCancel = cancel;             
    }
}
/**
 End of File
*/