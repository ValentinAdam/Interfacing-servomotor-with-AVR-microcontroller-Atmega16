#define F_CPU 1000000UL
#include<avr/io.h>
#include<util/delay.h>
 
void main()
{
        //Configure TIMER1
        TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11); //NON Inverted PWM
        TCCR1B|=(1<<WGM13)|(1<<WGM12)|(0<<CS11)|(1<<CS10); //PRESCALER=1 MODE 14(FAST PWM)
        
        ICR1=19999; //fPWM=50Hz (Period = 20ms Standard).
        
        DDRD|=(1<<PD4)|(1<<PD5); //PWM Pins as Out
    
        while(1)
        {
                OCR1A=0; //0 degree
                _delay_ms(1000);

                OCR1A=600; //45 degree 
                _delay_ms(1000);

                OCR1A=950; //90 degree 
                _delay_ms(1000);

                OCR1A=1425; //135 degree 
                _delay_ms(1000);

                OCR1A=1900; //180 degree 
                _delay_ms(1000);

                OCR1A=1425; //135 degree
                _delay_ms(1000);

                OCR1A=950; //90 degree
                _delay_ms(1000);

                OCR1A=650; //45 degree
                _delay_ms(1000);
        }
}