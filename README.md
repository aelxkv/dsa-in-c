# Data Structures in C

This repository contains array-based C implementations of core linear data structures. Each structure is implemented using **pointer parameters** to modify state (`front`, `rear`, `top`) declared locally in `main()`, rather than as global variables — a cleaner and more reusable design.

## Structures Covered

| Structure | Description | File |
|---|---|---|
| Stack | LIFO (Last In, First Out) structure | [`stack.md`](stack.md) |
| Queue | FIFO (First In, First Out) linear structure | [`queue.md`](queue.md) |
| Circular Queue | Space-efficient FIFO structure that reuses freed slots | [`circular_queue.md`](circular_queue.md) |
| Dequeue | Double-ended queue — insertion/deletion from both ends | [`dequeue.md`](dequeue.md) |

## Design Notes

- **Array-based** implementations (fixed max size `MAX`), not linked-list based.
- `FRONT`, `REAR`, and `TOP` are declared **locally in `main()`** and passed to functions:
  - Functions that **modify** state (`insert`, `delete`, `push`, `pop`) receive **pointers** (`int *front`).
  - Functions that only **read** state (`display`, `peek`) receive **plain values** (`int front`).
- `-1` is used as the sentinel value to represent "empty."

## How to Compile

Each `.md` file contains a pseudocode outline and concept explanation; the actual `.c` source files live alongside them in this repo. To compile any of them:

```bash
gcc stack.c -o stack
./stack
```

## Comparison at a Glance

```
Stack (LIFO)          Queue (FIFO)              Circular Queue           Deque
┌───┐                 ┌───┬───┬───┬───┐          ┌───┬───┬───┬───┐        ┌───┬───┬───┬───┐
│ 3 │ <- top           F               R          wraps around →         insert/delete
├───┤                 │ 1 │ 2 │ 3 │ 4 │           │ 4 │   │ 2 │ 3 │       at BOTH ends
│ 2 │                 └───┴───┴───┴───┘           └───┴───┴───┴───┘        ↑         ↑
├───┤                                              R       F             FRONT     REAR
│ 1 │
└───┘
```

See each file for the full concept, diagram, and pseudocode.
.
