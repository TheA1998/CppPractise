// 数值的整数次方
#include<iostream>
#include<cmath>

bool g_InvalidInput = false;

double Power(double base, int exponent);
double PowerWithUnsignedExponent(double base, unsigned int absExponent);
bool equal(double num1, double num2);

double Power(double base, int exponent) {
	g_InvalidInput = false;
	if (equal(base, 0.0) && exponent < 0) {
        g_InvalidInput = true;
        return 0.0;
	}
    unsigned int absExponent = (unsigned int)(exponent);
    if (exponent < 0)
        absExponent = (unsigned int)-exponent;

    double result = PowerWithUnsignedExponent(base, absExponent);
    if (exponent < 0)
        result = 1.0 / result;
    
    return result;
}

double PowerWithUnsignedExponent(double base, unsigned int absExponent) {
    double result = 1.0;
    for (int i = 1; i <= absExponent; i++)
        result *= base;

    return result;

}

double PowerWithUnsignedExponent_recursively(double base, unsigned int exponent) {
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;

    double result = PowerWithUnsignedExponent_recursively(base, exponent >> 1);
    result *= result;
    if ((exponent & 0x1) == 1)
        result *= base;

    return result;
}

bool equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}