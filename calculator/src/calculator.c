/*
 ============================================================================
 Name        : calculator.c
 Author      : 13
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>   //Подключение библиотеки ввода-вывода
#include <math.h>    //Подключение математической библиотеки
#include <stdlib.h>  //Подключение библиотеки для работы с памятью

int main(int argc,char *argv[]) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
    float a,b,x,d;
    char c,r,q;
    do
    {
    printf("Введите с каким калькулятором вы хотите работать Векторный-v Обычный-c:");
         scanf(" %c",&q);
     switch(q)                         //Разделение на векторный и обычный калькулятор
     {
     case 'c':                         //Обьчный калькулятор
    printf("Список доступных команд:\n");//Список доступных команд
    	      printf("Сложение +\n");
    	      printf("Вычитание -\n");
    	      printf("Умножение *\n");
    	      printf("Деление /\n");
    	      printf("Факториал числа !\n");
    	      printf("Возведение в степень ^\n");
    printf("Введите первое число:");   //Ввод переменных пользователем
    scanf("%f",&a);
    printf("Введите второе число:");
    scanf("%f",&b);
    printf("Введите желаемую операцию:");
    scanf(" %c",&c);
    switch(c)                      //Блок арифметичиских операций
      {
        case '+':                  // Сложение
        printf("Результат сложения: %f\n", a+b);
        break;
        case '-':                 // Вычитание
        printf("Результат вычитания: %f\n", a-b);
        break;
        case '*':                 // Умножение
        printf("Результат умножения: %f\n", a*b);
        break;
        case '/':                 // Деление
        printf("Результат деления:%f\n", a/b);
        break;
        case '!':                 // Факториал
        x=a;
        for(d=1;d<x;d++)
        {
        a=a*(x-d);
        }
        if (a<0){
        printf("Вы берёте факториал отрицательно числа нужно ввести положительное");
        }else{
        printf("Результат вычисление факториала:%f\n",a);
        }
        break;
        case '^':                 // Возведение в степень
        printf("Результат возведения в степень:%f\n", pow(a,b));
        break;
        default:                 // Сообщение о том что нет операции
        printf("Такой операции нет введите доступную операцию");
      }
			break;
    case 'v':                   //Векторный калькулятор
    	float *x,*y;
    	double res;
    	int size;
    	char c;
    	printf("Список доступных команд:\n");//Список доступных команд
    	     printf("Сложение +\n");
    	     printf("Вычитание -\n");
    	     printf("Скалярное произведение *\n");
    	printf("Введите размер векторов: ");
    	scanf("%i",&size);
    	x=malloc(size*sizeof(int));
    	y=malloc(size*sizeof(int));
    	printf("Введите первый вектор: ");    //Ввод переменных пользователем
    	for(int i=0;i<size;i++) scanf("%f",&x[i]);
    	printf("Введите второй вектор: ");
    	for(int i=0;i<size;i++) scanf("%f",&y[i]);
    	    printf("Введите желаемую операцию:");
    	    scanf(" %c",&c);
    	    switch(c)                      //Блок арифметичиских операций
    	          {
    	            case '+':                  // Сложение
    	            printf("Сложение векторов: ");
    	            for(int i=0;i<size;i++) printf("%f \n",x[i]+y[i]);
    	            printf("\n");
    	            break;
    	            case '-':                 // Вычитание
    	            for(int i=0;i<size;i++) printf("%f \n",x[i]-y[i]);
    	            printf("\n");
    	            break;
    	            case '*':                 // Скалярное произведение
    	            for(int i=0;i<size;i++) res += x[i]*y[i];
    	            printf("%lf",res);
    	            break;
    	            default:                 // Сообщение о том что нет операции
    	            printf("Такой операции нет введите доступную операцию");
    	            free(x);
    	            free(y);
    	          }
     }
    printf("Хотите продолжить? (y/n)"); // Запрос на повторное выполнение
    scanf(" %c",&r);
    } while (r == 'y');
   return 0;
}
