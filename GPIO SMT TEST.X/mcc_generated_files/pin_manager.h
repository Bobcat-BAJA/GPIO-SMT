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
        Device            :  PIC18F27Q43
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

// get/set EN aliases
#define EN_TRIS                 TRISAbits.TRISA6
#define EN_LAT                  LATAbits.LATA6
#define EN_PORT                 PORTAbits.RA6
#define EN_WPU                  WPUAbits.WPUA6
#define EN_OD                   ODCONAbits.ODCA6
#define EN_ANS                  ANSELAbits.ANSELA6
#define EN_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define EN_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define EN_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define EN_GetValue()           PORTAbits.RA6
#define EN_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define EN_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define EN_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define EN_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define EN_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define EN_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define EN_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define EN_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set RS aliases
#define RS_TRIS                 TRISAbits.TRISA7
#define RS_LAT                  LATAbits.LATA7
#define RS_PORT                 PORTAbits.RA7
#define RS_WPU                  WPUAbits.WPUA7
#define RS_OD                   ODCONAbits.ODCA7
#define RS_ANS                  ANSELAbits.ANSELA7
#define RS_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define RS_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define RS_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define RS_GetValue()           PORTAbits.RA7
#define RS_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define RS_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define RS_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define RS_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define RS_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define RS_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define RS_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define RS_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set D4 aliases
#define D4_TRIS                 TRISCbits.TRISC0
#define D4_LAT                  LATCbits.LATC0
#define D4_PORT                 PORTCbits.RC0
#define D4_WPU                  WPUCbits.WPUC0
#define D4_OD                   ODCONCbits.ODCC0
#define D4_ANS                  ANSELCbits.ANSELC0
#define D4_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define D4_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define D4_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define D4_GetValue()           PORTCbits.RC0
#define D4_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define D4_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define D4_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define D4_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define D4_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define D4_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define D4_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define D4_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set D5 aliases
#define D5_TRIS                 TRISCbits.TRISC1
#define D5_LAT                  LATCbits.LATC1
#define D5_PORT                 PORTCbits.RC1
#define D5_WPU                  WPUCbits.WPUC1
#define D5_OD                   ODCONCbits.ODCC1
#define D5_ANS                  ANSELCbits.ANSELC1
#define D5_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define D5_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define D5_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define D5_GetValue()           PORTCbits.RC1
#define D5_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define D5_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define D5_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define D5_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define D5_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define D5_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define D5_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define D5_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set D6 aliases
#define D6_TRIS                 TRISCbits.TRISC2
#define D6_LAT                  LATCbits.LATC2
#define D6_PORT                 PORTCbits.RC2
#define D6_WPU                  WPUCbits.WPUC2
#define D6_OD                   ODCONCbits.ODCC2
#define D6_ANS                  ANSELCbits.ANSELC2
#define D6_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define D6_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define D6_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define D6_GetValue()           PORTCbits.RC2
#define D6_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define D6_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define D6_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define D6_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define D6_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define D6_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define D6_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define D6_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set D7 aliases
#define D7_TRIS                 TRISCbits.TRISC3
#define D7_LAT                  LATCbits.LATC3
#define D7_PORT                 PORTCbits.RC3
#define D7_WPU                  WPUCbits.WPUC3
#define D7_OD                   ODCONCbits.ODCC3
#define D7_ANS                  ANSELCbits.ANSELC3
#define D7_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define D7_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define D7_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define D7_GetValue()           PORTCbits.RC3
#define D7_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define D7_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define D7_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define D7_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define D7_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define D7_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define D7_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define D7_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set Speed aliases
#define Speed_TRIS                 TRISCbits.TRISC4
#define Speed_LAT                  LATCbits.LATC4
#define Speed_PORT                 PORTCbits.RC4
#define Speed_WPU                  WPUCbits.WPUC4
#define Speed_OD                   ODCONCbits.ODCC4
#define Speed_ANS                  ANSELCbits.ANSELC4
#define Speed_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define Speed_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define Speed_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define Speed_GetValue()           PORTCbits.RC4
#define Speed_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define Speed_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define Speed_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define Speed_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define Speed_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define Speed_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define Speed_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define Speed_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

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