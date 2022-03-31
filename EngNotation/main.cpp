#include <iostream>
#include <string.h>
#include <math.h>

#define DEBUG4


using namespace std;
char exponentToSufix(int expo);
void fragNumber(char *buffer, unsigned int number, int *pos);


int main()
{
    cout << "Type a number" << endl;
    double number;
    int expo = 0;
    int pos = 0;
    char mathBuffer[7];

    cin >> number;
    cout << number << endl;

    // Verifies if number is not a number
    if (isnan(number)) {
        strcpy(mathBuffer, "nan");
        cout << mathBuffer;
        return 0;
    }

    // Verifies if number is infinite
    if (isfinite(number) == 0) {
        strcpy(mathBuffer, "inf");
        cout << mathBuffer;
        return 0;
    }

    // Negative is false
    // Positive is true
    bool signal = (number < 0.0) ? true: false;
    // Verifies if number is negative
    if (signal) {
        // Transforms the number in positive
        number = -number;
        mathBuffer[pos++] = '-';
    }

    // We have two cases:
    // 1 - numbers greater than 1
    // 2 - numbers between 0 and 1

    if (number >= 1.0 && number < 10.0) {

        unsigned int d = (unsigned int) number;
        double remainder = number - d;

        // Tests if the number has no decimal part
        if (remainder == 0.000000) {
            mathBuffer[pos++] = d + '0';
            mathBuffer[pos++] = '\0';
            //return mathBuffer;
            return 0;
        }

        // Anda casas para a direita
        while(number < 1000){
            number = number * 10;
            expo --;
        }

        // Arredondamento
        // Pega a parte inteira de number

        // Caso a parte inteira seja menor que round tem que incrementar em 1
        unsigned int rounding = round(number);
        d = (unsigned int) number;

        if (d < rounding) {
            d++;
        }

        uint8_t algarism = 0;

        while(d >= 1000) {
            d = d - 1000;
            algarism ++;
        }

        // Atualiza o buffer
        mathBuffer[pos++] = algarism + '0';
        algarism = 0;

        while(d >= 100) {
            d = d - 100;
            algarism ++;
        }

        // Atualiza o buffer
        mathBuffer[pos++] = algarism + '0';
        algarism = 0;

        while(d >= 10) {
            d = d - 10;
            algarism ++;
        }
        mathBuffer[pos++] = algarism + '0';
        algarism = 0;

        while(d >= 1) {
            d = d - 1;
            algarism ++;
        }

        mathBuffer[pos++] = algarism + '0';
        mathBuffer[pos++] = exponentToSufix(expo);
        // Acrescenta um caracter nulo para finalizar a string
        mathBuffer[pos++] = '\0';

    // Caso o número esteja entre (0 e 1)
    // Ex: 0.000537 -> 537u
    }else if (number > 0.0 && number < 1.0){
        unsigned int d = (unsigned int) number;
        double remainder = number - d;

        while((remainder > 0.0001 && expo > -6) || expo > -3) {
            number = number * 10;
            expo--;
            d = (int)number;
            remainder = number - d;

            if (expo == -3) {
                if (d < 10){
                    continue;
                }else{
                   break;
                }
            }
        }

        if (expo < -3 && expo > -6 ) {
            // Multiplies number until expo -6
            for (int i = expo; i > -6; i--) {
                number = number * 10;
                expo--;
            }
            d = (unsigned int) number;
        }
        // Caso a parte inteira seja menor que round tem que incrementar em 1
        unsigned int rounding = round(number);

        if (d < rounding)
            d++;

        fragNumber(mathBuffer, d, &pos);

        mathBuffer[pos++] = exponentToSufix(expo);
        // Acrescenta um caracter nulo para finalizar a string
        mathBuffer[pos++] = '\0';

    }else {
        expo = 0;
        fragNumber(mathBuffer, round(number), &pos);
        mathBuffer[pos++] = exponentToSufix(expo);
       // algarism = 0;
        // Acrescenta um caracter nulo para finalizar a string
        mathBuffer[pos++] = '\0';
    }

    cout << "Numero: " << mathBuffer << endl;

    return 0;
}

char exponentToSufix(int expo) {

    switch(expo) {
        case -18: return 'a';           // atto
        case -15: return 'f';           // femto
        case -12: return 'p';           // pico
        case -9: return 'n';            // nano
        case -6: return 'u';            // micro
        case -3: return 'm';            // milli
        case 0: return ' ';
        case 3: return 'k';             // kilo
        case 6: return 'M';             // Mega
        case 9: return 'G';             // Giga
        case 12: return 'T';            // Tera
        case 15: return 'P';            // Pera
        case 18: return 'E';            // Exa

        default: return -1;
    }
}

void fragNumber(char *buffer, unsigned int number, int *pos){
    unsigned char algarism = 0;
    bool isFirstZero = true;

    while(number >= 1000) {
        number = number - 1000;
        algarism ++;
        isFirstZero = false;
    }

    if (!isFirstZero) {
        // Atualiza o buffer
        buffer[*pos] = algarism + '0';
        ++*pos;
    }

    algarism = 0;

    while(number >= 100) {
        number = number - 100;
        algarism ++;
        isFirstZero = false;
    }

    if (!isFirstZero){
        // Atualiza o buffer
        buffer[*pos] = algarism + '0';
        ++*pos;
    }

    algarism = 0;

    while(number >= 10) {
        number = number - 10;
        algarism ++;
        isFirstZero = false;
    }

    if (!isFirstZero){
        // Atualiza o buffer
        buffer[*pos] = algarism + '0';
        ++*pos;
    }
    algarism = 0;

    while(number > 0) {
        number = number - 1;
        algarism ++;
    }

    buffer[*pos] = algarism + '0';
    ++*pos;
}

