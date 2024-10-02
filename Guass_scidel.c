#include <stdio.h>

float approximationx(float a1, float a2, float a3, float b1, float b2, float b3, 
                    float c1, float c2, float c3, float d1, float d2, float d3, 
                    float y, float z);
float approximationy(float a1, float a2, float a3, float b1, float b2, float b3, 
                    float c1, float c2, float c3, float d1, float d2, float d3, 
                    float x, float z);
float approximationz(float a1, float a2, float a3, float b1, float b2, float b3, 
                    float c1, float c2, float c3, float d1, float d2, float d3, 
                    float x, float y);

int main() {
    float a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3;
    
    printf("Enter the coefficients of the first equation: \n");
    scanf("%f%f%f%f", &a1, &b1, &c1, &d1);
    
    printf("Enter the coefficients of the second equation: \n");
    scanf("%f%f%f%f", &a2, &b2, &c2, &d2);
    
    printf("Enter the coefficients of the third equation: \n");
    scanf("%f%f%f%f", &a3, &b3, &c3, &d3);
    
    float x = 0.0, y = 0.0, z = 0.0,diff1=1,diff2=1,diff3=1,x1,y1,z1;
    while(diff1 >= 0.001 && diff2 >= 0.001 && diff3 >=0.001){
        x1 = x;
        y1 = y;
        z1 = z;
        x = approximationx(a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3, y, z);
        y = approximationy(a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3, x, z);
        z = approximationz(a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3, x, y);
        diff1=x1-x;
        diff2=y1-y;
        diff3=z1-z;
        if(diff1<0){
            diff1 = -diff1;
        }
        if(diff2<0){
            diff2 = -diff2;
        }
        if(diff3<0){
            diff3 = -diff3;
        }
    }
    
    printf("Values: x = %f, y = %f, z = %f\n", x, y, z);
    
    return 0;
}

float approximationx(float a1, float a2, float a3, float b1, float b2, float b3, 
                    float c1, float c2, float c3, float d1, float d2, float d3, 
                    float y, float z) {
    float x;
    x = (1 / a1) * (d1 - b1 * y - c1 * z);
    return x;
}
float approximationy(float a1, float a2, float a3, float b1, float b2, float b3, 
                    float c1, float c2, float c3, float d1, float d2, float d3, 
                    float x, float z) {
    float y;
    y = (1 / b2) * (d2 - a2 * x - c2 * z);
    return y;
}
float approximationz(float a1, float a2, float a3, float b1, float b2, float b3, 
                    float c1, float c2, float c3, float d1, float d2, float d3, 
                    float x, float y) {
    float z;
    z = (1 / c3) * (d3 - a3 * x - b3 * y);
    return z;
}