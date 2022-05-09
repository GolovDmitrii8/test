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
    FILE *input,*output;
	input = fopen ("input.txt","r");
	output = fopen ("output.txt","w");
    do
    {
         fscanf(input," %c",&q);
     switch(q)                         //Разделение на векторный и обычный калькулятор
     {
     case 's':                         //Обьчный калькулятор
    fscanf(input,"%f ",&a);             //Ввод переменных пользователем
    fprintf(output,"%f ",a);
    fscanf(input,"%f",&b);
    fscanf(input," %c",&c);
    switch(c)                      //Блок арифметичиских операций
      {
        case '+':                  // Сложение
        fprintf(output,"+ %f ",b);
        fprintf(output,"= %f\n", a+b);
        break;
        case '-':                 // Вычитание
        fprintf(output,"- %f ",b);
        fprintf(output,"= %f\n", a-b);
        break;
        case '*':                 // Умножение
        fprintf(output,"* %f ",b);
        fprintf(output,"= %f\n", a*b);
        break;
        case '/':                 // Деление
        fprintf(output,"/ %f ",b);
        fprintf(output,"= %f\n", a/b);
        break;
        case '!':                 // Факториал
        fprintf(output,"! ");
        x=a;
        for(d=1;d<x;d++)
        {
        a=a*(x-d);
        }
        if (a<0){
        fprintf(output,"Вы берёте факториал отрицательно числа нужно ввести положительное");
        }else{
        fprintf(output,"= %f\n",a);
        }
        break;
        case '^':                 // Возведение в степень
        fprintf(output,"^ %f ",b);
        fprintf(output,"= %f\n", pow(a,b));
        break;
        default:                 // Сообщение о том что нет операции
        fprintf(output,"Такой операции нет введите доступную операцию");
      }
			break;
    case 'v':                   //Векторный калькулятор
    	float *x,*y;
    	double res;
    	int size;
    	char c;
    	fscanf(input,"%i",&size);
    	x=malloc(size*sizeof(int));
    	y=malloc(size*sizeof(int));
    	for(int i=0;i<size;i++)       //Ввод переменных
    	 {
    	  fscanf(input,"%f",&x[i]);
    	     }
    	fprintf(output,"( ");
    	  for (int i = 0; i < size; i++)
    	     {
    	  fscanf(input," %f",&y[i]);   //Вывод переменной x
    	      }
    	   for (int i=0;i<size;i++)
    	      {
    	     	fprintf(output,"%f ", x[i]);
    	                        }
    	   fprintf(output,") ");
    	     fscanf(input," %c",&c);
    	    switch(c)                      //Блок арифметичиских операций
    	          {
    	            case '+':                  // Сложение
    	           fprintf(output,"+ (");                          //Вывод переменной y
    	           for (int i=0;i<size;i++)
    	                 {
    	            fprintf(output," %f ", y[i]);
    	                 }
    	            fprintf(output,")");
    	            fprintf(output," = ");
    	            fprintf(output,"( ");
    	            for(int i=0;i<size;i++) fprintf(output,"%f ",x[i]+y[i]);
    	            fprintf(output,") ");
    	            break;
    	            case '-':                 // Вычитание
    	            	fprintf(output,"- (");
    	            for (int i=0;i<size;i++)
    	                   {
    	            fprintf(output," %f ", y[i]);
    	                   }
    	            fprintf(output,")");
    	            fprintf(output," = ");
    	            fprintf(output,"( ");
    	            for(int i=0;i<size;i++) fprintf(output,"%f ",x[i]-y[i]);
    	            fprintf(output,") ");
    	            break;
    	            case '*':                 // Скалярное произведение
    	            	fprintf(output,"* (");
    	             for (int i=0;i<size;i++)
    	            	     {
    	            fprintf(output," %f ", y[i]);
    	                     }
    	            fprintf(output,")");
    	            fprintf(output," = ");
    	            for(int i=0;i<size;i++) res += x[i]*y[i];
    	            fprintf(output,"%lf",res);
    	            break;
    	            default:                 // Сообщение о том что нет операции
    	            fprintf(output,"Такой операции нет введите доступную операцию");
    	            free(x);
    	            free(y);
    	          }
     }
      fscanf(input," %c",&r);
    } while (r == 'y');
    fclose(input);
    fclose(output);
   return 0;
}
