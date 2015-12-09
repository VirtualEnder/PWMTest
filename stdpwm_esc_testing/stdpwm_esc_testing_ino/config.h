
// Configuration options

// Rates
#define UARTBAUD 921600    // UART Baud rate (DO NOT set to less than 115200) 
#define SENSORRATE 500     // Refresh rate in HZ of load cell and analog read timer.
#define LOOPDELAY 4000     // Looptime for main test loop (Doesn't effect braking test)  Set to false to use maximum stable values allowed by UARTBAUD

// Sensor and Motor configuration
#define MAGSENS true       // Using Magnetic RPM sensor?
#define OPTISENS false     // Using Magnetic RPM sensor?
#define POLES 14           // Number of magnetic poles in test motor.

// Test Range
#define MINTHROTTLE 1030   // Low end of ESC calibrated range
#define MAXTHROTTLE 2000   // High end of ESC calibrated range
#define MINCOMMAND  980    // Value sent to ESC when test isn't running.
#define IDLEPWM     1100   // PWM output used for idling

// Analog Configuation
#define OVERSAMPLING 64    // Analog oversampling multiplier
#define VSCALE 26          // Scale factor for Voltage divider.
#define CSCALE 100         // Scale factor for current sensor.
#define LSCALE -395        // Scale factor for load cell amplifier.

// Brake Test Configuration       NOTE: Braking test always runs as fast as UARTBAUD will allow
#define BRAKEMAXRPM 30000  // Maximum RPM limit used in braking test.
#define BRAKEMINRPM 8000   // Maximum RPM limit used in braking test.
#define BRAKERPMSAMPLE 250 // Sample size of RPM averaging for target RPM detection during brake test.
