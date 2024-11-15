#include "lcd.h"

void LCD_SendNibble(uint8_t nibble) {
    // Send the upper nibble to the LCD data pins
    D4_LAT = (nibble >> 0) & 0x01;
    D5_LAT = (nibble >> 1) & 0x01;
    D6_LAT = (nibble >> 2) & 0x01;
    D7_LAT = (nibble >> 3) & 0x01;

    __delay_us(10);  // Ensure data lines are stable

    // Pulse the Enable pin
    EN_SetHigh();
    __delay_us(1);
    EN_SetLow();
    __delay_us(50);
}

void LCD_SendCommand(uint8_t cmd) {
    RS_SetLow(); // Command mode
    LCD_SendNibble(cmd >> 4); // Send high nibble
    LCD_SendNibble(cmd & 0x0F); // Send low nibble
    __delay_ms(2); // Allow command to process
}

void LCD_SendData(uint8_t data) {
    RS_SetHigh(); // Data mode
    LCD_SendNibble(data >> 4); // Send high nibble
    LCD_SendNibble(data & 0x0F); // Send low nibble
    __delay_us(50);
}

void LCD_Init(void) {
    __delay_ms(100); // Initial power-up delay

    // Send 0x03 three times to initialize in 4-bit mode
    LCD_SendNibble(0x03);
    __delay_ms(5);
    LCD_SendNibble(0x03);
    __delay_us(150);
    LCD_SendNibble(0x03);
    __delay_us(150);
    LCD_SendNibble(0x02); // Set to 4-bit mode
    __delay_ms(5);

    // Set function and display settings
    LCD_SendCommand(0x28); // 4-bit, 2-line, 5x8 dots
    LCD_SendCommand(0x0C); // Display ON, cursor OFF
    LCD_SendCommand(0x06); // Entry mode: increment cursor
    LCD_SendCommand(0x01); // Clear display
    __delay_ms(2); 
}

void LCD_SendNum(int integer,int digits){
    int digit = 0;
    for(int i = digits;i >= 0; i--){
        digit = integer/(10^i);
        integer -= digit*(10^i);
        digit += '0';
        LCD_SendData(digit);
    }
}

