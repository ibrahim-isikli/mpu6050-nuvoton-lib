/*
 * mpu6050.c
 *
 *  Created on: Apr 12, 2025
 *      Author: ibrahim
 */

#include "mpu6050.h"


const double Accel_Z_corrector = 14418.0;

uint8_t MPU6050_Init(I2C_T *I2Cx)
{
	uint8_t check_addr,data,check = 0;

	check_addr = I2C_ReadByteOneReg(I2Cx, MPU6050_ADDR, WHO_AM_I_REG);				// check device address from WHO_AM_I register

    if(check_addr == MPU6050_ADDR)
    {
        data = 0;
        check |= I2C_WriteByteOneReg(I2Cx, MPU6050_ADDR, PWR_MGMT_1_REG, data); 	// power management register 0x6B we should write all 0's to wake the sensor up

        data = 0x07;
        check |= I2C_WriteByteOneReg(I2Cx, MPU6050_ADDR, SMPLRT_DIV_REG, data); 	// set data rate of 1KHz by writing SMPLRT_DIV register

        data = 0x00;
        check |= I2C_WriteByteOneReg(I2Cx, MPU6050_ADDR, ACCEL_CONFIG_REG, data); 	// set accelerometer config in ACCEL_CONFIG register

        data = 0x00;
        check |= I2C_WriteByteOneReg(I2Cx, MPU6050_ADDR, GYRO_CONFIG_REG, data); 	// set gyro config in GYRO_CONFIG register

        return (check == 0) ? 0 : 1;

    }
    return 1;
}

void MPU6050_Read_Accel(I2C_T *I2Cx, MPU6050_t *DataStruct)
{
    uint8_t receive_data[6];

    I2C_ReadMultiBytesOneReg(I2Cx, MPU6050_ADDR, ACCEL_XOUT_H_REG, receive_data, 6); // read 6 bytes of data starting from ACCEL_XOUT_H register

    DataStruct->Accel_X_RAW = (int16_t)(receive_data[0] << 8 | receive_data[1]);
    DataStruct->Accel_Y_RAW = (int16_t)(receive_data[2] << 8 | receive_data[3]);
    DataStruct->Accel_Z_RAW = (int16_t)(receive_data[4] << 8 | receive_data[5]);

    DataStruct->Ax = DataStruct->Accel_X_RAW / 16384.0;
    DataStruct->Ay = DataStruct->Accel_Y_RAW / 16384.0;
    DataStruct->Az = DataStruct->Accel_Z_RAW / Accel_Z_corrector;
}

void MPU6050_Read_Gyro(I2C_T *I2Cx, MPU6050_t *DataStruct)
{
	uint8_t receive_data[6];

    // Read 6 BYTES of data starting from GYRO_XOUT_H register
    I2C_ReadMultiBytesOneReg(I2Cx, MPU6050_ADDR, GYRO_XOUT_H_REG, receive_data, 6);

    DataStruct->Gyro_X_RAW = (int16_t)(receive_data[0] << 8 | receive_data[1]);
    DataStruct->Gyro_Y_RAW = (int16_t)(receive_data[2] << 8 | receive_data[3]);
    DataStruct->Gyro_Z_RAW = (int16_t)(receive_data[4] << 8 | receive_data[5]);

    DataStruct->Gx = DataStruct->Gyro_X_RAW / 131.0;
    DataStruct->Gy = DataStruct->Gyro_Y_RAW / 131.0;
    DataStruct->Gz = DataStruct->Gyro_Z_RAW / 131.0;
}

void MPU6050_Read_Temp(I2C_T *I2Cx, MPU6050_t *DataStruct)
{
    uint8_t receive_data[2];
    int16_t temp;

    I2C_ReadMultiBytesOneReg(I2Cx, MPU6050_ADDR, TEMP_OUT_H_REG, receive_data, 2);	// read 2 bytes of data starting from TEMP_OUT_H_REG register

    temp = (int16_t)(receive_data[0] << 8 | receive_data[1]);
    DataStruct->Temperature = (float)((int16_t)temp / (float)340.0 + (float)36.53);
}

void MPU6050_Read_All(I2C_T *I2Cx, MPU6050_t *DataStruct)
{
    uint8_t receive_data[14];
    int16_t temp;

    I2C_ReadMultiBytesOneReg(I2Cx, MPU6050_ADDR, ACCEL_XOUT_H_REG, receive_data, 14); // read 2 bytes of data starting from TEMP_OUT_H_REG register

    DataStruct->Accel_X_RAW = (int16_t)(receive_data[0] << 8 | receive_data[1]);
    DataStruct->Accel_Y_RAW = (int16_t)(receive_data[2] << 8 | receive_data[3]);
    DataStruct->Accel_Z_RAW = (int16_t)(receive_data[4] << 8 | receive_data[5]);
    temp = (int16_t)(receive_data[6] << 8 | receive_data[7]);
    DataStruct->Gyro_X_RAW = (int16_t)(receive_data[8] << 8 | receive_data[9]);
    DataStruct->Gyro_Y_RAW = (int16_t)(receive_data[10] << 8 | receive_data[11]);
    DataStruct->Gyro_Z_RAW = (int16_t)(receive_data[12] << 8 | receive_data[13]);

    DataStruct->Ax = DataStruct->Accel_X_RAW / 16384.0;
    DataStruct->Ay = DataStruct->Accel_Y_RAW / 16384.0;
    DataStruct->Az = DataStruct->Accel_Z_RAW / Accel_Z_corrector;
    DataStruct->Temperature = (float)((int16_t)temp / (float)340.0 + (float)36.53);
    DataStruct->Gx = DataStruct->Gyro_X_RAW / 131.0;
    DataStruct->Gy = DataStruct->Gyro_Y_RAW / 131.0;
    DataStruct->Gz = DataStruct->Gyro_Z_RAW / 131.0;

}
