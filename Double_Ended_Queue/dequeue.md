# Dequeue (Double-Ended Queue)

## Concept

A **dequeue** (deque) is a linear structure that allows insertion and deletion from **both ends** — front and rear. It generalizes both stacks and queues: used one way, it behaves like a queue; used another way, it can behave like a stack.

- `FRONT == -1` means the dequeue is empty.
- `REAR == MAX - 1` means no room to insert at the rear.
- `FRONT == 0` means no room to insert at the front.

## Figure

```
        insertFront            insertRear
             ↓                      ↓
        ┌───┬───┬───┬───┬───┐
        │   │ 2 │ 3 │ 4 │   │
        └───┴───┴───┴───┴───┘
             ↑                      ↑
        deleteFront            deleteRear

        FRONT = 1, REAR = 3

After insertFront(1) and insertRear(5):
        ┌───┬───┬───┬───┬───┐
        │ 1 │ 2 │ 3 │ 4 │ 5 │
        └───┴───┴───┴───┴───┘
          ↑                 ↑
        FRONT             REAR
```

## Operations

| Operation | Description | Time Complexity |
|---|---|---|
| `insertRear(x)` | Add `x` at the rear | O(1) |
| `insertFront(x)` | Add `x` at the front | O(1) |
| `deleteFront()` | Remove element from the front | O(1) |
| `deleteRear()` | Remove element from the rear | O(1) |
| `display()` | Print all elements from front to rear | O(n) |

## Pseudocode

```
QUEUE[MAX], FRONT = -1, REAR = -1

INSERT_REAR(x):
    if REAR == MAX - 1:
        print "Queue is Full"
        return
    if FRONT == -1:
        FRONT = 0
    REAR = REAR + 1
    QUEUE[REAR] = x

INSERT_FRONT(x):
    if FRONT == 0:
        print "No space at front"
        return
    if FRONT == -1:
        FRONT = 0
        REAR = 0
    else:
        FRONT = FRONT - 1
    QUEUE[FRONT] = x

DELETE_FRONT():
    if FRONT == -1:
        print "Queue Empty"
        return
    value = QUEUE[FRONT]
    if FRONT == REAR:
        FRONT = -1
        REAR = -1
    else:
        FRONT = FRONT + 1
    return value

DELETE_REAR():
    if FRONT == -1:
        print "Queue Empty"
        return
    value = QUEUE[REAR]
    if FRONT == REAR:
        FRONT = -1
        REAR = -1
    else:
        REAR = REAR - 1
    return value

DISPLAY():
    if FRONT == -1:
        print "Queue Empty"
        return
    for i = FRONT to REAR:
        print QUEUE[i]
```

## Key Points

- Two "full" checks: `REAR == MAX - 1` (no room at rear) and `FRONT == 0` (no room at front).
- Empty check: `FRONT == -1`.
- Note: this is a **simple array-based dequeue**, not circular — `insertFront` is limited once `FRONT` hits index `0`, even if there's free space at the rear end (a true circular dequeue would wrap both ends using `% MAX`, similar to the circular queue).
