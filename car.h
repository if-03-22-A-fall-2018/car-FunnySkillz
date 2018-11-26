/*----------------------------------------------------------
*				HTBLA-Leonding / Klasse: 2AHIF
* ---------------------------------------------------------
* Exercise Number: 0
* Title:			car.h
* Author:			Sebastijan Bogdan
* Due Date:		27.11.2018
* ----------------------------------------------------------
* Description:
* Car abstract data type demo.
* ----------------------------------------------------------
*/
#ifndef ___CAR_H
#define ___CAR_H

enum CarType{AIXAM, FIAT_MULTIPLA, JEEP};
enum Color{RED, GREEN, ORANGE, BLACK, SILVER, BLUE};

typedef struct CarImplementation* Car;

Car get_car(CarType);
enum CarType get_type(Car car1);
enum Color get_color(Car car1);
double get_fill_level(Car car1);
double get_acceleration_rate(Car car1);
double get_speed(Car car1);
void init();
void set_acceleration_rate(Car car1, double accelerate);
void accelerate(Car car1);

#endif
