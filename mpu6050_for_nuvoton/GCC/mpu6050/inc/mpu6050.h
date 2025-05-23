/*
 * mpu6050.h
 *
 *  Created on: Apr 12, 2025
 *      Author: ibrahim
 */

#ifndef MPU6050_INC_MPU6050_H_
#define MPU6050_INC_MPU6050_H_


#include "NuMicro.h"

// register addr
#define RAD_TO_DEG 57.295779513082320876798154814105
#define WHO_AM_I_REG 0x75
#define PWR_MGMT_1_REG 0x6B
#define SMPLRT_DIV_REG 0x19
#define ACCEL_CONFIG_REG 0x1C
#define ACCEL_XOUT_H_REG 0x3B
#define TEMP_OUT_H_REG 0x41
#define GYRO_CONFIG_REG 0x1B
#define GYRO_XOUT_H_REG 0x43

// mpu6050 ic addr
#define MPU6050_ADDR 0x68

// MPU6050 structure
typedef struct
{
    int16_t Accel_X_RAW;
    int16_t Accel_Y_RAW;
    int16_t Accel_Z_RAW;
    double Ax;
    double Ay;
    double Az;

    int16_t Gyro_X_RAW;
    int16_t Gyro_Y_RAW;
    int16_t Gyro_Z_RAW;
    double Gx;
    double Gy;
    double Gz;

    float Temperature;

} MPU6050_t;



// function prototypes
uint8_t MPU6050_Init(I2C_T *I2Cx);
void MPU6050_Read_Accel(I2C_T *I2Cx, MPU6050_t *DataStruct);
void MPU6050_Read_Gyro(I2C_T *I2Cx, MPU6050_t *DataStruct);
void MPU6050_Read_Temp(I2C_T *I2Cx, MPU6050_t *DataStruct);
void MPU6050_Read_All(I2C_T *I2Cx, MPU6050_t *DataStruct);

#endif /* MPU6050_INC_MPU6050_H_ */
