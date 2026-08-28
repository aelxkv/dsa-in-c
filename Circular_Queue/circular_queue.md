# Circular Queue

## Concept

A **circular queue** is a queue where the last position wraps around to connect back to the first position, forming a circle. This solves the linear queue's problem of wasting freed-up slots at the front — `REAR` can wrap using modulo arithmetic (`% MAX`) to reuse space instead of always moving forward.

- `FRONT` and `REAR` both wrap around using `(index + 1) % MAX`.
- `FRONT == -1` means the queue is empty.
- `(REAR + 1) % MAX == FRONT` means the queue is full.

> Note: This design intentionally "sacrifices" one array slot to distinguish full from empty, so it holds `MAX - 1` elements, not `MAX`.

## Figure

```
              index 0
                ┌───┐
     index 4 ┌──┤   ├──┐ index 1
             │  └───┘  │
           ┌─┴─┐     ┌─┴─┐
           │ 4 │     │ 1 │
           └─┬─┘     └─┬─┘
             │  ┌───┐  │
     index 3 └──┤   ├──┘ index 2
                └───┘
              index 2

After wrap-around:
        REAR              FRONT
          ↓                  ↓
        ┌───┬───┬───┬───┬───┐
        │ 5 │ 6 │   │ 3 │ 4 │
        └───┴───┴───┴───┴───┘
          0   1   2   3   4

REAR (1) is numerically SMALLER than FRONT (3) — this is normal
and expected once the queue has wrapped around.
```

## Operations

| Operation | Description | Time Complexity |
|---|---|---|
| `insert(x)` | Add `x` at rear, wrapping if needed | O(1) |
| `delete()` | Remove front element, wrapping if needed | O(1) |
| `display()` | Print elements from front to rear (wrap-aware) | O(n) |

## Pseudocode

```
QUEUE[MAX], FRONT = -1, REAR = -1

INSERT(x):
    if (REAR + 1) % MAX == FRONT:
        print "Queue is Full"
        return
    if FRONT == -1:
        FRONT = 0
    REAR = (REAR + 1) % MAX
    QUEUE[REAR] = x

DELETE():
    if FRONT == -1:
        print "Queue Empty"
        return
    value = QUEUE[FRONT]
    if FRONT == REAR:
        FRONT = -1
        REAR = -1
    else:
        FRONT = (FRONT + 1) % MAX
    return value

DISPLAY():
    if FRONT == -1:
        print "Queue Empty"
        return
    i = FRONT
    while true:
        print QUEUE[i]
        if i == REAR:
            break
        i = (i + 1) % MAX
```

## Why Not a Simple `for` Loop in Display?

Because `REAR` can be numerically **smaller** than `FRONT` after wrapping, `for (i = FRONT; i <= REAR; i++)` breaks — it may never execute even though the queue is non-empty. Instead, `DISPLAY` walks forward with `% MAX` until `i` **equals** `REAR`, regardless of numeric order.

## Key Points

- Full check: `(REAR + 1) % MAX == FRONT`
- Empty check: `FRONT == -1`
- `insert`/`delete` take pointers; `display` takes plain values, but uses a `while` loop instead of a `for` loop due to wrap-around.
