//Todo: 1. LED Glowing
//      2. Click Buttom to Erase Current Notification
//      3. Possible Power Saving 
//
//
/*----------------------------------------< Includes >----------------------------------------*/
#include "Arduino.h"
#include <avr/interrupt.h>
/*----------------------------------------< Defines  >----------------------------------------*/
//define Mouse State        MS_
#define MS_SlowLED_R        (0x0D)
#define MS_SlowLED_G        (0x0C)
#define MS_SlowLED_B        (0x0B)
#define MS_Idle             (0x04)
#define MS_Sleep            (0x05)
#define MS_FastLED_R        (0x06)
#define MS_FastLED_G        (0x06)
#define MS_FastLED_B        (0x06)

//TEST
#define INT1_Disable()      (GIMSK &= ~(1<<INT1))
#define INT1_Enable()       (GIMSK |= (1<<INT1))

//Sleep Allow               SA_
#define SA_DENY             (0x03)
#define SA_ALLOW            (0x04)

/*----------------------------------------< typedefs >----------------------------------------*/

/*---------------------------------------< prototypes >---------------------------------------*/
static void GlowingLED(char color);

/*---------------------------------------<    APIs    >---------------------------------------*/
void GlowingLED();

/*---------------------------------------< Interrupts >---------------------------------------*/

/*-------------------------------------< Local const Data >-----------------------------------*/

/*--------------------------------------< Local Var Data >------------------------------------*/
static char   state = MS_Idle;
static int    i;
/*---------------------------------------< Global Data >--------------------------------------*/

/*---------------------------------------< Begin Code >---------------------------------------*/


ISR(INT0_vect)
{
    state = MS_Idle;
    //analogWrite(state,0);
    //PORTB = (0<<DDB0)|(0<<DDB1)|(0<<DDB2) ;
}

ISR(USART_RX_vect)
{
    char receivedByte;  //ASIC
    receivedByte = UDR; // Retrieves byte from serial port (bluetooth module)
 
    switch (receivedByte) 
    {
        case 'R': 
            state = MS_SlowLED_R;
            //PORTB |= (1<<DDB4);   // turn the LED on (HIGH is the voltage level) at PB4, pin16
            break;
        case 'G': 
            state = MS_SlowLED_G;
            //PORTB |= (1<<DDB3);   // turn the LED on (HIGH is the voltage level) at PB4, pin16
            break;  
        case 'B': 
            state = MS_SlowLED_B;
            //PORTB |= (1<<DDB2);   // turn the LED on (HIGH is the voltage level) at PB4, pin16
            break;  
        case 'C': 
            state = MS_Idle;
            //PORTB = (0<<DDB0)|(0<<DDB1)|(0<<DDB2);
            break;            
        default:    
            break;  
    }
 
}

void GlowingLED()
{
    if(MS_Idle == state){
        //analogWrite(state,0);
        PORTB = (0<<DDB0)|(0<<DDB1)|(0<<DDB2) ;
    }
    else{
        char color = state;                //if state change to idle, can still finish up remain glowing
        for (i = 0; i < 240; i = i++)
        {
            analogWrite(color,i);
            delay(6);
        }
        for (i = 240; i >= 0; i--)
        {
            analogWrite(color,i);
            delay(6);
        }
        delay(500);

    }
}


