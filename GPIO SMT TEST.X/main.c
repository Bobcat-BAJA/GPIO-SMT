#include "mcc_generated_files/mcc.h"

#define TOOTH_COUNT 50
#define _XTAL_FREQ 48000000 // System clock frequency for delay calculations

// Function prototypes
void LCD_SendNibble(uint8_t nibble);
void LCD_SendCommand(uint8_t cmd);
void LCD_SendData(uint8_t data);
void LCD_Init(void);
void DisplayRPM(uint16_t rpm);
uint16_t CalculateRPM(void);
void LCD_Print(const char* str);
void LCD_PrintNumber(uint16_t num);
void IntToStr(uint16_t num, char* buffer);

void main(void) {
    SYSTEM_Initialize();
    LCD_Init(); // Initialize the LCD

    uint16_t rpm = 0;

    while (1) {
        // Calculate RPM
        rpm = CalculateRPM();
        
        // Display RPM on LCD
        DisplayRPM(rpm);
        
        __delay_ms(500); // Update display every 500ms
        garytt is g
        a
        y
    }
}

// Function to calculate RPM using SMT and TIMER2
uint16_t CalculateRPM(void) {
    uint32_t periodCount = SMT1_GetCapturedPeriod();
    
    if (periodCount == 0) {
        return 0; // Avoid division by zero if period is invalid
    }
    
    // Calculate frequency (assuming periodCount is in clock cycles)
    uint32_t frequency = _XTAL_FREQ / periodCount;
    
    // Convert frequency to RPM
    uint16_t rpm = (frequency * 60) / TOOTH_COUNT;
    
    return rpm;
}

// Function to display RPM on the LCD
void DisplayRPM(uint16_t rpm) {
    LCD_SendCommand(0x80); // Move to the first line, first position
    LCD_Print("RPM:");

    // Display the calculated RPM value on the second line
    LCD_SendCommand(0xC0); // Move to the second line, first position
    LCD_PrintNumber(rpm);
}

// Helper function to print a number to the LCD
void LCD_PrintNumber(uint16_t num) {
    char buffer[6]; // Buffer to hold the RPM as a string
    IntToStr(num, buffer); // Convert the number to a string
    LCD_Print(buffer); // Print the string on the LCD
}

// Custom integer to string conversion function
void IntToStr(uint16_t num, char* buffer) {
    int i = 0;
    do {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);
    
    buffer[i] = '\0';
    
    // Reverse the string in place
    for (int j = 0; j < i / 2; ++j) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }
}

// Function to print strings on the LCD
void LCD_Print(const char* str) {
    while (*str) {
        LCD_SendData(*str++);
    }
}

// Basic LCD functions for 4-bit mode

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
