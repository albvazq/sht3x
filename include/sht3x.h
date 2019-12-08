#ifndef _TCA9548A_H
#define _TCA9548A_H

#include <soft_i2c.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SHT3x_ADDR 0x44
#define SHT3x_SS 0x2C
#define SHT3x_HIGH 0x06
#define SHT3x_READ 0x00

typedef struct {
  float temperature;
  float humidity;
} SHT3X;

void readSensor(SHT3X*);

#ifdef __cplusplus
}
#endif

#endif
