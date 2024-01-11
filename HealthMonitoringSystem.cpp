#include "HealthMonitoringSystem.h"
#include <iostream>

using namespace std;

// Constructor implementation
HealthMonitoringSystem::HealthMonitoringSystem()
    : heartRate(0), bloodPressure(0), heartRateSet(false), bloodPressureSet(false), healthStatus(HEALTHY) {}

// Method to record heart rate and return corresponding signal
HealthMonitoringSystem::Signal HealthMonitoringSystem::recordHeartRate(int hr) {
    heartRate = hr;
    heartRateSet = true;
    if (hr > MAX_HEART_RATE) return DECREASE;
    else if (hr < MIN_HEART_RATE) return INCREASE;
    else return DO_NOTHING;
}

// Method to record blood pressure and return corresponding signal
HealthMonitoringSystem::Signal HealthMonitoringSystem::recordBloodPressure(int bp) {
    bloodPressure = bp;
    bloodPressureSet = true;
    if (bp > MAX_BLOOD_PRESSURE) return DECREASE;
    else if (bp < MIN_BLOOD_PRESSURE) return INCREASE;
    else return DO_NOTHING;
}

// Method to update the overall health status
void HealthMonitoringSystem::updateHealthStatus() {
    healthStatus = evaluateHealthStatus();
}

// Method to get the current heart rate
int HealthMonitoringSystem::getHeartRate() const {
    if (heartRateSet) return heartRate;
    else {
        cerr << "Heart rate not set\n";
        return -1;
    }
}

// Method to get the current blood pressure
int HealthMonitoringSystem::getBloodPressure() const {
    if (bloodPressureSet) return bloodPressure;
    else {
        cerr << "Blood pressure not set\n";
        return -1;
    }
}

// Method to get the current health status
HealthMonitoringSystem::HealthStatus HealthMonitoringSystem::getHealthStatus() const {
    return healthStatus;
}

// Private method to evaluate and return the health status
HealthMonitoringSystem::HealthStatus HealthMonitoringSystem::evaluateHealthStatus() const {
    if ((heartRateSet && (heartRate > MAX_HEART_RATE || heartRate < MIN_HEART_RATE)) ||
        (bloodPressureSet && (bloodPressure > MAX_BLOOD_PRESSURE || bloodPressure < MIN_BLOOD_PRESSURE))) {
        return CRITICAL;
    } else {
        return HEALTHY;
    }
}
