/*----------------------------------------< Includes >----------------------------------------*/
#include "Arduino.h"
#include <avr/interrupt.h>


/*----------------------------------------< Defines  >----------------------------------------*/

/*----------------------------------------< typedefs >----------------------------------------*/

/*---------------------------------------< prototypes >---------------------------------------*/
static void InitializePorts(void);
static void InitializeINT1Interrupt(void);
static void InitializeUART(void);

/*---------------------------------------<    APIs    >---------------------------------------*/
void InitializeATTiny2313(void);

/*---------------------------------------< Interrupts >---------------------------------------*/

/*-------------------------------------< Local const Data >-----------------------------------*/

/*--------------------------------------< Local Var Data >------------------------------------*/

/*---------------------------------------< Global Data >--------------------------------------*/

/*---------------------------------------< Begin Code >---------------------------------------*/



static void InitializePorts(void)
{
    DDRA = 0;
    PORTA = 0;
    DDRB = (1<<DDB0)|(1<<DDB1)|(1<<DDB2);       //Enable PB7 as output, the LED on Pin13 of Arduino Uno
    PORTB = 0;              //All initialized to 0
    DDRD = (1<<DDD2);       //PD2(INT0), Set it to pull dowm resister for INT0 Rising Edge Interrupt
    PORTD = 0; 
}

static void InitializeINT1Interrupt(void)
{
    GIMSK |= (1<<INT0);                 //External Interrupt Request 1 Enable INT0(PD2, pin6)
    //EIFR = (1<<INTF1);                //External Interrupt Flag 1, No need to do anything, it's a flag that process will handle)
    MCUCR |= (1<<ISC01) | (1<<ISC00);   //The rising edge of INT1 generates an interrupt request.
    SREG |= (0x80);                     //Enable Global Interrupt 0x80 => I
}

static void InitializeUART(void)
{
    UCSRB |= (1 << RXEN) | (1 << TXEN);     //RX TX  Enable
    UCSRC |= (1 << UCSZ0) | (1 << UCSZ1);   //Character size = 8 bits
    UCSRA |= (1 << U2X);                    //Doubling transmission speed
    UBRRL = 12;                             //Baud Rate Register, 9600, U2X=1, 1MHz
    //UBRRH = (12 >> 8);                    //Baud Rate Register, shift 8 to right
    UCSRB |= (1 << RXCIE);                  //RX Complete Interrupt Enable
}

void InitializeATTiny2313(void)
{
    cli();
    InitializePorts();
    InitializeINT1Interrupt();
    InitializeUART();

}
