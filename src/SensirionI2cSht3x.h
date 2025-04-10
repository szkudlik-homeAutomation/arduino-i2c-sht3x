/*
 * THIS FILE IS AUTOMATICALLY GENERATED
 *
 * Generator:     sensirion-driver-generator 0.33.0
 * Product:       sht3x
 * Model-Version: 1.0.0
 */
/*
 * Copyright (c) 2023, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SENSIRIONI2CSHT3X_H
#define SENSIRIONI2CSHT3X_H

#include "../../sensiron_core/src/SensirionCore.h"
#include <Wire.h>

#define NO_ERROR 0
#define SHT30A_I2C_ADDR_44 0x44
#define SHT30A_I2C_ADDR_45 0x45
#define SHT30_I2C_ADDR_44 0x44
#define SHT30_I2C_ADDR_45 0x45
#define SHT31A_I2C_ADDR_44 0x44
#define SHT31A_I2C_ADDR_45 0x45
#define SHT31_I2C_ADDR_44 0x44
#define SHT31_I2C_ADDR_45 0x45
#define SHT33_I2C_ADDR_44 0x44
#define SHT33_I2C_ADDR_45 0x45
#define SHT35A_I2C_ADDR_44 0x44
#define SHT35A_I2C_ADDR_45 0x45
#define SHT35_I2C_ADDR_44 0x44
#define SHT35_I2C_ADDR_45 0x45

typedef enum {
    MEASURE_SINGLE_SHOT_HIGH_REPEATABILITY_CMD_ID = 0x2400,
    MEASURE_SINGLE_SHOT_HIGH_REPEATABILITY_CLOCK_STRETCHING_CMD_ID = 0x2c06,
    MEASURE_SINGLE_SHOT_MEDIUM_REPEATABILITY_CMD_ID = 0x240b,
    MEASURE_SINGLE_SHOT_MEDIUM_REPEATABILITY_CLOCK_STRETCHING_CMD_ID = 0x2c0d,
    MEASURE_SINGLE_SHOT_LOW_REPEATABILITY_CMD_ID = 0x2416,
    MEASURE_SINGLE_SHOT_LOW_REPEATABILITY_CLOCK_STRETCHING_CMD_ID = 0x2c10,
    START_MEASUREMENT_0_5_MPS_HIGH_REPEATABILITY_CMD_ID = 0x2032,
    START_MEASUREMENT_0_5_MPS_MEDIUM_REPEATABILITY_CMD_ID = 0x2024,
    START_MEASUREMENT_0_5_MPS_LOW_REPEATABILITY_CMD_ID = 0x202f,
    START_MEASUREMENT_1_MPS_HIGH_REPEATABILITY_CMD_ID = 0x2130,
    START_MEASUREMENT_1_MPS_MEDIUM_REPEATABILITY_CMD_ID = 0x2126,
    START_MEASUREMENT_1_MPS_LOW_REPEATABILITY_CMD_ID = 0x212d,
    START_MEASUREMENT_2_MPS_HIGH_REPEATABILITY_CMD_ID = 0x2236,
    START_MEASUREMENT_2_MPS_MEDIUM_REPEATABILITY_CMD_ID = 0x2220,
    START_MEASUREMENT_2_MPS_LOW_REPEATABILITY_CMD_ID = 0x222b,
    START_MEASUREMENT_4_MPS_HIGH_REPEATABILITY_CMD_ID = 0x2334,
    START_MEASUREMENT_4_MPS_MEDIUM_REPEATABILITY_CMD_ID = 0x2322,
    START_MEASUREMENT_4_MPS_LOW_REPEATABILITY_CMD_ID = 0x2329,
    START_MEASUREMENT_10_MPS_HIGH_REPEATABILITY_CMD_ID = 0x2737,
    START_MEASUREMENT_10_MPS_MEDIUM_REPEATABILITY_CMD_ID = 0x2721,
    START_MEASUREMENT_10_MPS_LOW_REPEATABILITY_CMD_ID = 0x273a,
    START_ART_MEASUREMENT_CMD_ID = 0x2b32,
    READ_MEASUREMENT_CMD_ID = 0xe000,
    STOP_MEASUREMENT_CMD_ID = 0x3093,
    ENABLE_HEATER_CMD_ID = 0x306d,
    DISABLE_HEATER_CMD_ID = 0x3066,
    READ_STATUS_REGISTER_CMD_ID = 0xf32d,
    CLEAR_STATUS_REGISTER_CMD_ID = 0x3041,
    SOFT_RESET_CMD_ID = 0x30a2,
} CmdId;

typedef enum {
    REPEATABILITY_LOW = 0,
    REPEATABILITY_MEDIUM = 1,
    REPEATABILITY_HIGH = 2,
} Repeatability;

typedef enum {
    MPS_EVERY_TWO_SECONDS = 0,
    MPS_ONE_PER_SECOND = 1,
    MPS_TWO_PER_SECOND = 2,
    MPS_FOUR_PER_SECOND = 4,
    MPS_TEN_PER_SECOND = 10,
} Mps;

class SensirionI2cSht3x {
  public:
    SensirionI2cSht3x();
    /**
     * @brief Initializes the SHT3x class.
     *
     * @param i2cBus Arduino stream object to be used for communication.
     */
    void begin(TwoWire& i2cBus, uint8_t i2cAddress);

    /**
     * @brief Single shot measurement with the specified properties
     *
     * @param[in] measurementRepeatability The repeatability of the periodic
     * measurement
     * @param[in] isClockStretching Toggle clock stretching
     * @param[out] aTemperature Converted from ticks to degrees celsius by -45 +
     * (175 * value / 65535)
     * @param[out] aHumidity Converted from ticks to relative humidity by 100 *
     * value / 65535
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t measureSingleShot(Repeatability measurementRepeatability,
                              bool isClockStretching, float& aTemperature,
                              float& aHumidity);

    /**
     * @brief startPeriodicMeasurement
     *
     * Start the periodic measurement measurement mode.
     *
     * This is a convenience method that selects the correct measurement command
     * based on the provided arguments.
     *
     * @param[in] measurementRepeatability The repeatability of the periodic
     * measurement
     * @param[in] messagesPerSecond The messages per second of the periodic
     * measurement
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t startPeriodicMeasurement(Repeatability measurementRepeatability,
                                     Mps messagesPerSecond);

    /**
     * @brief blockingReadMeasurement
     *
     * This is a convenience method that combines polling the data ready flag
     * and reading out the data. As the minimal measurement interval is 2s and
     * we sleep for 100ms we iterate at most 200 times. Note that this is
     * blocking the system for a considerable amount of time!
     *
     * @param[out] aTemperature Converted from ticks to degrees celsius by -45 +
     * (175 * value / 65535)
     * @param[out] aHumidity Converted from ticks to relative humidity by 100 *
     * value / 65535
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t blockingReadMeasurement(float& aTemperature, float& aHumidity);

    /**
     * @brief Read the contents of the status register
     *
     * @param[out] aStatusRegister
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t readStatusRegister(uint16_t& aStatusRegister);

    /**
     * @brief measureSingleShotHighRepeatability
     *
     * Single shot measurement with high repeatability
     *
     * @param[out] temperatureTicks Temperature ticks. Convert to degrees
     * celsius by -45 + 175 * value / 65535
     * @param[out] humidityTicks Humidity ticks. Convert to relative humidity by
     * 100
     * * value / 65535
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t measureSingleShotHighRepeatability(uint16_t& temperatureTicks,
                                               uint16_t& humidityTicks);

    /**
     * @brief measureSingleShotHighRepeatabilityClockStretching
     *
     * Single shot measurement with high repeatability and clock stretching
     * enabled
     *
     * @param[out] temperatureTicks Temperature ticks. Convert to degrees
     * celsius by -45 + 175 * value / 65535
     * @param[out] humidityTicks Humidity ticks. Convert to relative humidity by
     * 100
     * * value / 65535
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t measureSingleShotHighRepeatabilityClockStretching(
        uint16_t& temperatureTicks, uint16_t& humidityTicks);

    /**
     * @brief measureSingleShotMediumRepeatability
     *
     * Single shot measurement with medium repeatability
     *
     * @param[out] temperatureTicks Temperature ticks. Convert to degrees
     * celsius by -45 + 175 * value / 65535
     * @param[out] humidityTicks Humidity ticks. Convert to relative humidity by
     * 100
     * * value / 65535
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t measureSingleShotMediumRepeatability(uint16_t& temperatureTicks,
                                                 uint16_t& humidityTicks);

    /**
     * @brief measureSingleShotMediumRepeatabilityClockStretching
     *
     * Single shot measurement with medium repeatability and clock stretching
     * enabled
     *
     * @param[out] temperatureTicks Temperature ticks. Convert to degrees
     * celsius by -45 + 175 * value / 65535
     * @param[out] humidityTicks Humidity ticks. Convert to relative humidity by
     * 100
     * * value / 65535
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t measureSingleShotMediumRepeatabilityClockStretching(
        uint16_t& temperatureTicks, uint16_t& humidityTicks);

    /**
     * @brief measureSingleShotLowRepeatability
     *
     * Single shot measurement with low repeatability
     *
     * @param[out] temperatureTicks Temperature ticks. Convert to degrees
     * celsius by -45 + 175 * value / 65535
     * @param[out] humidityTicks Humidity ticks. Convert to relative humidity by
     * 100
     * * value / 65535
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t measureSingleShotLowRepeatability(uint16_t& temperatureTicks,
                                              uint16_t& humidityTicks);

    /**
     * @brief measureSingleShotLowRepeatabilityClockStretching
     *
     * Single shot measurement with low repeatability and clock stretching
     * enabled
     *
     * @param[out] temperatureTicks Temperature ticks. Convert to degrees
     * celsius by -45 + 175 * value / 65535
     * @param[out] humidityTicks Humidity ticks. Convert to relative humidity by
     * 100
     * * value / 65535
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t
    measureSingleShotLowRepeatabilityClockStretching(uint16_t& temperatureTicks,
                                                     uint16_t& humidityTicks);

    /**
     * @brief startMeasurement05MpsHighRepeatability
     *
     * Start periodic measurement mode with 0.5 mps and high repeatability.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t startMeasurement05MpsHighRepeatability();

    /**
     * @brief startMeasurement05MpsMediumRepeatability
     *
     * Start periodic measurement mode with 0.5 mps and medium repeatability.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t startMeasurement05MpsMediumRepeatability();

    /**
     * @brief startMeasurement05MpsLowRepeatability
     *
     * Start periodic measurement mode with 0.5 mps and low repeatability.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t startMeasurement05MpsLowRepeatability();

    /**
     * @brief startMeasurement1MpsHighRepeatability
     *
     * Start periodic measurement mode with 1 mps and high repeatability.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t startMeasurement1MpsHighRepeatability();

    /**
     * @brief startMeasurement1MpsMediumRepeatability
     *
     * Start periodic measurement mode with 1 mps and medium repeatability.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t startMeasurement1MpsMediumRepeatability();

    /**
     * @brief startMeasurement1MpsLowRepeatability
     *
     * Start periodic measurement mode with 1 mps and low repeatability.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t startMeasurement1MpsLowRepeatability();

    /**
     * @brief startMeasurement2MpsHighRepeatability
     *
     * Start periodic measurement mode with 2 mps and high repeatability.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t startMeasurement2MpsHighRepeatability();

    /**
     * @brief startMeasurement2MpsMediumRepeatability
     *
     * Start periodic measurement mode with 2 mps and medium repeatability.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t startMeasurement2MpsMediumRepeatability();

    /**
     * @brief startMeasurement2MpsLowRepeatability
     *
     * Start periodic measurement mode with 2 mps and low repeatability.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t startMeasurement2MpsLowRepeatability();

    /**
     * @brief startMeasurement4MpsHighRepeatability
     *
     * Start periodic measurement mode with 4 mps and high repeatability.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t startMeasurement4MpsHighRepeatability();

    /**
     * @brief startMeasurement4MpsMediumRepeatability
     *
     * Start periodic measurement mode with 4 mps and medium repeatability.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t startMeasurement4MpsMediumRepeatability();

    /**
     * @brief startMeasurement4MpsLowRepeatability
     *
     * Start periodic measurement mode with 4 mps and low repeatability.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t startMeasurement4MpsLowRepeatability();

    /**
     * @brief startMeasurement10MpsHighRepeatability
     *
     * Start periodic measurement mode with 10 mps and high repeatability.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t startMeasurement10MpsHighRepeatability();

    /**
     * @brief startMeasurement10MpsMediumRepeatability
     *
     * Start periodic measurement mode with 10 mps and medium repeatability.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t startMeasurement10MpsMediumRepeatability();

    /**
     * @brief startMeasurement10MpsLowRepeatability
     *
     * Start periodic measurement mode with 10 mps and low repeatability.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t startMeasurement10MpsLowRepeatability();

    /**
     * @brief startArtMeasurement
     *
     * Start ART (accelerated response time) measurement
     *
     * @note After issuing the ART command the sensor will start acquiring data
     * with a frequency of 4Hz.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t startArtMeasurement();

    /**
     * @brief readMeasurement
     *
     * Read out data after a "start measurement" or "start art measurement"
     * command has been issued.
     *
     * @param[out] temperatureTicks Temperature ticks. Convert to degrees
     * celsius by -45 + 175 * value / 65535
     * @param[out] humidityTicks Humidity ticks. Convert to relative humidity by
     * 100
     * * value / 65535
     *
     * @note After the read out command fetch data has been issued, the data
     * memory is cleared, i.e. no measurement data is present.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t readMeasurement(uint16_t& temperatureTicks,
                            uint16_t& humidityTicks);

    /**
     * @brief stopMeasurement
     *
     * Stop the periodic measurement mode.
     *
     * @note Upon reception of this command the sensor will abort the ongoing
     * measurement and enter the single shot mode.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t stopMeasurement();

    /**
     * @brief enableHeater
     *
     * Enable the heater
     *
     * @note The SHT3x is equipped with an internal heater, which is meant for
     * plausibility checking only. The temperature increase achieved by the
     * heater depends on various parameters and lies in the range of a few
     * degrees centigrade.
     *
     * After a reset the heater is disabled (default condition).
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t enableHeater();

    /**
     * @brief disableHeater
     *
     * Disable the heater
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t disableHeater();

    /**
     * @brief llreadStatusRegister
     *
     * Read out the status register
     *
     * @param[out] statusRegister The contents of the status register
     *
     * @note The status register contains information on the operational status
     * of the heater, the alert mode and on the execution status of the last
     * command and the last write sequence.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t llreadStatusRegister(uint16_t& statusRegister);

    /**
     * @brief clearStatusRegister
     *
     * Clear (set to zero) all flags (Bit 4) in the status register.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t clearStatusRegister();

    /**
     * @brief softReset
     *
     * Perform a soft reset.
     *
     * @note A system reset of the SHT3x can be achieved in multiple ways: -
     * Soft reset: use this command - I2C general call: all devices on the I2C
     * bus are reset by sending the command 0x06 to the I2C address 0x00 - Reset
     * pin: send a pulse to the dedicated nReset pin. The nReset pin has to be
     * pulled low for a minimum of 1 µs to generate a reset of the sensor. -
     * Hard reset: Power down (incl. pulling SDA, SCL and ADDR low)
     *
     * During the reset procedure the sensor will not process commands.
     *
     * @return error_code 0 on success, an error code otherwise.
     */
    int16_t softReset();

  private:
    TwoWire* _i2cBus = nullptr;
    uint8_t _i2cAddress = 0;

    /**
     * @brief signalTemperature
     *
     * @param[in] temperatureTicks
     *
     * @return Converted from ticks to degrees celsius by -45 + (175 * value /
     * 65535)
     */
    float signalTemperature(uint16_t temperatureTicks);

    /**
     * @brief signalHumidity
     *
     * @param[in] humidityTicks
     *
     * @return Converted from ticks to relative humidity by 100 * value / 65535
     */
    float signalHumidity(uint16_t humidityTicks);
};

#endif  // SENSIRIONI2CSHT3X_H
