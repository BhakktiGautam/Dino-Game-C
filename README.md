# 🦖 Dino Game in C

A simple console-based Dino Game built using C language.
Inspired by the Chrome offline dinosaur game, this project demonstrates basic game development concepts like input handling, collision detection, and real-time rendering in the terminal.

---

## 🎮 Features

* 🦖 Dino character with jump and duck actions
* 🧱 Randomly generated obstacles
* ⚡ Increasing game speed over time
* 💀 Collision detection system
* 🔁 Restart option after game over
* 🖥️ Console-based rendering using ASCII

---

## 🕹️ Controls

| Key            | Action       |
| -------------- | ------------ |
| SPACE          | Jump         |
| ↓ (Down Arrow) | Duck         |
| R              | Restart Game |
| Any other key  | Exit         |

---

## 🚀 How to Run

### 🔧 Requirements

* GCC Compiler (MinGW / MSYS2 / any C compiler)
* Windows OS (uses `conio.h` and `windows.h`)

### ▶️ Compile

```bash
gcc Dino_Game_inC.c -o dino.exe
```

### ▶️ Run

```bash
./dino.exe
```

---

## 🧠 Game Logic

The game runs on a continuous loop:

* Takes user input (`kbhit`, `getch`)
* Updates game state (jump, obstacles)
* Clears screen and redraws frame
* Checks collision
* Updates score and speed

---

## 📸 Gameplay

```
Dino game
Score : 25

     D
    |    
___________|_____
```

---

## 🔮 Future Improvements

* 🎵 Sound effects
* 💾 High score saving
* 🎮 Pause functionality
* 🎨 Better graphics (colors / animation)
* 📱 Cross-platform support

---

## 👨‍💻 Author

Made with ❤️ by [Bhakkti Gautam]

---

## 📜 License

This project is open-source and free to use.
