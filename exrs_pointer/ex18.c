#include <stdio.h>
#include <stdlib.h>

void calc_esfera(float R, float *area, float *volume);

int main()
{
    float R, area, volume;
   
    R=5.0;
    area=2.0;
    volume=2.0;

    calc_esfera(R, &area, &volume);
    return 0;
}

void calc_esfera(float R, float *area, float *volume)
{
    float p = 3.14;
    *area = 4 *p*R*R;
    *volume = (p*R*R*R*4)/3;

    printf("%f area\n",*area);
    printf("%f volume",*volume);
}