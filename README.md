# Wireless Power Transfer System for Electric Vehicles

> 👇 Below you can see the inverter board and a real-time working demo:

![Inverter Front View](Images%20and%20Presentation/DC-AC%20Inverter%20Front.jpeg)

![Operating Demo](Images%20and%20Presentation/Operating.gif)

## 📌 Project Summary
This project presents a **wireless power transfer (WPT)** system prototype aimed at demonstrating the basic principles of resonant inductive coupling for electric vehicle (EV) charging applications. The prototype is based on an **Arduino-controlled** system that generates a high-frequency AC output using a **H-bridge inverter**, optimized for energy transfer over short distances via an air-core coil pair.

This project was developed as a senior design (bitirme) project in the Electrical and Electronics Engineering Department.

---

## ⚙️ Technical Features

- **Input Voltage:** 24V DC
- **Output Voltage:** ~18V AC (square wave, measured ≈3V AC RMS on multimeter) 
- **Control:** Arduino Uno R3-based PWM generation
- **Topology:** H-Bridge Inverter using IRFZ44N MOSFETs and IR2110 Gate Drivers
- **Regulation:** LM2596 Buck Converter for voltage stepping
- **Rectification:** Fast recovery Schottky diodes at receiver side
- **PCB Design Software:** KiCad 9.0

---

## 🔧 Hardware and Software Used

- **Microcontroller:** Arduino Uno R3  
- **H-Bridge Topology:** Implemented using IRFZ44N MOSFETs  
- **Gate Driver:** IR2110  
- **DC-DC Regulator:** LM2596 (Used to step down the 24V input to 12V to power the IR2110 gate driver ICs. Additionally, another LM2596 module was configured to provide a 5V regulated output to safely interface the Arduino Uno R3’s PWM control signals with the IR2110 inputs.)  
- **Protection Diodes:** 1N5817 Schottky Diodes  
- **PCB Design:** KiCad 9.0 (schematic and PCB design)

---

## ⚙️ PCB Production

The PCB for the inverter stage was fully fabricated by hand, using personal resources and without relying on any professional PCB manufacturing service. The entire process — including etching, manual drilling, and component soldering — was carried out with basic tools, showcasing a hands-on, resourceful approach to hardware prototyping under limited conditions.

---

## 🧪 Testing and Results

- Square wave signal confirmed on the output using an oscilloscope  
- Successful power transfer to receiver coil  
- 3D visualization used for mechanical validation

---

## 📂 Suggested Folder Structure

- `DC-AC Inverter with H-Bridge/`  
  ├── `Code/`  
  ├── `Images and Presentation/`  
    ├── [Operating.mp4](https://www.youtube.com/shorts/zgLSwQ5zg5Q)  
    └── [Wireless Electric Vehicle Charging System KTU EEE.mp4](https://www.youtube.com/shorts/1_IPSUS-X5c)  
  ├── `PCB/`  
    ├── `3D/`  
    ├── `BOM/`  
    ├── `Drill/`  
    └── `Gerber/`  
  ├── `Schematics/`  
  ├── `Simulation Graphs/`  
  └── `README.md`

---

## 📝 Notes

- This circuit is part of a larger system intended to provide an efficient power transfer layer for wireless charging of electric vehicles.  
- All components were selected based on reliable datasheet references and added to KiCad libraries accordingly.

---

## 📚 Future Improvements

- Implement closed-loop current control via feedback
- Design custom receiver coil enclosure
- Replace Arduino with STM32 for better signal precision
- Improve EMI shielding and cooling

---

## 📬 Contact

If you have any questions or want to collaborate, feel free to reach out via GitHub or [LinkedIn](https://www.linkedin.com/in/envergokaycay/).

