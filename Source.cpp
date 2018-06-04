/*
* @file  practika.cpp
* @autor Груба А.Г. 515-В
* @date 5 мая 2018
* @drief Летняя практика
* Программа, которая находит периметр многоугольника по его координатам.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include <string.h>
#include <stdio.h>
#include <conio.h>
float array_x[10];
float array_y[10];
int kol = 0;
float D;
void coordinates(double a, double b);
void schet();
int main()
{
	setlocale(LC_ALL, "Rus");
	char *f1, *f2; 
	char coor_s[100], coor[20], x[10], y[10];
	f1=&x[0];
	f2 = &y[0];
	int y1 = 0;
	double a=0, b=0;
	printf("Введите координаты многоугольника, разделенные пробелами в формате x+iy\n");
	gets_s(coor_s);
	printf("Вы ввели следущие координаты многоугольника\n");
	puts(coor_s);
	for (int i = 0; ; i++) {
		if (coor_s[i] == 'i') {
			coor[i] = '\0';
			break;
		}
		coor[i] = coor_s[i];
	}
	for (int i = 0; coor_s[i] != '\0'; i++) {
		if (coor_s[i] == 32) {
			for (int j = 0; ; j++, i++) {
				if (coor_s[i + 1] == 'i') {
					coor[j] = '\0';
					break;
				}
				coor[j] = coor_s[i + 1];
			}
		}
		
		x[0] = coor[0];
		for (int k = 1;; k++) {
			x[k] = coor[k];
			if (coor[k] == 43 || coor[k] == 45) {
				x[k] = '\0';
				break;
			}

			y1 = k;
		}
		for (int z = 0; ; z++, y1++) {
			y[z] = coor[y1 + 1];
			if (coor[y1] == '\0') {
				y[z] = '\0';
				break;
			}
		}
	
		y1 = 0;
		if ((i % 2 == 0) && (i >= 4)) {
			a = atof (f1);
			b = atof(f2);
			coordinates(a, b);
		}
	}
	schet();

	printf("Периметр иногоугольника(в условных единицах)\n%f", D);
	_getch();
}
void coordinates(double a, double b) {
	array_x[kol] = a;
	array_y[kol] = b;
	kol++;
}
void schet() {
	float d;
	D = sqrt((array_x[kol - 1] - array_x[0])*(array_x[kol - 1] - array_x[0]) + (array_y[kol - 1] - array_y[0])*(array_y[kol - 1] - array_y[0]));
	for (int i = 0; i < kol - 1; i++) {
		d = sqrt((array_x[i + 1] - array_x[i])*(array_x[i + 1] - array_x[i]) + (array_y[i + 1] - array_y[i])*(array_y[i + 1] - array_y[i]));
		D += d;
	}
}
