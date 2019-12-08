#include <sht3x.h>

#ifdef __cplusplus
extern "C" {
#endif

void readSensor(SHT3X* s) {
  byte data[8] = {0};
  int i = 0;
  i2c_start(*getBus());
  i2c_send_byte(*getBus(), SHT3x_ADDR << 1 | I2C_WRITE);
  i2c_send_byte(*getBus(), SHT3x_SS);
  i2c_send_byte(*getBus(), 0x00);
  i2c_start(*getBus());
  i2c_send_byte(*getBus(), SHT3x_ADDR << 1 | I2C_READ);
  i2c_send_byte(*getBus(), SHT3x_SS);
  for(i = 0; i < 8; i++) {
    data[i] = i2c_read_byte(*getBus());
  }
  s->temperature = (data[0] << 8) + data[1];
  s->temperature = ((175.72 * s->temperature) / 65536.0 ) - 45;

  s->humidity = (data[3] << 8) + data[4];
  s->humidity = ((100 * s->humidity) / 65536.0 )
}

#ifdef __cplusplus
}
#endif