# Balancing a Central Heating System

Balancing a central heating system involves adjusting the flow of water through each radiator to ensure that heat is distributed evenly throughout the property. An unbalanced system might cause some radiators to heat up quickly and become overly warm while others remain cold or take much longer to heat. Balancing improves efficiency, reduces energy waste, and ensures consistent comfort across all rooms.

---

## Why is Balancing Necessary?

- **Uneven Heat Distribution:** Water naturally takes the path of least resistance, which means radiators closer to the boiler or pump might receive more hot water, while those further away get less.
- **Efficiency:** Balancing ensures the boiler doesn't work harder than necessary, which can reduce energy costs.
- **Comfort:** It eliminates cold spots and creates a consistent temperature in the home.

---

## Steps to Balance a Central Heating System

### 1. Turn Off the Heating System
Start by turning off the heating and letting the radiators cool completely. This ensures accurate adjustments.

### 2. Bleed the Radiators
Bleed all radiators to remove trapped air, which can interfere with water flow.

### 3. Set All Radiator Valves to Open
Fully open the lockshield valve (usually located on one side of the radiator) and the thermostatic or manual valve (on the opposite side) for all radiators.

### 4. Turn the Heating Back On
Turn the heating back on and let the system reach its normal operating temperature. Check that all radiators are heating up.

### 5. Measure Temperature Differences
- Use a digital thermometer or infrared thermometer to measure the temperature of the pipe entering and leaving each radiator.
- The goal is to achieve a consistent temperature drop (typically 10-12°C) between the inlet and outlet pipes.

### 6. Adjust the Lockshield Valve
- Starting with the radiator closest to the boiler:
  - Close the lockshield valve fully, then reopen it slightly.
  - Adjust the valve incrementally, allowing the temperature to stabilize before rechecking.
- Move sequentially through the system, making similar adjustments for each radiator. Radiators further from the boiler may require the valve to be more open to allow sufficient flow.

### 7. Recheck and Fine-Tune
Once all radiators are adjusted, recheck the temperature drop across each radiator to ensure consistency. Fine-tune the lockshield valves as necessary.

### 8. Test the System
Allow the system to run for an extended period and observe the heat distribution. Make further adjustments if needed.

---

### Tools Required

- A radiator bleed key.
- A digital or infrared thermometer.
- An adjustable wrench (for lockshield valves).
- Patience, as the process can be time-consuming.

---

Balancing is a precise process but pays off in terms of comfort and energy efficiency. If the task feels too complex or time-consuming, a professional heating engineer can perform it effectively.

---

# The Problem

Currently, this is a hugely manual process, requiring a thermometer to check one radiator at a time and then adjust it to increase or decrease the flow through it. This process can be made more efficient and repeatable with technology!

---

## Objectives

1. Identify and select an optimal technology stack, such as ESP32, espNOW, MQTT, Firebase, and Flutter, to support the prototype's functionality and scalability.
2. Develop an IoT-enabled prototype that automates temperature measurement.
3. Utilize sensors controlled by microcontrollers to monitor and manage radiator performance.
4. Create a user-friendly interface (mobile or web application) for real-time feedback and control.
5. Test and evaluate the prototype in a simulated environment to ensure accuracy and efficiency.
6. Use a git repository to track your work as a team. This should follow git best practices where possible.

---

## Key Features of the IoT Solution

### **Temperature Monitoring**
Each radiator will have a temperature sensor to measure the inlet and outlet temperatures.

### **Actuator-Controlled Valves**
Microcontrollers will adjust lockshield valves automatically based on temperature readings.

### **Wireless Communication**
Use Wi-Fi or Bluetooth modules for communication between microcontrollers and the central hub or mobile application.

### **Data Visualization**
A mobile or web app will display temperature readings, valve statuses, and system performance in real time.

### **Automated Recommendations**
The system will suggest or automatically implement adjustments for optimal heat distribution.

---

## Expected Outcomes

- A working prototype (2 devices + services) that simplifies heating system balancing through IoT.
- An intuitive user interface for installers to monitor and control the system.
- Comprehensive documentation detailing the design, implementation, and testing process.
- Insights into further development and scalability for real-world applications.
- Working knowledge of Git. https://gist.github.com/luismts/495d982e8c5b1a0ced4a57cf3d93cf60

---

## Further Objectives

1. Create a system for 'job' history.
2. Develop an IoT-enabled prototype that automates temperature measurement and adjustment processes.
3. Create a guided setup feature to helpm the end user.

---

## Key Notes for Students

- This project should be approached as a research and development exercise, where your work serves as a foundation for future improvements and expansions.  
- **Documentation is imperative**: Your report must be clear, concise, and well-structured to allow others to understand and build upon your work. Include system design, implementation details, testing results, and justifications for your choices.  
- **Focus on scalability and extensibility**: Ensure your solution demonstrates how it could be expanded or adapted for future use cases or larger systems.  
- **Highlight critical thinking and research**: Justify your technology stack, design choices, and feature implementations with evidence-based reasoning and references where appropriate.  
- **Testing and evaluation** are crucial: A thorough evaluation of your prototype's functionality, limitations, and potential areas for improvement will be highly valued.  
- **Innovation and originality**: Aim to go beyond the baseline objectives by addressing further objectives or proposing new features that add significant value to the project.  
- Your work should not only solve the problem but also **contribute to your academic and practical understanding** of IoT-based systems.
