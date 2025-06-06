#include "../mcc.h"

void SSD(unsigned char num, unsigned char xn);
void SSLED(unsigned char nu, unsigned char xa);
void disp_7seg(unsigned char char1, unsigned char char2, unsigned char char3);
// void LED_SW(void);
void LED_DISABLE(void);


void disp_sub(char disp_temp, unsigned char disp_char) {
  unsigned int temp = disp_temp;
  unsigned char display_digital1 = (unsigned char)(temp / 10);

  //over 100 just show 0 to 9
  if(display_digital1 >9) {
    display_digital1 %= 10;
  }
  unsigned char display_digital2 = (unsigned char)(temp % 10);
  unsigned char display_digital3 = disp_char;

  for (unsigned int i = 0; i < DISP_TIMES; i++) {
    disp_7seg(display_digital1, display_digital2, display_digital3);
  }
}

void disp_7seg(unsigned char char1, unsigned char char2, unsigned char char3) {
  SSD(char1, 1); // 百位
  SSD(char2, 2); // 十位
  SSD(10, 3);    // 小數點
  SSD(char3, 3); // 個位
  SSD(10, 1);    // 關
}

// void LED_SW(void) {
//   LED1_SetLow();
//   LED2_SetLow();
//   LED3_SetLow();
//   LED4_SetLow();
//   LED5_SetLow();
//   LED6_SetLow();
// }
void LED_DISABLE(void){
  LED1_SetDigitalInput();
  LED2_SetDigitalInput();
  LED3_SetDigitalInput();
  LED4_SetDigitalInput();
  LED5_SetDigitalInput();
  LED6_SetDigitalInput();
}

void SSLED(unsigned char nu, unsigned char xa) {
  if (nu == 1) {
    if (xa == 1) // A
    {
      // TRISA = 0b11011110;
      // TRISC = 0b11011011;
      // LED6 = OFF;
      // LED1 = ON;
      LED_DISABLE();
      LED6_SetDigitalOutput();
      LED1_SetDigitalOutput();
      LED6_SetLow();
      LED1_SetHigh();
    } else if (xa == 2) // B
    {
      // TRISA = 0b11011011;
      // TRISC = 0b11011011;
      // LED6 = OFF;
      // LED3 = ON;
      LED_DISABLE();
      LED6_SetDigitalOutput();
      LED3_SetDigitalOutput();
      LED6_SetLow();
      LED3_SetHigh();
    } else if (xa == 3) // C
    {
      // TRISA = 0b11011111;
      // TRISC = 0b11011001;
      // LED6 = OFF;
      // LED5 = ON;
      LED_DISABLE();
      LED6_SetDigitalOutput();
      LED5_SetDigitalOutput();
      LED6_SetLow();
      LED5_SetHigh();
    } else if (xa == 4) // D
    {
      // TRISA = 0b11011111;
      // TRISC = 0b11011010;
      // LED4 = OFF;
      // LED6 = ON;
      LED_DISABLE();
      LED4_SetDigitalOutput();
      LED6_SetDigitalOutput();
      LED4_SetLow();
      LED6_SetHigh();
    } else if (xa == 5) // E
    {
      // TRISA = 0b11011111;
      // TRISC = 0b11011010;
      // LED6 = OFF;
      // LED4 = ON;
      LED_DISABLE();
      LED6_SetDigitalOutput();
      LED4_SetDigitalOutput();
      LED6_SetLow();
      LED4_SetHigh();
    } else if (xa == 6) // F
    {
      // TRISA = 0b11011111;
      // TRISC = 0b11011001;
      // LED5 = OFF;
      // LED6 = ON;
      LED_DISABLE();
      LED5_SetDigitalOutput();
      LED6_SetDigitalOutput();
      LED5_SetLow();
      LED6_SetHigh();
    } else if (xa == 7) // G
    {
      // TRISA = 0b11011110;
      // TRISC = 0b11011101;
      // LED5 = OFF;
      // LED1 = ON;
      LED_DISABLE();
      LED5_SetDigitalOutput();
      LED1_SetDigitalOutput();
      LED5_SetLow();
      LED1_SetHigh();
    } else if (xa == 8) // X
    {
      // TRISA = 0b11011111;
      // TRISC = 0b11011111;
      LED1_SetDigitalOutput();
      LED2_SetDigitalOutput();
      LED3_SetDigitalOutput();
      LED4_SetDigitalOutput();
      LED5_SetDigitalOutput();
      LED6_SetDigitalOutput();
      LED1_SetLow();
      LED2_SetLow();
      LED3_SetLow();
      LED4_SetLow();
      LED5_SetLow();
      LED6_SetLow();
    }
  } else if (nu == 2) {
    if (xa == 1) // A
    {
      // TRISA = 0b11011111;
      // TRISC = 0b11011100;
      // LED4 = OFF;
      // LED5 = ON;
      LED_DISABLE();
      LED4_SetDigitalOutput();
      LED5_SetDigitalOutput();
      LED4_SetLow();
      LED5_SetHigh();
    } else if (xa == 2) // B
    {
      // TRISA = 0b11011011;
      // TRISC = 0b11011101;
      // LED5 = OFF;
      // LED3 = ON;
      LED_DISABLE();
      LED5_SetDigitalOutput();
      LED3_SetDigitalOutput();
      LED5_SetLow();
      LED3_SetHigh();
    } else if (xa == 3) // C
    {
      // TRISA = 0b11011111;
      // TRISC = 0b11011100;
      // LED5 = OFF;
      // LED4 = ON;
      LED_DISABLE();
      LED5_SetDigitalOutput();
      LED4_SetDigitalOutput();
      LED5_SetLow();
      LED4_SetHigh();
    } else if (xa == 4) // D
    {
      // TRISA = 0b11011011;
      // TRISC = 0b11011110;
      // LED4 = OFF;
      // LED3 = ON;
      LED_DISABLE();
      LED4_SetDigitalOutput();
      LED3_SetDigitalOutput();
      LED4_SetLow();
      LED3_SetHigh();
    } else if (xa == 5) // E
    {
      // TRISA = 0b11011011;
      // TRISC = 0b11011011;
      // LED3 = OFF;
      // LED6 = ON;
      LED_DISABLE();
      LED3_SetDigitalOutput();
      LED6_SetDigitalOutput();
      LED3_SetLow();
      LED6_SetHigh();
    } else if (xa == 6) // F
    {
      // TRISA = 0b11011011;
      // TRISC = 0b11011110;
      // LED3 = OFF;
      // LED4 = ON;
      LED_DISABLE();
      LED3_SetDigitalOutput();
      LED4_SetDigitalOutput();
      LED3_SetLow();
      LED4_SetHigh();
    } else if (xa == 7) // G
    {
      // TRISA = 0b11011011;
      // TRISC = 0b11011101;
      // LED3 = OFF;
      // LED5 = ON;
      LED_DISABLE();
      LED3_SetDigitalOutput();
      LED5_SetDigitalOutput();
      LED3_SetLow();
      LED5_SetHigh();
    } else if (xa == 8) // DP
    {
      // TRISA = 0b11011010;
      // TRISC = 0b11011111;
      // LED1 = OFF;
      // LED3 = ON;
      LED_DISABLE();
      LED1_SetDigitalOutput();
      LED3_SetDigitalOutput();
      LED1_SetLow();
      LED3_SetHigh();
    }
  } else if (nu == 3) {
    if (xa == 1) // A
    {
      // TRISA = 0b11011001;
      // TRISC = 0b11011111;
      // LED3 = OFF;
      // LED2 = ON;
      LED_DISABLE();
      LED3_SetDigitalOutput();
      LED2_SetDigitalOutput();
      LED3_SetLow();
      LED2_SetHigh();
    } else if (xa == 2) // B
    {
      // TRISA = 0b11011101;
      // TRISC = 0b11011110;
      // LED4 = OFF;
      // LED2 = ON;
      LED_DISABLE();
      LED4_SetDigitalOutput();
      LED2_SetDigitalOutput();
      LED4_SetLow();
      LED2_SetHigh();
    } else if (xa == 3) // C
    {
      // TRISA = 0b11011101;
      // TRISC = 0b11011101;
      // LED2 = OFF;
      // LED5 = ON;
      LED_DISABLE();
      LED2_SetDigitalOutput();
      LED5_SetDigitalOutput();
      LED2_SetLow();
      LED5_SetHigh();
    } else if (xa == 4) // D
    {
      // TRISA = 0b11011101;
      // TRISC = 0b11011011;
      // LED6 = OFF;
      // LED2 = ON;
      LED_DISABLE();
      LED6_SetDigitalOutput();
      LED2_SetDigitalOutput();
      LED6_SetLow();
      LED2_SetHigh();
    } else if (xa == 5) // E
    {
      // TRISA = 0b11011101;
      // TRISC = 0b11011101;
      // LED5 = OFF;
      // LED2 = ON;
      LED_DISABLE();
      LED5_SetDigitalOutput();
      LED2_SetDigitalOutput();
      LED5_SetLow();
      LED2_SetHigh();
    } else if (xa == 6) // F
    {
      // TRISA = 0b11011001;
      // TRISC = 0b11011111;
      // LED2 = OFF;
      // LED3 = ON;
      LED_DISABLE();
      LED2_SetDigitalOutput();
      LED3_SetDigitalOutput();
      LED2_SetLow();
      LED3_SetHigh();
    } else if (xa == 7) // G
    {
      // TRISA = 0b11011101;
      // TRISC = 0b11011110;
      // LED2 = OFF;
      // LED4 = ON;
      LED_DISABLE();
      LED2_SetDigitalOutput();
      LED4_SetDigitalOutput();
      LED2_SetLow();
      LED4_SetHigh();
    } else if (xa == 8) // DP
    {
      // TRISA = 0b11011100;
      // TRISC = 0b11011111;
      // LED1 = OFF;
      // LED2 = ON;
      LED_DISABLE();
      LED1_SetDigitalOutput();
      LED2_SetDigitalOutput();
      LED1_SetLow();
      LED2_SetHigh();
    }
  }
  __delay_us(30);
}

void SSD(unsigned char num, unsigned char xn) {
  if (num == 0) {
    SSLED(xn, 1);
    SSLED(xn, 2);
    SSLED(xn, 3);
    SSLED(xn, 4);
    SSLED(xn, 5);
    SSLED(xn, 6);
    SSLED(1, 8); // G
  } else if (num == 1) {
    SSLED(xn, 5); // E
    SSLED(xn, 6); // F
    SSLED(1, 8);
    SSLED(1, 8);
    SSLED(1, 8);
    SSLED(1, 8);
    SSLED(1, 8);
  } else if (num == 2) {
    SSLED(xn, 1); // A
    SSLED(xn, 2); // B
    SSLED(xn, 4); // D
    SSLED(xn, 5); // E
    SSLED(xn, 7); // G
    SSLED(1, 8);
    SSLED(1, 8);
  } else if (num == 3) {
    SSLED(xn, 1); // A
    SSLED(xn, 4); // D
    SSLED(xn, 5); // E
    SSLED(xn, 6); // F
    SSLED(xn, 7); // G
    SSLED(1, 8);
    SSLED(1, 8);
  } else if (num == 4) {
    SSLED(xn, 3); // C
    SSLED(xn, 5); // E
    SSLED(xn, 6); // F
    SSLED(xn, 7); // G
    SSLED(1, 8);
    SSLED(1, 8);
    SSLED(1, 8);
  } else if (num == 5) {
    SSLED(xn, 1); // A
    SSLED(xn, 3); // C
    SSLED(xn, 4); // D
    SSLED(xn, 6); // F
    SSLED(xn, 7); // G
    SSLED(1, 8);
    SSLED(1, 8);
  } else if (num == 6) {
    SSLED(xn, 1); // A
    SSLED(xn, 2); // B
    SSLED(xn, 3); // C
    SSLED(xn, 6); // F
    SSLED(xn, 7); // G
    SSLED(1, 8);
    SSLED(1, 8);
  } else if (num == 7) {
    SSLED(xn, 3); // C
    SSLED(xn, 4); // D
    SSLED(xn, 5); // E
    SSLED(xn, 6); // F
    SSLED(1, 8);
    SSLED(1, 8);
    SSLED(1, 8);
  } else if (num == 8) {
    SSLED(xn, 1);
    SSLED(xn, 2);
    SSLED(xn, 3);
    SSLED(xn, 4);
    SSLED(xn, 5);
    SSLED(xn, 6);
    SSLED(xn, 7);
  } else if (num == 9) {
    SSLED(xn, 3); // C
    SSLED(xn, 4); // D
    SSLED(xn, 5); // E
    SSLED(xn, 6); // F
    SSLED(xn, 7); // G
    SSLED(1, 8);
    SSLED(1, 8);
  } else if (num == 10) { //.
    SSLED(xn, 8);         // dot
    SSLED(1, 8);
    SSLED(1, 8);
    SSLED(1, 8);
    SSLED(1, 8);
    SSLED(1, 8);
    SSLED(1, 8);
  } else if (num == 11) { // C
    SSLED(xn, 1);         // A             //      D
    SSLED(xn, 2);         // B             //    ====
    SSLED(xn, 3);         // C             // C | G  |E
    SSLED(xn, 4);         // D             //    ====
    SSLED(1, 8);          //               // B |    |F
    SSLED(1, 8);          //               //    ====
    SSLED(1, 8);          //               //      A
  } else if (num == 12) { // set1 up O
    SSLED(xn, 3);         // C
    SSLED(xn, 4);         // D
    SSLED(xn, 5);         // E
    SSLED(xn, 7);         // G
    SSLED(1, 8);          // F
    SSLED(1, 8);          // B
    SSLED(1, 8);          // A
  } else if (num == 13) { // set2 down O
    SSLED(xn, 1);         // A
    SSLED(xn, 2);         // B
    SSLED(xn, 6);         // F
    SSLED(xn, 7);         // G
    SSLED(1, 8);          // C
    SSLED(1, 8);          // D
    SSLED(1, 8);          // E
  }
}
