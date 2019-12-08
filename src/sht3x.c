#include <sht3x.h>

#ifdef __cplusplus
extern "C" {
#endif

void readSensor(SHT3X* s) {
  byte data[8] = {0};
  int i = 0;
  i2c_start(*getBus());
  i2c_send_byte(*getBus(), SHT3x_ADDR << 1 | I2C_WRITE);
  i2c_send_byte(*getBus(), SHT3x_MSB);
  i2c_send_byte(*getBus(), SHT3x_LSB);
  usleep(5000);
  i2c_start(*getBus());
  i2c_send_byte(*getBus(), SHT3x_ADDR << 1 | I2C_READ);

  for(i = 0; i < 6; i++) {
    data[i] = i2c_read_byte(*getBus());
    i2c_send_bit(*getBus(), I2C_ACK);
  }
  i2c_stop(*getBus());

  s->temperature = (((data[0] * 256) + data[1]) * 175.0) / 65535.0 - 45.0;
  s->humidity = (((data[3] * 256) + data[4])) * 100.0 / 65535.0;
}

#ifdef __cplusplus
}
#endif