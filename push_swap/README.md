*This project has been created as part of the 42 curriculum by guicarva, gfranca*

---

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using a limited set of operations, in as few moves as possible, using two stacks — `a` and `b`.

The challenge is not just to sort, but to do so **efficiently**: the grading is based on the number of operations used to sort a given set of integers. This pushes us to study, implement, and compare different algorithmic strategies.

The program reads a list of integers from the command line, and writes to standard output the sequence of operations needed to sort stack `a` in ascending order.

---

## Allowed Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack `a` |
| `sb` | Swap the first two elements of stack `b` |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the top of `b` onto `a` |
| `pb` | Push the top of `a` onto `b` |
| `ra` | Rotate `a` upward (first element becomes last) |
| `rb` | Rotate `b` upward |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate `a` (last element becomes first) |
| `rrb` | Reverse rotate `b` |
| `rrr` | `rra` and `rrb` at the same time |

---

## Instructions

### Compilation

```bash
make
```

This produces the `push_swap` executable.

```bash
make clean    # remove object files
make fclean   # remove object files and executable
make re       # fclean + all
```

### Execution

```bash
./push_swap [integers...]
```

Integers can be passed as separate arguments or as a quoted string:

```bash
./push_swap 3 1 4 1 5       # Error: duplicate
./push_swap 3 1 4 2 5
./push_swap "3 1 4 2 5"
```

### Optional Flags

| Flag | Description |
|------|-------------|
| `--bench` | Print operation statistics after sorting |
| `--simple` | Force Turkish sort (greedy insertion, O(n²)) |
| `--medium` | Force the O(n√n) chunk sort (k-sort) |
| `--complex` | Force Radix sort (LSD bitwise, O(n log n)) |
| `--adaptive` | Let the program choose based on disorder level |

```bash
./push_swap --bench 5 3 1 4 2
./push_swap --complex $(seq 1 100 | shuf | tr '\n' ' ')
```

### Checking correctness

You can pipe the output into a checker to verify the result:

```bash
ARG="5 3 1 4 2"
./push_swap $ARG | wc -l           # count operations
./push_swap $ARG | ./checker $ARG  # verify sort (if checker available)
```

---

## Algorithms

This project implements **three main sorting strategies**, selected adaptively based on the disorder level of the input. Below is a detailed explanation, justification, and complexity analysis of each.

---

### 1. Simple Sort — for ≤ 5 elements

**How it works:**

- For **2 elements**: one `sa` if needed.
- For **3 elements** (`simple_3low`): every possible ordering of 3 values is handled with a hardcoded sequence of at most 2 operations.
- For **4–5 elements** (`sort_simple`): elements are extracted one by one to stack `b` in sorted order (smallest first), then pushed back to `a`. Each extraction uses `bring_to_top` to rotate the target to the top before pushing.

**Why:**
Small inputs have very few possible states, making brute-force/hardcoded solutions optimal. These cases must be handled perfectly to meet grading thresholds.

---

### 2. Turkish Sort (Greedy Insertion) — O(n²) — `--simple` flag

**How it works:**

Based on the "Turk algorithm" — a greedy, cost-minimizing insertion sort between two stacks:

1. Push the first two elements to `b`.
2. For every remaining element in `a`, scan all elements in `a` and compute the **cheapest move**: the pair (position in `a`, target position in `b`) that requires the fewest total rotations. Target position in `b` is the slot where the element fits in descending order.
3. Execute the cheapest move using simultaneous rotations (`rr`/`rrr`) when both stacks rotate in the same direction, then individual rotations, then `pb`.
4. After `a` is reduced to 3 elements, apply `simple_3low`.
5. Push everything back from `b` to `a` using `get_target_a_pos` to find the correct insertion point each time.
6. Finally, rotate `a` so the minimum is at the top.

**Cost function (`total_cost`):**

All four rotation strategies are evaluated and the minimum is selected:
- `rr` cost: `max(pos_a, pos_b)` — simultaneous forward rotation
- `rrr` cost: `max(size_a - pos_a, size_b - pos_b)` — simultaneous reverse rotation
- `mix1` cost: `pos_a + (size_b - pos_b)` — forward on `a`, reverse on `b`
- `mix2` cost: `(size_a - pos_a) + pos_b` — reverse on `a`, forward on `b`

**Complexity argument:**

- Each call to `find_cheapest` scans all `|a|` elements and for each calls `get_target_b_pos` which scans `|b|` → O(|a| × |b|) per call. Since `|a| + |b| = n`, this is O(n²) in the worst case.
- `find_cheapest` is called once per element pushed to `b`, so O(n) times total.
- However, what the push_swap model actually counts is **operations** (rotations + pushes), not comparisons. Each element pushed to `b` costs at most O(n/2) rotations in each stack. Over n elements: **O(n²) total operations**.
- The early exit (`if (min_ops == 0) break`) reduces average-case work but does not change the worst-case bound.
- Space: O(1) auxiliary (no extra data structures beyond the two stacks).

**Why O(n²) is acceptable for low disorder:**
At low disorder, most elements are already close to their target positions, so the average rotation cost per element is much lower than n/2. In practice, Turkish sort on nearly-sorted input performs well within the grading thresholds.

---

### 3. K-Sort (Chunk Sort) — O(n√n) — `--medium` flag

**How it works:**

1. **`push_to_b` — distribute by chunks**: the sorted index range `[0, n)` is processed incrementally. The chunk size is `(√n × 3) / 2 ≈ 1.5√n`. For each element at the top of `a`:
   - If its index is the next expected (`≤ i`): push to `b`, advance `i`.
   - If its index falls in the next chunk (`≤ i + chunk_size`): push to `b` and rotate to the back (`rb`), advance `i`.
   - Otherwise: rotate `a` forward (`ra`) and try the next element.
2. **`push_to_a` — reassemble in order**: elements are retrieved from `b` largest-first. For each target index (from `n-1` down to `0`), the stack is scanned to find its position, then rotated via `rb` or `rrb` (whichever is shorter) before pushing back to `a`.

**Complexity argument:**

- **`push_to_b`**: there are `O(n / chunk_size)` = `O(n / √n)` = `O(√n)` chunk boundaries. For each element, the loop may rotate `a` past elements that don't belong to the current chunk. Across all chunks, each element is rotated past at most once per chunk boundary it doesn't belong to. Total rotations across all elements and all chunks: O(n × √n) = **O(n√n)**.
- **`push_to_a`**: this phase processes elements in strictly decreasing index order. Because `push_to_b` fills `b` in chunk order (back of `b` = smallest, front = largest within each chunk), elements within each chunk of size `O(√n)` are already grouped. When retrieving element `k`, it is at most `O(√n)` positions away from the current top of `b` on average, since it is within its chunk. Over all n elements: `n × O(√n)` = **O(n√n)** average rotations.
- Total: **O(n√n)** in the push_swap operation model.
- Space: O(1) auxiliary.

**Why O(n√n) is appropriate for medium disorder:**
At medium disorder, elements are scattered enough that Turkish sort's per-element rotation cost grows significantly, but the input is not random enough to need the full machinery of a bitwise sort. Chunk sort groups elements into coarse buckets of size √n, reducing the average search cost per element without the overhead of multiple bitwise passes.

---

### 4. Radix Sort (LSD Bitwise) — O(n log n) — `--complex` flag

**How it works:**

1. **Assign indexes**: each element is mapped to its sorted rank (0 to n−1), bounding the bit width to `⌈log₂(n)⌉`.
2. **LSD passes**: for each bit position `i` from least to most significant, `process_a_bit` scans all elements in `a`:
   - Bit is `0` → push to `b`.
   - Bit is `1` → rotate to back of `a` (`ra`).
3. While elements are in `b`, `process_b_bit` speculatively processes bit `i+1` on `b` before pushing back to `a`, folding two bits into one round trip when the distribution is non-trivial.
4. A `pays_off` check skips any bit where all elements share the same value (no work needed).
5. After all bits are processed, any remaining elements in `b` are pushed back to `a`.

**Complexity argument:**

- There are `⌈log₂(n)⌉` bit positions to process.
- Each pass of `process_a_bit` and `process_b_bit` touches all n elements exactly once: n pushes/rotations to distribute, then n pushes to reassemble.
- The `process_b_bit` optimisation folds two bits into one round trip but does not change the number of passes: it processes bit `i+1` while elements are already in `b`, saving one full reassembly cycle. The number of passes remains bounded by `⌈log₂(n)⌉`.
- The `pays_off` skip reduces constant factors but does not change the asymptotic bound.
- Total: `⌈log₂(n)⌉ × O(n)` = **O(n log n) operations**.
- Space: O(1) auxiliary (distribution happens in-place between the two stacks).

**Why O(n log n) is appropriate for high disorder:**
At high disorder, greedy strategies pay a high and unpredictable rotation cost per element. Radix sort's operation count depends only on `n` and the bit width of the index — not on the input order — giving consistent, predictable performance regardless of how scrambled the input is.

---

## Adaptive Strategy

### Disorder Metric

The program computes a **disorder metric** at startup using pairwise inversion counting:

```
disorder = inversions / total_pairs
```

where `inversions` is the number of pairs `(i, j)` with `i < j` but `a[i] > a[j]`, and `total_pairs = n × (n−1) / 2`.

A value of `0.0` means the input is already sorted; `1.0` means it is fully reversed.

### Threshold Rationale

| Disorder | Strategy | Complexity |
|----------|----------|------------|
| < 0.2 | Turkish Sort | O(n²) |
| 0.2 – 0.5 | K-Sort | O(n√n) |
| ≥ 0.5 | Radix Sort | O(n log n) |

**Why these thresholds:**

- **Below 0.2**: fewer than 20% of pairs are inverted — the input is nearly sorted. Turkish sort's greedy insertion is highly efficient here because each element is already close to its target position. The O(n²) worst case is never approached; actual operation counts remain low.
- **0.2 to 0.5**: moderate disorder. Turkish sort's per-element rotation cost grows as elements stray further from their targets, making its quadratic behaviour increasingly costly. K-sort's chunk-based approach amortizes this cost by grouping elements into coarse buckets, achieving O(n√n) without the overhead of a full bitwise sort.
- **Above 0.5**: more than half of all pairs are inverted — the input is heavily scrambled. Greedy strategies pay a high rotation cost per element. Radix sort's O(n log n) bitwise passes are input-order-independent and provide the best guaranteed performance in this regime.

---

## Resources

### Sorting Algorithms & Theory

- [Wikipedia — Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Visualgo — Sorting visualizations](https://visualgo.net/en/sorting)
- [42 push_swap — The Turk Algorithm (Medium)](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Chunk sort / K-sort explanation (Stack Overflow discussions)](https://stackoverflow.com)

### 42 Project References

- [push_swap subject (42 official)](https://cdn.intra.42.fr/pdf/pdf/13196/en.push_swap.pdf)
- [push_swap tester — ft_ps_tester](https://pypi.org/project/ft-ps-tester/)

# Learner Contributions

This project was developed collaboratively by both learners, who are able to explain, defend, and maintain the entire codebase. While responsibilities were divided during development, all architectural and algorithmic decisions were discussed and reviewed together.

## guicarva

Primary responsibilities:

* Design and implementation of the Turkish Sort (greedy insertion strategy).
* Design and implementation of the K-Sort / Chunk Sort algorithm.
* Optimisation of the Radix Sort implementation.
* Performance analysis and benchmarking of sorting strategies.
* Additional algorithmic improvements and general optimisations throughout the project.
* Contributions to stack manipulation logic and sorting infrastructure.

## gfranca

Primary responsibilities:

* Design and implementation of the first Radix Sort version.
* Design and implementation of the Simple Sort strategy for small inputs.
* Creation and maintenance of the project README and documentation.
* Input validation and project organisation support.
* Additional implementations, refactoring work, and minor performance optimisations throughout the codebase.

## Shared Responsibilities

Both learners:

* Participated in project design discussions and algorithm selection.
* Reviewed and tested each other's code.
* Validated correctness and performance of all sorting strategies.
* Contributed to debugging, integration, and final project polishing.
* Understand and can explain the entire codebase, including all algorithms and supporting infrastructure.

### AI Usage

AI was used for documentation and clarification of some concepts. All decisions were made by the participants together.

---

## Project Structure

```
push_swap/
├── includes
│   └── push_swap.h
├── srcs
│   ├── checker.c
│   ├── free_and_check.c
│   ├── ft_printf.c
│   ├── ft_printf_utils.c
│   ├── ft_split.c
│   ├── get_next_line_utils.c
│   ├── make_stack.c
│   ├── o_push.c
│   ├── o_rotate.c
│   ├── o_rotate_r.c
│   ├── o_swap.c
│   ├── push_swap.c
│   ├── sort_k.c
│   ├── sort_radix.c
│   ├── sort_simple.c
│   ├── sort_turk.c
│   ├── sort_turk_utils.c
│   └── stack_utils.c
├── Makefile
└── README.md
```