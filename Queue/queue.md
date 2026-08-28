# Queue (Linear, FIFO)

## Concept

A **queue** is a linear data structure that follows **FIFO** — First In, First Out. Elements are added at the **rear** and removed from the **front**, just like a real-world line/queue of people.

- `FRONT` tracks the index of the first element.
- `REAR` tracks the index of the last element.
- `FRONT == -1` means the queue is empty.
- `REAR == MAX - 1` means the queue is full (linear queue limitation — see below).

## Figure

```
Insert(4):
        FRONT                REAR
          ↓                    ↓
        ┌───┬───┬───┬───┬───┐
        │ 1 │ 2 │ 3 │ 4 │   │
        └───┴───┴───┴───┴───┘
          0   1   2   3   4

Delete():  removes 1 (front)
              FRONT        REAR
                ↓             ↓
        ┌───┬───┬───┬───┬───┐
        │   │ 2 │ 3 │ 4 │   │
        └───┴───┴───┴───┴───┘
```

## The Linear Queue Limitation

Once `REAR` reaches `MAX - 1`, the queue reports **full** — even if elements have been deleted from the front and slots `0`, `1`, etc. are empty. Those freed slots are wasted because `REAR` only ever moves forward.

```
        ┌───┬───┬───┬───┬───┐
        │   │   │   │ 4 │ 5 │  ← REAR = 4 (full), but 3 slots wasted
        └───┴───┴───┴───┴───┘
          ↑ freed, unusable space
```

This is fixed by the **Circular Queue** (see `circular_queue.md`).

## Operations

| Operation | Description | Time Complexity |
|---|---|---|
| `insert(x)` | Add `x` at the rear | O(1) |
| `delete()` | Remove and return the front element | O(1) |
| `display()` | Print all elements from front to rear | O(n) |

## Pseudocode

```
QUEUE[MAX], FRONT = -1, REAR = -1

INSERT(x):
    if REAR == MAX - 1:
        print "Queue is Full"
        return
    if FRONT == -1:
        FRONT = 0
    REAR = REAR + 1
    QUEUE[REAR] = x

DELETE():
    if FRONT == -1 or FRONT > REAR:
        print "Queue Empty"
        return
    value = QUEUE[FRONT]
    FRONT = FRONT + 1
    return value

DISPLAY():
    if FRONT == -1 or FRONT > REAR:
        print "Queue Empty"
        return
    for i = FRONT to REAR:
        print QUEUE[i]
```

## Key Points

- Full check: `REAR == MAX - 1`
- Empty check: `FRONT == -1` or `FRONT > REAR`
- `insert`/`delete` take `int *front, int *rear` (they modify state); `display` takes plain values.
