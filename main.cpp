/*
initial 2020/05/20
*/

#include "mbed.h"

AnalogIn L1(PA_0);
AnalogIn L2(PA_1);
AnalogIn L3(PA_3);
AnalogIn L4(PA_4);
AnalogIn L5(PA_5);
Serial pc(PA_9, PA_10, 9600);

DigitalOut red(PA_7);
DigitalOut yellow(PB_0);
DigitalOut blue(PB_1);

int main()
{
    float meas_r[5];
    float meas_v[5];
    float sum = 0.0;
    int i;
    
    pc.printf("\nAnalogIn example\n");

    while(1) {
        sum = 0.0;

        meas_r[0] = L1.read();// Read the analog input value (value from 0.0 to 1.0 = full ADC conversion range)
        meas_r[1] = L2.read();// Read the analog input value (value from 0.0 to 1.0 = full ADC conversion range)
        meas_r[2] = L3.read();// Read the analog input value (value from 0.0 to 1.0 = full ADC conversion range)
        meas_r[3] = L4.read();// Read the analog input value (value from 0.0 to 1.0 = full ADC conversion range)
        meas_r[4] = L5.read();// Read the analog input value (value from 0.0 to 1.0 = full ADC conversion range)

        for(i=0;i<5;i++){    
            meas_v[i] = meas_r[i] * 3300; // Converts value in the 0V-3.3V range
            pc.printf("%.0f,", meas_v[i]);
            sum += meas_v[i];
        }
        
        pc.printf("%.0f\r\n",sum/5.0);

        // LED is ON is the value is below 1V
        if (sum > 2000) {
            red = 1; // LED ON
            yellow = 0;
            blue = 0;
        }else if(sum > 1200) {
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
