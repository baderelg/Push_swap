<p align="center">
  <img src="https://i.imgur.com/F5tg1nq.png" alt="Kaze">
</p>

> *“One little slip can leave you wide open... Remember that.”*

The goal of the Bonus part of the mission is to mimic the checker that is provided by 42.

## 🪭 Subject expectations

The `checker` is the referee for Push_swap.

You first feed it the initial stack (`a`) and then a sequence of operations (`sa` `pa` `rrr` for example) via the standard input (STDIN).

It **silently** simulates that sequence of operations and tells you whether:
- OK, `a` is sorted and `b` is empty
- KO, otherwise

If you give it any invalid input or unknown operations, it stops and prints an error.

- Clean parsing (the same one from push_swap is re-used)

- Read lines from STDIN until end of input.\
Each line must therefore be exactly one valid operation with a trailing newline, like **"sa\n"**

- Only simulate.\
Operations must be applied to the stacks without printing, so Wrappers is a strict NO

## 🍃 Kirikiri Mai

> *"A sharp wind always carries the stacks into order"*

### 1. Lay the ground (<a href="https://github.com/baderelg/Push_swap/blob/main/bonus/checker_bonus.c">checker.c</a>)

- Initialize `a` and `b`
- If no arguments were received, return without doing anything
- Parse the arguments into the stack `a` (same parsing as push_swap)

### 2. Read the instructions (<a href="https://github.com/baderelg/Push_swap/blob/main/bonus/get_instructions_bonus.c">get_instructions.c</a>)

- Start pulling lines from STDIN with `get_next_instruction(0)`
- This function reads byte by byte until it sees `\n`\
At which point, it returns the full line (while including the newline)\
If it receives a `\0` it returns NULL immediately

> [!TIP]
> `get_next_instruction` is a bit like another 42 project: [Get_next_line](https://github.com/baderelg/Get_next_line)\
> Re-using the same get_next_line from the curriculum is fine but be careful, as it doesn't distinguish between EoF and an empty line\
> Indeed, it returns `NULL` in both cases
> An empty line should however trigger an Error

### 3. Dispatch the moves (<a href="https://github.com/baderelg/Push_swap/blob/main/bonus/dispatcher_bonus.c">dispatcher.c</a>)

- Have a little peek at the first character in `apply_instructions`
	- If it starts with `p` then it must be **"pa"** or **"pb"**
	- If it starts with `s` then it must be **"sa"**, **"sb"** or **"ss"**
	- If it starts with `r` then it must be **"ra"**, **"rb"**, **"rr"**, **"rra"**, **"rrb"** or **"rrr"**\
Forward it to the appropriate dispatcher. If none matches then it's an invalid instruction

- Each dispatcher checks if the string is valid (and has a trailing newline) like **"pa\n"**\
The helper function `is_valid_instruction` returns true only when both strings end at the same time (so a perfect match)

- If the string is valid, then it **silently** does the operation

### 4. Verdict

After going through all the lines that were given in the command line interface, the program simply checks if `a` is sorted and `b` is empty.\
It writes OK or KO accordingly, and then frees both stacks and exits.

> *"My fan doesn't forgive sloppy swings, and neither should the checker."*