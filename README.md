# Sensor-Based-Ambient-Lights
PG-7232 Embedded Systems - Project Sprint 2

This project contains the firmware and simulation of a prototype of ambient lights. It contains a PIC16F1768 to manage all the digital signals. This repository includes a [MPLABX](https://www.microchip.com/en-us/development-tools-tools-and-software/mplab-x-ide) project, with the source code for the microcontroller (the folder Hela.X). It also contains a [Proteus](https://www.labcenter.com/simulation/) project  used to simulate and test the electronic design.

The design is a modular system that allows the user to multiple usage modes for an [110V/220V LED Strip](https://es.aliexpress.com/item/1005001989354694.html?spm=a2g0o.productlist.0.0.15731814f4HM3v&algo_pvid=82597dfd-2696-4544-87ad-ca4784616c1c&algo_expid=82597dfd-2696-): they can be turn on/of manually or automatically depending on a the time of the day or the amount of light in the environment.

For further information about the design requirements and the overall design visit the [Documents](https://github.com/leonardoward/Sensor-Based-Ambient-Lights/tree/main/Documents) folder for a more detailed report.

## Table of Contents

1. [About the Project](#about-the-project)
2. [Getting Started](#getting-started)
    1. [Dependencies](#dependencies)
    2. [Building](#building)
    3. [Usage](#usage)
3. [Further Reading](#further-reading)
4. [Authors](#authors)

# About the Project

The following image presents the Proteus Project with the complete electronic design:

![Proteus Project](./images/proteus_schematic.png)

The following video presents the available features achieved with the last version of the source code.

[![Demonstration](./images/demonstration.jpeg)](https://youtu.be/3KqcJgEQBLA "Demostración Proyecto 2 HELA - Luces inteligentes")

# Getting Started

## Dependencies

The project only requires the following development environments:

* [MPLABX](https://www.microchip.com/en-us/development-tools-tools-and-software/mplab-x-ide)
* [Proteus](https://www.labcenter.com/simulation/)

The Proteus project uses components the are contained in the environment by default, doesn't require additional component imports.

**[Back to top](#table-of-contents)**

## Building

The building process is performed in the MPLABX development environment.

**[Back to top](#table-of-contents)**

## Getting the Source

This project is [hosted on GitHub](https://github.com/leonardoward/Sensor-Based-Ambient-Lights/). You can clone this project directly using this command:

```
git clone https://github.com/leonardoward/Sensor-Based-Ambient-Lights.git
```

**[Back to top](#table-of-contents)**

## Running Tests

The Proteus project contains a Serial Terminal that is used to display messages that can be used to debug errors.

**[Back to top](#table-of-contents)**

# Further Reading

The folder [Documents](https://github.com/leonardoward/Sensor-Based-Ambient-Lights/tree/main/Documents) contains a Report with the design process, and a document with the Bill od Materials.

**[Back to top](#table-of-contents)**

# Authors

* **[Carlos Sanoja](https://github.com/CarSanoja)**
* **[Jesús Guillen](https://github.com/JG-Guillen)**
* **[Leonardo Ward](https://github.com/leonardoward)**
* **[Mauricio Marcano](https://github.com/rinripper)**
* **[Oscar Moreno](https://github.com/OscarEMoreno)**
* **[Vincenzo D’Argento](https://github.com/vincdargento)**

**[Back to top](#table-of-contents)**
