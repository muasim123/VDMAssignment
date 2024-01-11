#include <iostream>
#include <cassert>
#include "HealthMonitoringSystem.h"

using namespace std;

// Test class for HealthMonitoringSystem
class HealthMonitoringSystemTest {
public:
    // Test method for recordHeartRate function
    static void testRecordHeartRate() {
        HealthMonitoringSystem monitor;
        assert(monitor.recordHeartRate(50) == HealthMonitoringSystem::INCREASE);
        cout << "Heart rate 50: Expected INCREASE, Got " << monitor.recordHeartRate(50) << endl;

        assert(monitor.recordHeartRate(100) == HealthMonitoringSystem::DO_NOTHING);
        cout << "Heart rate 100: Expected DO_NOTHING, Got " << monitor.recordHeartRate(100) << endl;

        assert(monitor.recordHeartRate(130) == HealthMonitoringSystem::DECREASE);
        cout << "Heart rate 130: Expected DECREASE, Got " << monitor.recordHeartRate(130) << endl;

        cout << "testRecordHeartRate passed." << endl;
    }

    // Test method for recordBloodPressure function
    static void testRecordBloodPressure() {
        HealthMonitoringSystem monitor;
        assert(monitor.recordBloodPressure(80) == HealthMonitoringSystem::INCREASE);
        cout << "Blood pressure 80: Expected INCREASE, Got " << monitor.recordBloodPressure(80) << endl;

        assert(monitor.recordBloodPressure(100) == HealthMonitoringSystem::DO_NOTHING);
        cout << "Blood pressure 100: Expected DO_NOTHING, Got " << monitor.recordBloodPressure(100) << endl;

        assert(monitor.recordBloodPressure(150) == HealthMonitoringSystem::DECREASE);
        cout << "Blood pressure 150: Expected DECREASE, Got " << monitor.recordBloodPressure(150) << endl;

        cout << "testRecordBloodPressure passed." << endl;
    }

    // Test method for updateHealthStatus function
    static void testUpdateHealthStatus() {
        HealthMonitoringSystem monitor;
        monitor.recordHeartRate(130); // should set health status to CRITICAL
        monitor.recordBloodPressure(150); // should set health status to CRITICAL
        monitor.updateHealthStatus();
        assert(monitor.getHealthStatus() == HealthMonitoringSystem::CRITICAL);
        cout << "Updated Health Status: Expected CRITICAL, Got " << monitor.getHealthStatus() << endl;

        cout << "testUpdateHealthStatus passed." << endl;
    }

    // Method to run all tests
    static void testAll() {
        testRecordHeartRate();
        testRecordBloodPressure();
        testUpdateHealthStatus();
        cout << "All tests passed." << endl;
    }
};

// Main function to execute tests
int main() {
    HealthMonitoringSystemTest::testAll();
    return 0;
}
