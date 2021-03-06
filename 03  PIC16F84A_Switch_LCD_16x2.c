// Oreoluwa Oluwafemi LCD with PIC16f84a 
// Note: the Libraries used for the lcd were pre attached using the mikroC PRO software 
// Hence , why no libraries were called here. To use this code , select the lcd, lcd_Constants libraries 
// under the Library Manger for "mikro C PRO for PIC"
// If you do not have mickroC PRO for PIC installed on your PC , you can download the software 
// via this link https://www.mikroe.com/mikroc-pic


sbit LCD_RS at  RB0_bit;   //lcd reset
sbit LCD_EN at  RB2_bit;  // lcd enanble
sbit LCD_D4 at  RB4_bit;    //Data
sbit LCD_D5 at  RB5_bit;    //Data
sbit LCD_D6 at  RB6_bit;   //Data
sbit LCD_D7 at  RB7_bit;   //Data


sbit LCD_RS_Direction at TRISB0_bit;
sbit LCD_EN_Direction at TRISB2_bit;
sbit LCD_D4_Direction at TRISB4_bit;
sbit LCD_D5_Direction at TRISB5_bit;
sbit LCD_D6_Direction at TRISB6_bit;
sbit LCD_D7_Direction at TRISB7_bit;

int i;


void main() {

TRISB=0;
PORTB=0;
TRISA=0x04;
PORTA=0x00;


Lcd_Init();
for(i=0;i<16;i++)
{
Lcd_Cmd(_LCD_SHIFT_RIGHT);
Lcd_Out(1,1,"Oreoluwa");
Delay_ms(50); //causes a delay
}
for(i=0;i<16;i++)
{
Lcd_Cmd(_LCD_SHIFT_LEFT);
Lcd_Out(1,1,"17CE023397");
Delay_ms(50); //causes a delay
}


while(1){ // the code is loop bacause input may enter at anytimes , therefore running it once may not read the input after the first switch state
if(PORTA==0x04)
{
Lcd_Cmd(_LCD_CLEAR); // clears the characters on the LCD prior to this state
Lcd_Out(1,1,"ON");
Delay_ms(500);
}
else if(PORTA==0x00)
{
Lcd_Cmd(_LCD_CLEAR);
Lcd_Out(1,1,"OFF");
Delay_ms(500);
}
}
}
