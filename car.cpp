#include "car.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define CARS_COUNT 6

#define CAR_PARK_SIZE 6
#define MAX_ACCELERATION_RATE_AIXAM 1
#define MAX_ACCELERATION_RATE_MULTIPLA 2.26
#define MAX_ACCELERATION_RATE_JEEP 3.14

#define MAX_SPEED_AIXAM 45
#define MAX_SPEED_MULTIPLA 170
#define MAX_SPEED_JEEP 196


struct CarImplementation{
  enum CarType carType;
  enum Color color;
  double fill_level;
  double acceleration_rate;
  double current_speed;
  bool is_rented;
};

static struct CarImplementation AIXAM1 = {AIXAM, RED, 16, 0, 0, false};
static struct CarImplementation MULTIPLA1 = {FIAT_MULTIPLA, GREEN, 65, 0, 0, false};
static struct CarImplementation MULTIPLA2 = {FIAT_MULTIPLA, BLUE, 65, 0, 0, false};
static struct CarImplementation MULTIPLA3 = {FIAT_MULTIPLA, ORANGE, 65, 0, 0, false};
static struct CarImplementation JEEP1 = {JEEP, SILVER, 80, 0, 0, false};
static struct CarImplementation JEEP2 = {JEEP, BLACK, 80, 0, 0, false};

Car car_park[CARS_COUNT] = {&AIXAM1, &MULTIPLA1, &MULTIPLA2, &MULTIPLA3, &JEEP1, &JEEP2};

Car get_car(CarType carType){
  for (int i = 0; i < CARS_COUNT; i++) {
  if (car_park[i]->carType == carType && !car_park[i]->is_rented) {
    car_park[i]->is_rented = true;
    return car_park[i];
    }
  }
  return 0;
}
enum CarType get_type(Car car1){ return car1->carType; }
enum Color get_color(Car car1){ return car1->color; }
double get_fill_level(Car car1){ return car1->fill_level; }
double get_acceleration_rate(Car car1){ return car1->acceleration_rate; }
double get_speed(Car car1){ return round(car1->current_speed); }

void init(){
  for(int i = 0; i < CARS_COUNT; i++)
  {
    car_park[i]->acceleration_rate = 0;
    car_park[i]->is_rented = false;
    car_park[i]->current_speed = 0;
    if(i == 0)
    {
      car_park[i]->fill_level = 16;
    }
    else if(i < 4)
    {
      car_park[i]->fill_level = 65;
    }
    else
    {
      car_park[i]->fill_level = 80;
    }
  }
}
void set_acceleration_rate(Car car1, double acceleration){

if(acceleration >= -8)
   {
     switch (car1->carType) {
      case AIXAM:
        if(acceleration <= 1)
        {
          car1->acceleration_rate = acceleration;
        }
        else
        {
          car1->acceleration_rate = 1;
        }
      break;
      case FIAT_MULTIPLA:
        if(acceleration <= 2.26)
        {
         car1->acceleration_rate = acceleration;
        }
        else
        {
         car1->acceleration_rate = 2.26;
        }
      break;
      case JEEP:
        if(acceleration <= 3.14)
        {
         car1->acceleration_rate = acceleration;
        }
        else
        {
         car1->acceleration_rate = 3.14;
        }
      break;
     }
   }
   else
   {
     car1->acceleration_rate = -8;
   }
}
void accelerate(Car car1){
  car1->current_speed += car1->acceleration_rate*3.6;

  if((car1->carType == AIXAM) && (car1->current_speed > 45))
  {
    car1->current_speed = 45;
  }
  else if((car1->carType == FIAT_MULTIPLA) && (car1->current_speed > 170))
  {
    car1->current_speed = 170;
  }
  else if((car1->carType ==JEEP) && (car1->current_speed > 196))
  {
    car1->current_speed = 196;
  }
}
