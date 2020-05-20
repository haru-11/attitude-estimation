/*
initial 2020/05/20
*/

#include "mbed.h"

AnalogIn analog_value(PA_0);
Serial pc(PA_9, PA_10, 9600);

DigitalOut red(PA_7);
DigitalOut yellow(PB_0);
DigitalOut blue(PB_1);

int main()
{
    float meas_r;
    float meas_v;
    
    pc.printf("\nAnalogIn example\n");

    while(1) {

        meas_r = analog_value.read(); // Read the analog input value (value from 0.0 to 1.0 = full ADC conversion range)
        meas_v = meas_r * 3300; // Converts value in the 0V-3.3V range
        
        // Display values
        pc.printf("%f,%.0f\r\n", meas_r, meas_v);

        // LED is ON is the value is below 1V
        if (meas_v > 2000) {
            red = 1; // LED ON
            yellow = 0;
            blue = 0;
        }else if(meas_v > 1200) {
            red = 1; // LED ON
            yellow = 1;
            blue = 0;
        }else{
            red = 1; // LED ON
            yellow = 1;
            blue = 1;
        }

        wait(0.2); // 1 second
    }
}
