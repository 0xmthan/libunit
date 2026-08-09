*This project has been created as part of the 42 curriculum by kaaltint, mtaheri.*

## Rush - libunit
🏃🏻

A micro test framework: each test runs in its own process, so a crash is a
result instead of the end of the run.

## Build & run

The mandatory and the bonus parts are two separate builds of `libunit.a`.

| command | what it does |
| --- | --- |
| `make` | builds the **mandatory** `libunit.a` |
| `make bonus` | builds the **bonus** `libunit.a` |
| `make test` | mandatory lib + `tests/` (demo) + `real-tests/` (get_next_line) |
| `make test_bonus` | bonus lib + `tests/bonus/` + `real-tests/` |
| `make clean` / `fclean` / `re` | usual rules (`fclean` also removes the `.log` files) |

Each rule rebuilds the archive from scratch and drops the other mode's stamp
file, so switching parts can never leave a stale object in `libunit.a`.
No optimization flags are used.

## Mandatory part

`launch_tests()` forks once per test. The child runs the test function and
`exit()`s with its return value; the parent `waitpid()`s and prints
`OK`, `KO`, `SIGSEGV` or `SIGBUS`, then the total. It returns `0` if every test
passed, `-1` otherwise.

```
$> make fclean && make test
DEMO: OK test : [OK]
DEMO: KO test : [KO]
DEMO: SEGV test : [SIGSEGV]
DEMO: BUS test : [SIGBUS]

1/4 tests checked
```

## Bonus part

| feature | where | test routine |
| --- | --- | --- |
| color output | `status_bonus.c` | `tests/bonus/color/` |
| stdout/stderr capture | `launch_tests_bonus.c` | `tests/bonus/output/` |
| timeout (`TIMEOUT_SEC`, default 5s) | `launch_tests_bonus.c` | `tests/bonus/timeout/` |
| SIGABRT / SIGFPE / SIGPIPE / SIGILL | `status_bonus.c` | `tests/bonus/signals/` |
| `[function_name].log` | `log_bonus.c`, `log_open_bonus.c` | `tests/bonus/log/` |

The routines are real assertions, not demonstrations: the stdout test writes a
marker and a second test reads `bonus_stdout.log` back to prove the marker was
captured instead of reaching the terminal; the log tests check the header, the
captured output and the `--> [OK]` status line inside `bonus_log.log`; the color
tests build one child per status class and assert `status_color()` returns green
for `OK`, yellow for `TIMEOUT` and red for a `KO` or a signal, plus a last one
checking `bonus_color.log` holds no escape sequence at all — the colors are for
the terminal, the log stays plain text. The
signal and timeout routines are *expected* to report `SIGxxx` / `TIMEOUT` — that
is what they are testing — so `make test_bonus` ends on a red count by design.

### Extra functions used, and why

- `fork` / `waitpid` — one process per test, so a crashing test cannot take the
  runner down. Every child is waited for, so no zombie is left behind.
- `pipe` / `dup2` — the child's `stdout` and `stderr` go into a pipe, so a
  function that writes still cannot pollute the runner's output; the parent
  drains the pipe straight into the log file.
- `alarm` — the timeout, armed in the child only: a hanging test dies from
  `SIGALRM` and is reported as `TIMEOUT`. Costs no extra process and needs no
  `kill`, which the subject forbids.
- `open` / `write` / `close` — the log file, written with raw `write` so each
  test is on disk before the next one starts.


## Resources
- [fork() in C - geeksforgeeks](https://www.geeksforgeeks.org/c/fork-system-call/)
- man fork, man alarm, man 2 wait

