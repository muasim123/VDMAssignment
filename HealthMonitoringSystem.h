#ifndef HEALTH_MONITORING_SYSTEM_H
#define HEALTH_MONITORING_SYSTEM_H

using namespace std;

// HealthMonitoringSystem class declaration
class HealthMonitoringSystem {
public:
    // Enumerations for signal and health status
    enum Signal { INCREASE, DECREASE, DO_NOTHING };
    enum HealthStatus { HEALTHY, WARNING, CRITICAL };

    // Constants for heart rate and blood pressure thresholds
    static const int MAX_HEART_RATE = 120;
    static const int MIN_HEART_RATE = 60;
    static const int MAX_BLOOD_PRESSURE = 140;
    static const int MIN_BLOOD_PRESSURE = 90;

    // Constructor declaration
    HealthMonitoringSystem();

    // Method declarations for recording and getting health data
    Signal recordHeartRate(int hr);
    Signal recordBloodPressure(int bp);
    void updateHealthStatus();
    int getHeartRate() const;
    int getBloodPressure() const;
    HealthStatus getHealthStatus() const;

private:
    // Private member variables for storing health data
    int heartRate;
    int bloodPressure;
    bool heartRateSet;
    bool bloodPressureSet;
    HealthStatus healthStatus;

    // Private method for evaluating health status
    HealthStatus evaluateHealthStatus() const;
};

#endif // HEALTH_MONITORING_SYSTEM_H
