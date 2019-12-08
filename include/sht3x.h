#ifndef _SHT3X_H
#define _SHT3X_H

#include <soft_i2c.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SHT3x_ADDR 0x44
#define SHT3x_MSB 0x2C
#define SHT3x_LSB 0x10

typedef struct {
  float temperature;
  float humidity;
} SHT3X;

void readSensor(SHT3X*);

#ifdef __cplusplus
}
#endif

#endif
