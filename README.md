# Flight Management System (C)

## Overview
This repository contains a modular **Flight Management System** developed in **C** as part of the Laboratórios de Informática III course at the University of Minho.

The application is designed to ingest, validate, and process large relational datasets (CSV files containing information about airports, flights, passengers, and reservations). It structures this data in memory using optimized data collections to execute complex analytical queries under strict performance and memory limitations.

## Key Features
* **Modular Architecture:** Fully structured following strict modularization and encapsulation principles, dividing the code into clear entities, managers, parsers, and query executors.
* **Robust Data Validation:** Implements multi-layered syntax and logical validation checks (e.g., verifying date formats, email layouts, flight paths, and cross-entity existence) while logging corrupted entries to error files.
* **Performance-Oriented Queries:** Developed to answer targeted dataset queries rapidly (e.g., fetching airport summaries, listing top active aircraft, or tracking busiest flight schedules).
* **Memory & Leak Management:** Engineered with strict memory lifecycle controls, ensuring zero memory leaks when audited under tools like `valgrind`.

---

## Architecture & Technologies
* **Language:** C (Standard ISO C / standard library `libc`)
* **Optional Collections:** Developed using the `glib2` library for robust and efficient data structuring (Hash Tables, Linked Lists, Arrays).
* **Testing & Profile Tools:** Verified using `gdb`, `valgrind`, and specific system utilities (`sys/resource.h` and `time.h`) to monitor CPU time and peak RAM usage.

---

## Getting Started

### Prerequisites
* Linux environment 
* GCC Compiler & Make
* `glib2` developer package (if utilized):
  ```bash
  sudo apt install libglib2.0-dev
