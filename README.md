*This project has been created as part of the 42 curriculum by tguezala, wczarnom.*

# push_swap

## Description

`push_swap` sorts a list of integers using **two stacks** (`a` and `b`) and a
small set of operations (`sa sb ss pa pb ra rb rr rra rrb rrr`). The program does
not sort "in memory": it parses the input and **prints to `stdout` the sequence
of operations** that leaves stack `a` sorted in ascending order with the smallest
value on top.

The binary implements **four strategies** and chooses one at run time:

| Strategy | Class | Idea |
|----------|-------|------|
| Simple   | `O(n²)`      | Selection sort: extract the minimum into `b`, then pour it back. |
| Medium   | `O(n·√n)`    | Chunk sort: split into ranges of size ≈√n, then rebuild. |
| Complex  | `O(n·log n)` | LSD radix sort on the rank index (base 2). |
| Adaptive | mixed        | Picks Simple / Medium / Complex from the disorder index. |

## Instructions

```sh
make                      # builds ./push_swap  (cc -Wall -Wextra -Werror)
make clean / fclean / re

./push_swap 4 2 5 1 3               # default strategy (--adaptive)
./push_swap --simple  5 4 3 2 1
./push_swap --medium  "12 4 90 2"
./push_swap --complex $(shuf -i 1-1000 -n 500)
./push_swap --bench 4 2 5 1 3       # metrics on stderr, operations on stdout
```

Selectors: `--simple`, `--medium`, `--complex`, `--adaptive` (default).
`--bench` can be combined with any selector and writes to **stderr**:

```
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n sqrt n)
[bench] total_ops: 13
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 2 rb: 1 rr: 0 rra: 0 rrb: 0 rrr: 0
```

Errors (`Error\n` on stderr, exit code ≠ 0): non-integer arguments, values
outside the `int` range, duplicates, contradictory selectors, empty arguments.
With no arguments the program prints nothing and exits successfully.

## Disorder index and thresholds

The disorder index is computed with the subject's formula (inversions / total
pairs) **before** any move, in `stack_analysis.c:disorder_check`.

| Regime | Condition | Strategy chosen | Threshold rationale |
|--------|-----------|-----------------|---------------------|
| Low    | `d < 0.20` | Simple  | Few inversions ⇒ few useful extractions; the real operation count stays low even though the theoretical class is `O(n²)`. |
| Mid    | `0.20 ≤ d < 0.50` | Medium | The √n-chunk split amortises the cost: each element enters and leaves `b` once, plus a bounded local reordering → `O(n·√n)`. |
| High   | `d ≥ 0.50` | Complex (radix) | Essentially random input: radix does `⌈log2(n)⌉` passes of `O(n)` → `O(n·log n)`, independent of the disorder. |

`adaptive_sort.c` uses strict inequalities (`disorder < 0.2f`, then
`disorder < 0.5f && disorder > 0.2f`), so a disorder of exactly `0.20` matches
neither Low nor Mid and falls through to Complex. If you'd rather have `0.20`
land in Mid as the table used to imply, change the second condition to
`disorder <= 0.2f` — the code and this table now agree on the current,
as-shipped behaviour.

The cuts `0.2` and `0.5` are **our own design choice**, not values mandated by
the 42 subject. `0.5` is the expected disorder of a random permutation (each
pair is inverted with probability ½), and `0.2` is roughly where the chunk
sort stops paying off compared to plain minimum extraction.

## Complexity bounds (push_swap model)

| Strategy | Operations (worst case) | Extra space |
|----------|-------------------------|-------------|
| Simple  | `O(n²)`      | `O(1)` (pointers only) |
| Medium  | `O(n·√n)`    | `O(1)` (the two given stacks) |
| Complex | `O(n·log n)` | `O(1)` |
| Adaptive| max of the chosen branch | `O(1)` |

## Project structure

```
push_swap/
├── Makefile                 all / clean / fclean / re / $(NAME)
├── README.md
├── push_swap.h              types (t_node, t_op, enum t_opid), macros, prototypes
│
├── main.c                   argv handling and main flow
│
├── input handling
│   ├── parsing.c            parse_int (no exit on error), has_duplicate
│   └── flag_detector.c      --simple / --medium / --complex / --adaptive / --bench
│
├── generic helpers
│   ├── ft_string.c          ft_strlen, ft_strncmp, ft_strdup, ft_substr
│   ├── ft_split.c           ft_split
│   ├── lst_utils.c          doubly linked list: new / add_back / size / last
│   └── free_utils.c         free_stack, free_split
│
├── stack helpers
│   ├── stack_utils.c        size, max bits, minimum, node position, move_to_top
│   └── stack_analysis.c     assign_index, disorder_check, ft_is_sorted
│
├── operations
│   ├── op_utils.c           init_op (resets flag/complexity/bench/disorder/counters)
│   ├── swap.c               sa, sb, ss
│   ├── push.c               pa, pb
│   ├── rotate.c             ra, rb, rr
│   └── reverse_rotate.c     rra, rrb, rrr
│
├── benchmark (--bench, stderr)
│   ├── bench.c              print_bench_results
│   └── bench_utils.c        ft_putnbr_fd, labels, disorder %, class names
│
└── sorting
    ├── sort_stack.c         dispatcher: reads op->flag, sets op->complexity
    ├── sort_small.c         hard-coded sort for 2..5 elements
    ├── sort_simple.c        Simple   — selection sort            O(n²)
    ├── sort_medium.c        Medium   — √n chunk sort             O(n·√n)
    ├── radix_sort.c         Complex  — LSD radix sort            O(n·log n)
    └── adaptive_sort.c      Adaptive — picks one by disorder index
```

### Data flow

```
argv ──► parsing / flag_detector ──► doubly linked list (stack a)
     ──► assign_index (rank each value 0..n-1)
     ──► disorder_check (store op->disorder)
     ──► sort_stack ──► (forced flag) sort_simple / sort_medium / radix_sort
                   └──► (default)     adaptive_sort ──► one of the above / sort_small
     ──► each of the 11 operation functions (sa/sb/ss/pa/pb/ra/rb/rr/rra/rrb/rrr)
         writes "xx\n" to stdout and increments op->count[OP_*] and op->total itself
     ──► if --bench: print_bench_results to stderr
     ──► free_stack(a), free_stack(b)
```

## Memory management

- All heap memory belongs to the linked list and to `ft_split`.
- `ft_split` is freed after each `argv[i]` is processed (and on the error path).
- Parsing **does not call `exit()`**: `parse_int` returns `0`, the error
  propagates up to `main`, which frees the stack before printing `Error`.
- `main` frees `a` and `b` before returning.
- Checked with AddressSanitizer / LeakSanitizer and `valgrind --leak-check=full`.

## Resources

- Jamie Dawson, Push_Swap: The least amount of moves with two stacks, Medium — selection-style "push the current minimum to b" approach used by the Simple strategy: https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
- Julien C., Push_Swap: An Easy and Efficient Sorting Algorithm, Medium — the chunk / bucket sort used by the Medium strategy (split the value range into chunks, push to b, pull back largest first): https://medium.com/@julien-ctx/push-swap-an-easy-and-efficient-algorithm-to-sort-numbers-4b7049c2639a
- GeeksforGeeks, Radix Sort — general background on LSD (least-significant-digit) radix sort: https://www.geeksforgeeks.org/dsa/radix-sort/. It's the classic base-10, in-array version with a counting-sort bucket step, not the two-stack, base-2, zero-extra-memory adaptation used in radix_sort.c — useful for the underlying concept, not for how the Complex strategy is actually implemented here.

### Contributions

Main flow, structural decisions and testing: both contributors.
- **tguezala** — parsing, disorder index and radix sort.
- **wczarnom** — operations and sorts: small, simple and medium.