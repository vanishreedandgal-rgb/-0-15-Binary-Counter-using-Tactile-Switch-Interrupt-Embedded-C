/*
 * ------------------------------------------------------------
 * Project : 0–15 Binary Counter using Tactile Switch (Interrupt)
 * MCU     : ATmega328P / ATmega16 / ATmega32
 * Clock   : 16 MHz
 * Author  : Your Name
 * ------------------------------------------------------------
 *
 * Description:
 * A tactile push button connected to PD6 generates an interrupt.
 * Each button press increments a 4-bit binary counter (0–15).
 * LEDs connected to PD2–PD5 display the binary count.
 *
 * ------------------------------------------------------------
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/* Global counter variable */
volatile uint8_t count = 0;

int main(void)
{
    /* -------------------------------
       Configure LED Pins (PD2–PD5)
       ------------------------------- */
    DDRD |= (1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5);

    /* -------------------------------
       Configure Tactile Switch (PD6)
       ------------------------------- */
    DDRD &= ~(1 << PD6);      // Input pin
    PORTD |= (1 << PD6);      // Enable internal pull-up resistor

    /* -------------------------------
       Enable Pin Change Interrupt
       ------------------------------- */
    PCICR  |= (1 << PCIE2);     // Enable PORTD interrupt
    PCMSK2 |= (1 << PCINT22);   // Enable interrupt for PD6

    sei();   // Enable Global Interrupts

    /* Main Loop */
    while (1)
    {
        // MCU waits for interrupt
    }
}

/* ------------------------------------------------------------
   Interrupt Service Routine
   Triggered when button is pressed
------------------------------------------------------------ */
ISR(PCINT2_vect)
{
    /* Check Button Press (Active LOW) */
    if (!(PIND & (1 << PD6)))
    {
        _delay_ms(50);   // Debounce delay

        if (!(PIND & (1 << PD6)))
        {
            count++;        // Increment counter
            count &= 0x0F;  // Limit 0–15 (4-bit counter)

            /* Turn OFF all LEDs first */
            PORTD |= (1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5);

            /* Display Binary Value */
            PORTD &= ~((count & 0x0F) << 2);

            /* Wait until button released */
            while (!(PIND & (1 << PD6)));

            _delay_ms(50);  // Debounce release
        }
    }
}
