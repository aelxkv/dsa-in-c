# Data Structures in C

This repository contains array-based C implementations of core linear data structures. Each structure is implemented using **pointer parameters** to modify state (`front`, `rear`, `top`) declared locally in `main()`, rather than as global variables — a cleaner and more reusable design.

## Structures Covered

| Structure | Description | File |
|---|---|---|
| Stack | LIFO (Last In, First Out) structure | [`Stack/stack.md`](Stack/stack.md) |
| Queue | FIFO (First In, First Out) linear structure | [`Queue/queue.md`](Queue/queue.md) |
| Circular Queue | Space-efficient FIFO structure that reuses freed slots | [`Circular_Queue/circular_queue.md`](Circular_Queue/circular_queue.md) |
| Dequeue | Double-ended queue — insertion/deletion from both ends | [`Double_Ended_Queue/dequeue.md`](Double_Ended_Queue/dequeue.md) |

## Design Notes

- **Array-based** implementations (fixed max size `MAX`), not linked-list based.
- `FRONT`, `REAR`, and `TOP` are declared **locally in `main()`** and passed to functions:
  - Functions that **modify** state (`insert`, `delete`, `push`, `pop`) receive **pointers** (`int *front`).
  - Functions that only **read** state (`display`, `peek`) receive **plain values** (`int front`).
- `-1` is used as the sentinel value to represent "empty."

## How to Compile

Each `.md` file contains a pseudocode outline and concept explanation; the matching `.c` source file lives in the same folder. To compile any of them:

```bash
cd Stack
gcc stack.c -o stack
./stack
```

## Comparison at a Glance

**Stack (LIFO)** — insert/remove only at the top

```
┌───┐
│ 3 │ <- top
├───┤
│ 2 │
├───┤
│ 1 │
└───┘
```

**Queue (FIFO)** — insert at rear, remove from front

```
  F               R
┌───┬───┬───┬───┐
│ 1 │ 2 │ 3 │ 4 │
└───┴───┴───┴───┘
```

**Circular Queue** — rear wraps back around to reuse freed space

```
┌───┬───┬───┬───┐
│ 4 │   │ 2 │ 3 │
└───┴───┴───┴───┘
  R           F
(wraps around)
```

**Dequeue** — insert/remove from BOTH ends

```
     ┌───┬───┬───┬───┐
     │ 1 │ 2 │ 3 │ 4 │
     └───┴───┴───┴───┘
       ↑             ↑
     FRONT          REAR
```

See each file for the full concept, diagram, and pseudocode.
