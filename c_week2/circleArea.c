#include <stdio.h>
#include <math.h>

float circle(float radius){
    const double pi = 3.14159265358979323846;
    float area;
    area = pi * radius;
    return area;
}

float sphere(float radius){
    const double pi = 3.14159265358979323846;
    float volume;
    volume = (4 * pi * radius * radius * radius) / 3;
    return volume;
}

int main(){
    float radius, area;
    printf("enter the radius");
    scanf("%f", &radius);
    area = sphere(radius);
    printf("the volume of a sphere with radius %f is %f\n", radius,area);
    return area;
}