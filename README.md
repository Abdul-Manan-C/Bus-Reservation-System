<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0,1a1a2e,0d1117,162447&height=180&section=header&text=Bus%20Reservation%20System&fontSize=40&animation=fadeIn&fontColor=58a6ff&fontAlignY=40&desc=C%2B%2B%20Console%20Application%20%7C%20File-based%20Storage&descSize=16&descAlignY=62&descColor=8b949e" />

</div>

<div align="center">

<img src="https://readme-typing-svg.demolab.com?font=JetBrains+Mono&size=16&pause=1000&color=58A6FF&center=true&vCenter=true&width=600&lines=Add+buses+%E2%86%92+Reserve+seats+%E2%86%92+View+reports;File-based+persistent+storage+%7C+No+database+needed;Pure+C%2B%2B+%7C+iostream+%7C+fstream+%7C+string;Runs+on+Linux+%C2%B7+Windows+%C2%B7+Termux" alt="typing" />

</div>

<br/>

<div align="center">

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Standard](https://img.shields.io/badge/Standard-C++17-blue?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-3fb950?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20Windows%20%7C%20Termux-a371f7?style=for-the-badge&logo=linux&logoColor=white)
![Stars](https://img.shields.io/github/stars/Abdul-Manan-C/Bus-Reservation-System?style=for-the-badge&color=ffa657)

</div>

---

## `$ ./reservation_system`

```
===== BUS RESERVATION SYSTEM =====
1. Add Bus Information
2. Reserve Seat(s)
3. Show Reservation Report
4. Show Available Buses
99. Exit Program
====================================
Enter Option:
```

---

## `$ cat overview.txt`

**Bus Reservation System** is a console-based C++ application for managing bus routes and passenger bookings. All data persists automatically to local `.txt` files — no database, no external libraries, just standard C++.

Built as a university project (BSCS — UAJK) to practice procedural programming, file I/O, and structured application design.

---

## `$ ./reservation_system --features`

### What it does

| Feature | Description |
|---|---|
| 🚌 **Add Bus** | Register a bus with plate number, chassis number, and type (mini/big) |
| 🎫 **Reserve Seat** | Select a bus by plate, choose available seat numbers, enter passenger names |
| 📋 **View Reservations** | Full report of all booked seats with bus details and passenger names |
| 🔍 **View Buses** | List all registered buses with plate, chassis, type, and total seats |
| 💾 **Auto-save** | All data instantly written to `bus_data.txt` and `seat.txt` |
| ✅ **Seat Validation** | Blocks double-booking, invalid seat numbers, and over-capacity requests |
| 🔄 **Chain Booking** | Option to book another bus immediately after completing a reservation |

### Bus types

```
mini  →  30 seats
big   →  50 seats
```

---

## `$ cat architecture.txt`

```
main.cpp
│
├── main()             ← menu loop (0 = show menu, 99 = exit)
│
├── addBus()           ← writes to bus_data.txt
│   Format: plate|chassis|type|seats
│
├── reserveSeat()      ← reads bus_data.txt, writes to seat.txt
│   Format: plate seatNumber passengerName
│
├── viewReservations() ← reads seat.txt + cross-refs bus_data.txt
│
└── viewBuses()        ← reads bus_data.txt
```

**Data files created at runtime:**

| File | Contents | Created by |
|---|---|---|
| `bus_data.txt` | `plate\|chassis\|type\|seats` per line | `addBus()` |
| `seat.txt` | `plate seatNum passengerName` per line | `reserveSeat()` |

**Libraries used:**
```cpp
#include <iostream>   // console I/O
#include <fstream>    // file read/write
#include <string>     // string handling
```
No external dependencies. No database. No setup beyond a C++ compiler.

---

## `$ g++ main.cpp -o reservation_system && ./reservation_system`

### Requirements

- C++ compiler: `g++` / `clang++` / MinGW (Windows)
- Any OS: Linux · Windows · Termux (Android)

### Build & run

```bash
# Clone
git clone https://github.com/Abdul-Manan-C/Bus-Reservation-System.git
cd Bus-Reservation-System

# Compile
g++ main.cpp -o reservation_system

# Run
./reservation_system          # Linux / Termux
reservation_system.exe        # Windows
```

### Quick walkthrough

```bash
# Step 1 — add a bus
Enter Option: 1
Enter Bus Plate Number: ABC-123
Enter Bus Chasis Number: CH-456789
Enter Bus Type (mini/big): mini
→ Bus added successfully.  (30 seats, saved to bus_data.txt)

# Step 2 — reserve a seat
Enter Option: 2
Enter Bus Plate Number: ABC-123
How many seats do you want to reserve? 2
Enter Seat Number for Passenger 1: 5
Enter Passenger Name: Ali Raza
Enter Seat Number for Passenger 2: 12
Enter Passenger Name: Sara Khan
→ RESERVATION SUCCESSFUL!

# Step 3 — view report
Enter Option: 3
Bus: ABC-123 (Chassis: CH-456789) | Seat: 5  | Passenger: Ali Raza
Bus: ABC-123 (Chassis: CH-456789) | Seat: 12 | Passenger: Sara Khan
```

---

## `$ cat project_structure.txt`

```
Bus-Reservation-System/
│
├── main.cpp              ← entire application (single file)
├── README.md
│
├── assets/
│   └── images/           ← screenshots (if added)
│
└── [runtime files — created when you run the app]
    ├── bus_data.txt       ← bus registry
    └── seat.txt           ← seat reservations
```

---

## `$ cat author.txt`

<div align="center">

**Ch Manan** · `OBLIQ_CORE` · BSCS @ UAJK

[![GitHub](https://img.shields.io/badge/GitHub-Abdul--Manan--C-181717?style=for-the-badge&logo=github)](https://github.com/Abdul-Manan-C)
[![Portfolio](https://img.shields.io/badge/Portfolio-abdulmannan.galaxydev.pk-00ffaa?style=for-the-badge&logo=firefox&logoColor=white)](https://abdulmannan.galaxydev.pk)
[![TryHackMe](https://img.shields.io/badge/TryHackMe-mananhanif01-212C42?style=for-the-badge&logo=tryhackme)](https://tryhackme.com/p/mananhanif01)

<img src="https://readme-typing-svg.demolab.com?font=JetBrains+Mono&size=13&pause=2000&color=3FB950&center=true&vCenter=true&width=480&lines=%22Code+with+purpose.+Learn+deeply.+Build+efficiently.%22" alt="quote" />

</div>

---

<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0,162447,0d1117,1a1a2e&height=100&section=footer&fontColor=58a6ff&animation=fadeIn" />

</div>
