# ME 331 Project 5 – Temperature-Controlled Cooling Fan

**Author:** Abbas Hussain  
**Course:** ME 331 – Mechatronics  
**Semester:** Spring 2025

This project uses a temperature sensor to control a cooling fan and RGB LED based on thermal conditions. The system provides visual and mechanical feedback to manage heat by spinning a fan and changing LED colors at specified temperature thresholds.

---

## 🧰 Components Used

- Arduino Uno  
- DC Motor with Propeller  
- Temperature Sensor (e.g., DHT11 or TMP36)  
- RGB LED or discrete red, yellow, and blue LEDs  
- NPN Transistor (e.g., 2N2222 or TIP120)  
- Flyback Diode  
- Resistors, Breadboard, Jumper Wires  
- External Power Source (if needed for motor)

---

## 🌡️ Temperature Thresholds

- **Below 85°F:**  
  - LED: **Blue**  
  - Motor: **OFF**

- **85°F – 88°F:**  
  - LED: **Yellow**  
  - Motor: **50% Speed**

- **Above 88°F:**  
  - LED: **Red**  
  - Motor: **Full Speed**

---

## 🧠 Project Logic

1. The temperature sensor reads the ambient or object temperature in real time.
2. Based on the temperature:
   - The RGB LED displays color indicating heat level.
   - The motor activates at proportional speed to simulate a fan cooling the object.
3. The Arduino PWM output adjusts motor speed accordingly:
   - `analogWrite()` used for speed modulation.
   - `digitalWrite()` or `analogWrite()` used for RGB LED control.

---

## 🎯 How It Works

- At room temperature, the blue LED turns on and the fan is idle.
- As the temperature rises past 85°F, the system enters a warning state:
  - The yellow LED turns on.
  - Fan spins at 50% speed.
- When the temperature exceeds 88°F:
  - The red LED turns on.
  - Fan spins at full speed to cool the object.
- The system continuously monitors and updates based on real-time readings.

---

## 🧪 Demonstration Conditions

To test the system:
- A mug of hot water was held near the temperature sensor.
- Sensor took 1–2 minutes to respond due to thermal latency.
- Fan and LEDs responded appropriately at defined thresholds.

---

## 📁 Files Included

- `Project5_AbbasHussain.ino` – Arduino sketch
- `cooling_fan_demo.mp4` – Video demonstration of all three states
- `README.md` – Project documentation

---

## 🚀 Future Enhancements

- Add an LCD screen to display real-time temperature.
- Use a more responsive sensor like the DHT22 for better accuracy.
- Add hysteresis to prevent rapid toggling between states.

---

> 🔄 *This project demonstrates a practical Arduino-based control system for heat mitigation using sensor input, real-time logic, and multi-output response.*
