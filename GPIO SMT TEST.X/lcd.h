/* 
 * File:   lcd.h
 * Author: levilyons
 *
 * Created on November 11, 2024, 4:11 PM
 */

#ifndef LCD_H
#define	LCD_H
#include <xc.h>
#include "mcc_generated_files/device_config.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/mcc.h"

void LCD_SendNibble(uint8_t nibble);
void LCD_SendCommand(uint8_t cmd);
void LCD_SendData(uint8_t data);
void LCD_Init(void);
void LCD_Print(const char* str);
void LCD_SendNum(int integer,int digits);


#endif	/* LCD_H */

