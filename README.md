# Tic-Tac-Toe 

A **C++ Tic-Tac-Toe game** with an opponent using **Minimax algorithm with Alpha-Beta Pruning**. Built with **Object-Oriented Programming** principles.

---

##  Features

-  **Minimax algorithm** 
-  **Two Modes** - Player vs AI or Player vs Player
-  **OOP Design** - Inheritance, Polymorphism, Encapsulation
-  **Input Validation** - No invalid moves
-  **Optimized** - Alpha-Beta pruning for speed

---

##  Build & Run

**Compile:**

g++ -std=c++17 -o TicTacToe main.cpp Player.cpp Computer.cpp game.cpp Display.cpp


**Run:**

./TicTacToe


---

##  How to Play

1. Choose mode: `1` (vs AI) or `2` (vs Player)
2. Enter your move (1-9)
3. Computer plays optimally
4. Game ends when someone wins or draws

```
 1 | 2 | 3
-----------
 4 | 5 | 6
-----------
 7 | 8 | 9
```

---

## Project Structure

| File | Purpose |
|------|---------|
| `main.cpp` | Game loop & entry point |
| `Player.h/cpp` | Base player class |
| `Computer.h/cpp` | AI with Minimax |
| `Game.h/cpp` | Board & game logic |
| `Display.h/cpp` | Console UI |

---

## OOP Design

**Classes:**
- `Player` (base) - Human player
- `Computer` (derived) - AI opponent
- `Game` - Manages board & state
- `Display` - UI abstraction

**Concepts Used:**
-  Inheritance (`Computer extends Player`)
-  Polymorphism (virtual `makeMove()`)
-  Encapsulation (private members)
-  Abstraction (clean interfaces)

---

##   Algorithm

**Minimax** evaluates all game states:
- Scores: Win (+10), Loss (-10), Draw (0)
- Recursively finds best move
- **Alpha-Beta Pruning** optimizes performance
---


##  Learning Value

Perfect for understanding:
- Object-Oriented Design
- Inheritance & Polymorphism
- Game Tree Algorithms
- Alpha-Beta Pruning
- Encapsulation Patterns

---
