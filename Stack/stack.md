# Stack (LIFO)

## Concept

A **stack** is a linear data structure that follows **LIFO** — Last In, First Out. The last element pushed onto the stack is the first one popped off. Think of a stack of plates: you add and remove from the top only.

- `TOP` tracks the index of the most recently inserted element.
- `TOP = -1` means the stack is empty.
- `TOP = MAX - 1` means the stack is full.

Only one end of the structure is ever accessed — the **top**.

## Figure

```
   Push 3 →                Pop →
                          removes 3
   ┌─────┐                ┌─────┐
   │  3  │ ← TOP          │  2  │ ← TOP
   ├─────┤                ├─────┤
   │  2  │                │  1  │
   ├─────┤                └─────┘
   │  1  │
   └─────┘
   index 0

Array view:  [ 1 | 2 | 3 |   |   ]
                       ↑
                      TOP = 2
```

## Operations

| Operation | Description | Time Complexity |
|---|---|---|
| `push(x)` | Insert `x` at the top | O(1) |
| `pop()` | Remove and return the top element | O(1) |
| `peek()` | View the top element without removing it | O(1) |
| `display()` | Print all elements from top to bottom | O(n) |

## Pseudocode

```
STACK[MAX], TOP = -1

PUSH(x):
    if TOP == MAX - 1:
        print "Stack Overflow"
        return
    TOP = TOP + 1
    STACK[TOP] = x

POP():
    if TOP == -1:
        print "Stack Underflow"
        return
    value = STACK[TOP]
    TOP = TOP - 1
    return value

PEEK():
    if TOP == -1:
        print "Stack Empty"
        return
    return STACK[TOP]

DISPLAY():
    if TOP == -1:
        print "Stack Empty"
        return
    for i = TOP down to 0:
        print STACK[i]
```

## Key Points

- Overflow check: `TOP == MAX - 1`
- Underflow check: `TOP == -1`
- All operations are **O(1)** except `display`, which is O(n).
- In the C implementation, `push`/`pop` take `int *top` (they modify state), while `peek`/`display` take `int top` (they only read it).
