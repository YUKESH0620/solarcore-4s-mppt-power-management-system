# LED and Buzzer Behavior Specification

## Overview

The SolarCore-4S MPPT Power Management System includes a visual and audible notification subsystem implemented using:

- 5 Battery Level LEDs
- 1 BMS Fault LED
- 1 Charging Status LED
- 1 Discharging Status LED
- 1 Power Status LED
- 1 Firmware-Controlled Buzzer

The behavior described in this document represents the recommended firmware implementation for Hardware Revision A.

---

# Indicator Summary

| Indicator | Purpose |
|------------|------------|
| BAT_LEVEL1 | Battery Capacity Display |
| BAT_LEVEL2 | Battery Capacity Display |
| BAT_LEVEL3 | Battery Capacity Display |
| BAT_LEVEL4 | Battery Capacity Display |
| BAT_LEVEL5 | Battery Capacity Display |
| BMS Fault LED | BMS Alert Indication |
| Charging LED | Charging Activity |
| Discharging LED | Load Activity |
| Power LED | System Power Presence |
| Buzzer | Audible Notifications |

---

# STM32 Pin Assignment

## Battery Indicators

| LED | STM32 Pin |
|------|------|
| BAT_LEVEL1 | PB0 |
| BAT_LEVEL2 | PB1 |
| BAT_LEVEL3 | PB2 |
| BAT_LEVEL4 | PB3 |
| BAT_LEVEL5 | PB4 |

---

## Buzzer

| Signal | STM32 Pin |
|---------|---------|
| BUZ_CTRL | PB7 |

---

# Battery Capacity Display

## Normal Operating Mode

The battery level LEDs indicate the estimated state of charge (SOC) of the connected 4S LiFePO4 battery pack.

### Recommended Mapping

| Battery Percentage | LED Status |
|--------------------|------------|
| 0% – 20% | LED1 ON |
| 20% – 40% | LED1 + LED2 ON |
| 40% – 60% | LED1 + LED2 + LED3 ON |
| 60% – 80% | LED1 + LED2 + LED3 + LED4 ON |
| 80% – 100% | All LEDs ON |

---

# Startup Sequence

When the system powers up:

### Recommended Animation

Step 1

```text
LED1
```

Step 2

```text
LED1 LED2
```

Step 3

```text
LED1 LED2 LED3
```

Step 4

```text
LED1 LED2 LED3 LED4
```

Step 5

```text
LED1 LED2 LED3 LED4 LED5
```

Then return to normal battery display mode.

Purpose:

- Verify LEDs are functional
- Provide visual startup confirmation
- Improve user experience

---

# Charging Indication

## Charging Active

Recommended Pattern:

```text
Running LED Animation
```

Example:

```text
LED1
LED2
LED3
LED4
LED5
Repeat
```

Purpose:

Clearly indicate charging activity.

---

## Charging Complete

Recommended Pattern:

```text
All LEDs ON
```

for

```text
3 seconds
```

followed by normal display mode.

---

## Trickle / Float State

Recommended Pattern:

```text
All LEDs Slow Blink
```

Period:

```text
1 second ON
1 second OFF
```

---

# Low Battery Warning

## Warning Level

Battery below:

```text
20%
```

Recommended Pattern:

```text
LED1 Slow Blink
```

Purpose:

Warn user before critical discharge.

---

# Critical Battery State

## Critical Threshold

Battery below:

```text
10%
```

Recommended Pattern:

```text
LED1 Fast Blink
```

Purpose:

Immediate recharge required.

---

# Fault Display Modes

## BMS Alert

Condition:

```text
BMS_ALERT asserted
```

Possible Causes:

- Cell Overvoltage
- Cell Undervoltage
- Overcurrent
- Short Circuit

Recommended Display:

```text
All Battery LEDs Blink Simultaneously
```

Rate:

```text
4 Hz
```

---

## Communication Fault

Condition:

Loss of communication with BQ76920.

Recommended Display:

```text
LED1 + LED3 + LED5 Blink
```

Pattern:

```text
Alternating Pattern
```

Purpose:

Differentiate from battery faults.

---

## Sensor Fault

Condition:

ADC readings invalid.

Recommended Display:

```text
LED2 + LED4 Blink
```

Purpose:

Indicate measurement subsystem issue.

---

# Power LED Behavior

## System Active

Power LED:

```text
Solid ON
```

Meaning:

System operational.

---

## System Shutdown

Power LED:

```text
OFF
```

Meaning:

No system power.

---

# Charging LED Behavior

## Charging Enabled

Charging LED:

```text
Solid ON
```

Meaning:

Battery charging path active.

---

## Charging Disabled

Charging LED:

```text
OFF
```

Meaning:

Charge path disabled.

---

## Charging Fault

Charging LED:

```text
Fast Blink
```

Meaning:

Charging inhibited due to protection event.

---

# Discharging LED Behavior

## Load Active

Discharging LED:

```text
Solid ON
```

Meaning:

Battery supplying load current.

---

## Load Disabled

Discharging LED:

```text
OFF
```

Meaning:

Discharge path disabled.

---

# Audible Notification System

## Startup

Pattern:

```text
Single Short Beep
```

Duration:

```text
100 ms
```

Meaning:

System boot successful.

---

## Charging Started

Pattern:

```text
Double Beep
```

Meaning:

Charging operation detected.

---

## Charging Complete

Pattern:

```text
Triple Beep
```

Meaning:

Battery fully charged.

---

## Low Battery

Pattern:

```text
Short Beep Every 10 Seconds
```

Meaning:

Battery nearing depletion.

---

## Critical Battery

Pattern:

```text
Short Beep Every 2 Seconds
```

Meaning:

Recharge immediately.

---

## BMS Fault

Pattern:

```text
Long Continuous Tone
```

Duration:
```text
2 Seconds
```

Meaning:

Battery protection event.

---

## Communication Fault

Pattern:

```text
Three Short Pulses
```

Meaning:

BMS communication lost.

---

## Sensor Fault

Pattern:

```text
Two Long Pulses
```

Meaning:

Measurement subsystem error.

---

# Future OLED Integration

When an OLED display is connected to the I²C header, the LED indications may be supplemented with textual status information.

Possible OLED Messages:

```text
Charging
Charge Complete
Battery Low
Battery Critical
BMS Fault
Sensor Fault
System Ready
Output Enabled
```

---

# Future Firmware Expansion

Because all indicators are GPIO controlled through the STM32F103C8T6, future firmware revisions may implement:
- User-selectable alert profiles
- Silent mode
- Diagnostic mode
- Morse-code fault indications
- Configurable buzzer frequencies
- OLED-assisted status display
- Mobile app notifications through ESP32

---

# Revision Information

Document Version: 1.0
Applicable Hardware Revision: Rev A

Board:
SolarCore-4S MPPT Power Management System

Author:
Yukesh S