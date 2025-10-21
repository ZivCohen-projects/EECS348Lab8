#include <stdio.h>

int main() {
    double temp, converted;
    char fromScale, toScale;

    printf("Enter the temperature value: ");
    scanf("%lf", &temp);
    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &fromScale);
    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &toScale);

    // Convert input to Celsius first
    double tempC;
    if (fromScale == 'C' || fromScale == 'c') tempC = temp;
    else if (fromScale == 'F' || fromScale == 'f') tempC = (temp - 32) * 5 / 9;
    else if (fromScale == 'K' || fromScale == 'k') tempC = temp - 273.15;

    // Convert Celsius to target scale
    if (toScale == 'C' || toScale == 'c') converted = tempC;
    else if (toScale == 'F' || toScale == 'f') converted = tempC * 9 / 5 + 32;
    else if (toScale == 'K' || toScale == 'k') converted = tempC + 273.15;

    printf("Converted temperature: %.2lf %c\n", converted, toScale);

    // Categorize
    const char *category, *advisory;
    if (tempC < 0) { category = "Freezing"; advisory = "Wear a jacket"; }
    else if (tempC < 10) { category = "Cold"; advisory = "Wear a sweater"; }
    else if (tempC < 25) { category = "Comfortable"; advisory = "Enjoy the weather"; }
    else if (tempC < 35) { category = "Hot"; advisory = "Drink lots of water!"; }
    else { category = "Extreme Heat"; advisory = "Stay indoors!"; }

    printf("Temperature category: %s\n", category);
    printf("Weather advisory: %s\n", advisory);

    return 0;
}
