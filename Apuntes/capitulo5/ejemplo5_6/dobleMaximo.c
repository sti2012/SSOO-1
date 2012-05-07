//ejemplo5_6
//dobleMaximo.c

static float maximo(float num1, float num2){
    if (num1 > num2){
        return num1;
    }
    else if (num1 < num2){
        return num2;
    }
    else{
        return 0;
    }
}

extern float calculo(float num1, float num2){
    return 2*maximo(num1, num2);
}

