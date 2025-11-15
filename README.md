<p align="center">
  <img src="https://i.imgur.com/ptjgah3.png" width="150" alt="Minitalk Badge With Bonus">
</p>

<div align="center">

[![42 School](https://img.shields.io/badge/Paris-blue?logo=42&logoColor=fff)](https://42.fr/en/homepage/)
[![Bonus](https://img.shields.io/badge/✔️_Bonus-5cb85c)](https://github.com/baderelg/Minitalk) \
<img src="https://i.imgur.com/HTci8UV.png" width="100" alt="Validation confirmation on the 42 Intra @baelgadi - Oct 11th 2025"> \
[![Validation date](https://img.shields.io/date/1760191200?label=&style=for-the-badge&color=5cb85c)](https://github.com/baderelg/Push_swap)

</div>

> [!NOTE]
> <details>
> <summary><strong>What is 42?</strong></summary>
>
> > [42 School](https://42.fr/en/homepage/) is a coding school focused on peer to peer learning and being project driven. \
> > We are given a project, a set of rules and clear objectives, and then it's up to us to figure out how to achieve the goal. \
> > It pushes to learn how to learn. It may be intense and sometimes frustrating but the sense of accomplishment makes everything worth it. \
> > Short term comfort is thus sacrificed for long term growth and versatility.
> </details>
>
> <details>
> <summary><strong>What is Push_swap?</strong></summary>
>
> > Push_swap is an algorithm challenge.\
> > The main goal is to sort a stack of integers using only a small set of operations as the program can only manipulate two stacks (a and b) using 11 types of operations in total: swaps, pushes and rotations.\
> > There are also requirements to fulfill, so the program should minimize the number of moves.\
> > Thus, the real lesson in this project is complexity and mastery of heuristic techniques.
> </details>
>
> To make the journey entertaining, I chose to approach the project through the eyes and voice of a fictional character.
>
> <details>
> <summary><strong>Why ?</strong></summary>
>
> > Embodying a character while tackling a project isn't just entertaining, it forges stronger connections with the logic and makes it way more engaging.</br>
> > When you try expressing what you just learned with the voice of a fictional character, it helps cementing the newly acquired knowledge and even adds new perspectives.</br>
> >
> </details>
> <details>
> <summary><strong>Why Shikamaru?</strong></summary>
>
> > Push_swap is strategy under pressure. Minimal effort, maximum efficiency.\
> > The algorithm used in here is kind of lazy, so it makes sense... "What a drag" and yet, the mission must be carried out.
> </details>

---

<p align="center">
  <img src="https://i.imgur.com/ElJQiZ8.png" alt="What a drag...">
</p>

> *“What a drag... Let's finish this quickly."*

Wasting energy is troublesome and I'd rather stare at the clouds.

Still... Time to get serious. Here is my **Lazy Turk with sliding windows**, get ready.

# ♟️ The rules

Before any strategy or plan, know the board.

You have two [stacks](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) named `a` and `b`.
- The stack `a` contains a random list of unique integers
- The stack `b` is empty

The goal is to sort the numbers in `a` in ascending order, so the smallest on top.\
<ins>The 11 allowed moves are the following:</ins>

<table align="center">
<tr>
    <th align="center"><code>pa</code></th>
    <td align="center"><b>push a</b>, take the element on top of `b` and put it at the top of `a`</td>
  </tr>
  <tr>
    <th align="center"><code>pb</code></th>
    <td align="center"><b>push b</b>, take the element on top of `a` and put it at the top of `b`</td>
  </tr>
  <tr>
    <th align="center"></th>
	<th align="center"></th>
  </tr>
  <tr>
    <th align="center"><code>sa</code></th>
    <td align="center"><b>swap a</b>, swap the 2 first elements on top of `a`</td>
  </tr>
  <tr>
    <th align="center"><code>sb</code></th>
    <td align="center"><b>swap b</b>, swap the 2 first elements on top of `b`</td>
  </tr>
  <tr>
    <th align="center"><code>ss</code></th>
    <td align="center"><b>swap a</b> and <b>swap b</b> at the same time</td>
  </tr>
  <tr>
    <th align="center"></th>
	<th align="center"></th>
  </tr>
  <tr>
    <th align="center"><code>ra</code></th>
    <td align="center"><b>rotate a</b>, the first element of `a` becomes the last</td>
  </tr>
  <tr>
    <th align="center"><code>rb</code></th>
    <td align="center"><b>rotate b</b>, the first element of `b` becomes the last</td>
  </tr>
  <tr>
    <th align="center"><code>rr</code></th>
    <td align="center"><b>rotate a</b> and <b>rotate b</b> at the same time</td>
  </tr>
  <tr>
    <th align="center"></th>
	<th align="center"></th>
  </tr>
  <tr>
    <th align="center"><code>rra</code></th>
    <td align="center"><b>reverse rotate a</b>, the last element of `a` becomes the first</td>
  </tr>
  <tr>
    <th align="center"><code>rrb</code></th>
    <td align="center"><b>reverse rotate b</b>, the last element of `b` becomes the first</td>
  </tr>
  <tr>
    <th align="center"><code>rrr</code></th>
    <td align="center"><b>reverse rotate a</b> and <b>reverse rotate b</b> at the same time</td>
  </tr>
</table>


Each instruction is a special jutsu.

- **Swap** is a quick micro correction
- **Push** is used to switch elements between `a` and `b`
- **Rotate** cycles the stack and exposes the right element at the very top
- **Reverse rotate** cycles in the opposite direction

The shortest path matters. If an element is nearer the top it must be rotated up.\
Near the bottom? Reverse rotate.

## 💻 The program

- The Push_swap program should take as argument(s) the list of integers and parse it accordingly.
- It must display each operation on the standard output.
- If already sorted, it should print nothing.
- On error, it should print "Error\n" on the standard error.
- No global variables, no leaks, and respect the norm of 42.
- Allowed functions are: read, write, malloc, free, exit & [libft](https://github.com/baderelg/Libft) is authorized (although it's not used here).

To validate with a 100% score, the number of moves is:
- Sort `100` numbers in under 700 moves **(< 700)**
- Sort `500` numbers in 5500 moves or less **(<= 5500)**

## 🪖 Parsing the battlefield

> *"Strategy begins before the first move."*

Yeah I know. Parsing is boring, but it's essential.

It doesn't matter how good the algorithm is if the parsing isn't perfect.\
The input must be correctly checked and shaped into a proper stack.

### ➢ Tokenizing the inputs

Arguments can arrive in the following forms:
- **Separated**
```
./push_swap 42 13 37 21
```
- **Grouped**
```
./push_swap "42 13 37 21"
```
- **Mixed**
```
./push_swap "42" "13 37 21"
```

So I scan each argument character by character and I cut a token whenever I meet a whitespace.\
Whitespaces in ASCII are `32` (space), `9` (tab), `10` (newline), `11` (vertical tab), `12` (form feed) and `13` (carriage return)

⚠️ <ins>Cases that should be dealt with as errors:</ins>

- Empty arguments `""`
- Only whitespace arguments `" "` 

### ➢ Valid numbers

- Each token must contain at least one digit
- The sign is optional but it must be directly before the digits

<table align="center">
<tr>
	<th align="center">✅</th>
	<td align="center">"0005" = <code>5</code></td>
	<td align="center">"-0005" = <code>-5</code></td>
	<td align="center">"-0" = <code>0</code></td>
</tr>
<tr>
	<th align="center">❌</th>
	<td align="center">"---1"</td>
	<td align="center">"+ 1"</td>
	<td align="center">"0x10"</td>
</tr>
</table>

⚠️ <ins>Overflow must be dealt with:</ins>

Every number must fit in a 32-bit signed integer.\
At each step I check if adding the next digit would break the int boundaries (`INT_MIN` to `INT_MAX`)

### ➢ Building the stack

Numbers must be appended to the tail of our linked list so that the first argument ends up on top of the stack.

<ins>Example</ins>
```c
./push_swap 42 13 37 21
```
Stack `a` after parsing:
```c
42 | 13 | 37 | 21
```

⚠️ <ins>Duplicates should be detected</ins>

The subject strictly forbids duplicates: The values must be unique.
It means that something like `./push_swap 42 13 37 21 42` should be treated as an error.

# ♟️ Dual path no jutsu

> *"Plan it once and you won't have to think again."*

Sorting stacks is like shogi.\
When the board is small you just finish it with the quickest moves without overthinking: that's `ez_sort`.\
But when the board is crowded, don't rush. Break it into zones and control the field step by step.\
Always think a few steps ahead, chunk by chunk in `turk_sort`.

## 🥱 The power of laziness (`ez_sort` - Small inputs)

If the stack is tiny (2-5 elements), why waste too much effort?\
Just pick the shortest path.

### ➢ 2 elements

With just 2 numbers, there are only two possible scenarios.
- They are already sorted
- They are reverse (one `sa` and it's fixed)

One glance, one move and back to my nap.

### ➢ 3 elements

Now things are getting slightly more serious. But really, not that much.

<table align="center">

  <tr>
    <td align="center">There are <code>3!</code> (6) permutations, but one of those is already sorted, so I'll just have to deal with 5 cases<br><br>
	<ins><b>CASE 0</b></ins><br>
	Already sorted, ty<br>
	<ins>Example</ins> ✔️ 2 | 5 | 7
	</td>
  </tr>
  <tr>
    <td align="center"><ins><b>CASE 1</b></ins><br>
	Third > First > Second<br>
	<ins>Example</ins> 5 | 2 | 7<br><br>
	<b>➤ swap a</b><br>
	✔️ 2 | 5 | 7
	</td>
  </tr>
  <tr>
    <td align="center"><ins><b>CASE 2</b></ins><br>
	First > Second > Third<br>
	<ins>Example</ins> 7 | 5 | 2<br><br>
	<b>➤ swap a</b><br>
	5 | 7 | 2<br>
	<b>➤ reverse rotate a</b><br>
	✔️ 2 | 5 | 7
	</td>
  </tr>
  <tr>
    <td align="center"><ins><b>CASE 3</b></ins><br>
	First > Third > Second<br>
	<ins>Example</ins> 7 | 2 | 5<br><br>
	<b>➤ rotate a</b><br>
	✔️ 2 | 5 | 7
	</td>
  </tr>
  <tr>
    <td align="center"><ins><b>CASE 4</b></ins><br>
	Second > Third > First<br>
	<ins>Example</ins> 2 | 7 | 5<br><br>
	<b>➤ swap a</b><br>
	7 | 2 | 5<br>
	<b>➤ rotate a</b><br>
	✔️ 2 | 5 | 7
	</td>
  </tr>
  <tr>
    <td align="center"><ins><b>CASE 5</b></ins><br>
	Second > First > Third<br>
	<ins>Example</ins> 5 | 7 | 2<br><br>
	<b>➤ reverse rotate a</b><br>
	✔️ 2 | 5 | 7
	</td>
  </tr>
</table>

### ➢ 4-5 elements

The trick is to remove the smallest distractions first, and then end up with just a manageable 3-elements stack.

This is my lazy-efficient technique:

1. Find the minimum value in `a`
2. Rotate or reverse-rotate to bring it on top (calculate the one that costs fewer moves)
3. Push it to stack `b`
4. If we started with 5 elements, re-do steps 1 to 3 one last time
5. And here I am back to a smaller problem with merely 3 numbers, so I'll just re-use the same tactic from the previous section
6. I bring back the numbers by pushing them from `b` to `a`

>[!TIP]
> For the 5-stack scenario: by pushing the minimum first, and then the next smaller one, I ensure that in stack `b` the bigger one is on top. Thus, when pushing back to `a`, it pushes the biggest one first.

The stack is now perfectly sorted with no wasted effort.\
For ≤5 elements, these moves are always optimal as they guarantee the smallest possible number of operations.

## 𖣘 The power of chunks (`turk_sort` - Large inputs)

> *"The problem is the world won't let me ez_sort forever, so I can't lie around crying about it either."*

<p align="center">
  <img src="https://i.imgur.com/xbqOUNj.png" alt="The will of Chunks">
</p>


When the stack grows beyond the 5 elements, hardcoding all possibilities won't do the trick.\
Imagine memorizing every possible shogi game from start to end. I mean... what a drag.

So instead, let's be pragmatic and use [heuristics](https://en.wikipedia.org/wiki/Heuristic): break the problem into manageable chunks and handle them one at a time.\
Basically, divide and conquer.

### ➢ Step 1, preparing the battlefield

First, I copy the values from stack a into a new array, then sort it with a simple bubble sort.\
This is the [`create_sorted_array`](https://github.com/baderelg/Push_swap/blob/main/mandatory/sorting/turk_sort.c) function.
- This array is kind of a cheat sheet that shows the true final order of the numbers, without me doing anything yet
- With it, I can easily check if a value belongs in the current zone I'm working in, without searching blindly

If that talking about "zone" is confusing, don't worry, it will all make sense.

### ➢ Step 2, defining the windows (zones)

Instead of pushing numbers one by one (which would cause tons of unnecessary rotations), let's group them into **windows** (or chunks).

<table align="center">
	<tr>
	<th align="center">Input of size <= 100</th>
	<td align="center"><code>Windows size</code> = 15</td>
	</tr>
	<tr>
	<th align="center">Input of size > 100</th>
	<td align="center"><code>Windows size</code> = 35</td>
	</tr>
</table>

Why `15` and `35`? It's all about testing and finding the perfect practical values.
- If the chunks are too small, I waste too many moves pushing constantly
- If the chunks are too big, the control is lost and I pay the price when I need to push back

Remember the benchmarks, you need to use values that guarantee under 700 moves for 100 numbers and 5500 moves or under for 500 numbers.\
With my tests, the best results came from using the 15/35 window (15/40 came in close), but to each their own, as long as it's balanced.

### ➢ Step 3, sweeping the values from `a` to `b`

And now the main event: pushing the chunks into `b`.

While looping through stack `a`, I check for each top element its index in my sorted array (step 1).\
And then, 3 possible scenarios:

**1. The index is inside the current window** ∈ [lower bound ... upper bound]
- Simply push it to `b`

**2. The index is inside the window AND smaller than the lower bound** < lower bound
- Push it to `b`
- Rotate `b` to bury the small value deeper
This keeps the bigger numbers near the top of b, which is exactly what we want, because just like in `ez_sort`, having the biggest numbers on top of B helps us when pushing back to a: we first push the big numbers and then put the smaller ones on top.

**3. The index is outside the current window** > upper bound
- Rotate `a` to move the element down. We'll deal with it later.

I repeat this process until the whole window has been evacuated to `b`.\
And then, I increase the window bound and move on until stack `a` is completely empty.

### ➢ Step 4, pulling back

At this stage `a` is empty and `b` contains all the numbers, but not in perfectly sorted order.\
And the task is to rebuild `a` in order. How ?\
Always pull the current maximum from `b`.

1. Use the function `find_pos` to locate the current maximum value in `b`
2. Use `move_to_top` to bring it to the top
- If the position is in the top half, rotate
- If it's in the bottom half, reverse rotate
3. Once the max is on top, simply push to a

This is repeated until `b` is empty, at which point `a` is neatly and perfectly sorted.

### ➢ Step 5, lay back and watch the clouds

The windows shrink the search area and the laziness avoids overrotations.\
And I can rest my cloud envy.

This algorithm isn't the perfect one, but it's simple and efficient enough to pass through all the benchmarks.

# ♟️ Visualization

## 🕳️ Phase 1: Shadow scattering

Let's say stack `a` is:
```c
4 | 1 | 9 | 6 | 2 | 8 | 10 | 7 | 3 | 42
```

The sorted array I'm creating will be:
```diff
1, 2, 3, 4, 6, 7, 8, 9, 10, 42
> Indexes (positions) 0 1 2 3 4 5 6 7 8 9
```

- `Window size = 5` and windows are always [i, i +1, ..., i + 5 - 1]
- At the start the lower bound is `i = 0` thus making `4` the upper bound index

The first window is: **[ 0, 1, 2, 3, 4 ]** (pos) meaning [1, 2, 3, 4, 6] in real values.

<p align="center">
  <img src="https://i.imgur.com/A2yPuBY.png">
</p>

### 🚩 STEP 1

- **Top of `a` = 4**
	- Index of 4 in the sorted array = 3
	- 3 ∈ [0...4] so it's inside the current window
	- `pb` push it to b
	- i++<br>
<ins>Now:</ins>
```c
a: 1 | 9 | 6 | 2 | 8 | 10 | 7 | 3 | 42
b: 4

i = 1
New window = [1, 2, 3, 4, 5] (positions)
```

---

### 🚩 STEP 2

- **Top of `a` = 1**
	- Index(1) is 0
	- 0 is outside the [1...5] range BUT below the lower bound (1) so it must be one of the smallest possible values
	- `pb` push it to b
	- then `rb` to bury it down in b
	- i++<br>
<ins>Now:</ins>
```c
a: 9 | 6 | 2 | 8 | 10 | 7 | 3 | 42
b: 4 | 1

i = 2
New window = [2, 3, 4, 5, 6]
```

---


### 🚩 STEP 3

- **Top of `a` = 9**
	- Index(9) is 7
	- 7 is above the window [2...6]
	- `ra` rotate `a` and we'll deal with it later<br>
<ins>Now:</ins>
```c
a: 6 | 2 | 8 | 10 | 7 | 3 | 42 | 9
b: 4 | 1

i = 2
Unchanged window = [2, 3, 4, 5, 6]
```

---

### 🚩 STEP 4

- **Top of `a` = 6**
	- Index(6) is 4
	- 4 is inside the window [2...6]
	- `pb` push it to b
	- i++<br>
<ins>Now:</ins>
```c
a: 2 | 8 | 10 | 7 | 3 | 42 | 9
b: 6 | 4 | 1

i = 3
New window = [3, 4, 5, 6, 7]
```

---

### 🚩 STEP 5

- **Top of `a` = 2**
	- Index(2) is 1
	- 1 is below the lower bound from the window [3...7]
	- `pb` push it to b
	- `rb` rotate to bury it
	- i++<br>
<ins>Now:</ins>
```c
a: 8 | 10 | 7 | 3 | 42 | 9
b: 6 | 4 | 1 | 2

i = 4
New window = [4, 5, 6, 7, 8]
```

---

### 🚩 STEP 6

- **Top of `a` = 8**
	- Index(8) is 6
	- 6 ∈ [4 ... 8]
	- `pb`
	- i++<br>
<ins>Now:</ins>
```c
a: 10 | 7 | 3 | 42 | 9
b: 8 | 6 | 4 | 1 | 2

i = 5
New window = [5, 6, 7, 8, 9]
```

---

### 🚩 STEP 7

- **Top of `a` = 10**
	- Index(10) is 8
	- 8 ∈ [5 ... 9]
	- `pb`
	- i++<br>
<ins>Now:</ins>
```c
a: 7 | 3 | 42 | 9
b: 10 | 8 | 6 | 4 | 1 | 2

i = 6
New window = [6, 7, 8, 9, 10]
```
>[!TIP]
> Wait what ? 10 ? But the array only goes up to index 9.\
> That's where this condition is used:
> ```c
> if (upper >= size)
>	upper = size - 1;
> ```
> So upper is brought down from 10 to 9: `10 - 1 = 9`.\
> Therefore the real window is **[6, 7, 8 , 9]**

---

### 🚩 STEP 8

- **Top of `a` = 7**
	- Index(7) is 5
	- 5 is below the lower bound of [6 ... 9]
	- `pb`
	- `rb`
	- i++<br>
<ins>Now:</ins>
```c
a: 3 | 42 | 9
b: 10 | 8 | 6 | 4 | 1 | 2 | 7

i = 7
New window = [7, 8, 9, 10, 11] // but really [7, 8, 9]
```

---

### 🚩 STEP 9

- **Top of `a` = 3**
	- Index(3) is 2
	- 2 is below the lower bound of [7 ... 9]
	- `pb`
	- `rb`
	- i++<br>
<ins>Now:</ins>
```c
a: 42 | 9
b: 10 | 8 | 6 | 4 | 1 | 2 | 7 | 3

i = 8
New window = [8, 9, 10, 11, 12] // but really [8, 9]
```

---

### 🚩 STEP 10

- **Top of `a` = 42**
	- Index(42) is 9
	- 9 ∈ [8, 9]
	- `pb`
	- i++<br>
<ins>Now:</ins>
```c
a: 9
b: 42 | 10 | 8 | 6 | 4 | 1 | 2 | 7 | 3

i = 9
New window = [9, 10, 11, 12, 13] // but really just 9
```

---

### 🚩 STEP 11

- **Top of `a` = 9**
	- Index(9) is 7
	- 7 is below the lower bound which is 9
	- `pb`
	- `rb`
	- i++<br>
<ins>Now:</ins>
```c
a: 
b: 42 | 10 | 8 | 6 | 4 | 1 | 2 | 7 | 3 | 9

i = 10
a is now empty
```

---

## 🥷🏿 Phase 2: Retrieval

The task is simple:

- At each step, find the current maximum in `b`
- Rotate or reverse rotate `b`, whichever is the shortest path, until the max is on top
- Push it to `a`
- Repeat until `b` is empty

When starting:
```c
b: 42 | 10 | 8 | 6 | 4 | 1 | 2 | 7 | 3 | 9
```

<p align="center">
  <img src="https://i.imgur.com/A2yPuBY.png">
</p>

### 🚩 STEP 1

- Max = 42
	- Already on top of `b`
	- `pa` to push it to a<br>
<ins>Now:</ins>
```c
a: 42
b: 10 | 8 | 6 | 4 | 1 | 2 | 7 | 3 | 9
```

---

### 🚩 STEP 2

- Max = 10
	- Already on top of `b`
	- `pa` to push it to a<br>
<ins>Now:</ins>
```c
a: 10 | 42
b: 8 | 6 | 4 | 1 | 2 | 7 | 3 | 9
```

---

### 🚩 STEP 3

- Max = 9
	- Position is at the bottom of `b`
	- Shortest path is `rrb` once (b is now `9 | 8 | 6 | 4 | 1 | 2 | 7 | 3`)
	- `pa` to push it to a<br>
<ins>Now:</ins>
```c
a: 9 | 10 | 42
b: 8 | 6 | 4 | 1 | 2 | 7 | 3
```

---

### 🚩 STEP 4

- Max = 8
	- Already on top of `b`
	- `pa` to push it to a<br>
<ins>Now:</ins>
```c
a: 8 | 9 | 10 | 42
b: 6 | 4 | 1 | 2 | 7 | 3
```

---

### 🚩 STEP 5

- Max = 7
	- Position is 5th element of `b`
	- Distance from top = 4, from bottom = 2, so the shortest path is `rrb` twice
	- `pa` to push it to a<br>
<ins>Now:</ins>
```c
a: 7 | 8 | 9 | 10 | 42
b: 3 | 6 | 4 | 1 | 2
```

---

### 🚩 STEP 6

- Max = 6
	- Position is 2nd element of `b`
	- Distance from top = 1, from bottom = 4, so the shortest path is `rb` once
	- `pa` to push it to a<br>
<ins>Now:</ins>
```c
a: 6 | 7 | 8 | 9 | 10 | 42
b: 4 | 1 | 2 | 3
```

---

### 🚩 STEP 7

- Max = 4
	- already on top of `b`
	- `pa` to push it to a<br>
<ins>Now:</ins>
```c
a: 4 | 6 | 7 | 8 | 9 | 10 | 42
b: 1 | 2 | 3
```

---

### 🚩 STEP 8

- Max = 3
	- at the very bottom of `b`
	- shortest is `rrb` once
	- `pa` to push it to a<br>
<ins>Now:</ins>
```c
a: 3 | 4 | 6 | 7 | 8 | 9 | 10 | 42
b: 1 | 2
```

---

### 🚩 STEP 9

- Max = 2
	- at the very bottom of `b`
	- shortest is `rrb` once
	- `pa` to push it to a<br>
<ins>Now:</ins>
```c
a: 2 | 3 | 4 | 6 | 7 | 8 | 9 | 10 | 42
b: 1
```

---

### 🚩 STEP 10

- Max = 1
	- only element of `b`
	- `pa` to push it to a<br>
<ins>Now:</ins>
```c
a: 1 | 2 | 3 | 4 | 6 | 7 | 8 | 9 | 10 | 42
b: (empty)
```

And here it is, `a` is now perfectly sorted.\
The same logic applies on a much larger scale, as the logic is the same no matter how many chunks there are.

# ♟️ The way of the Shinobi

## 📐 Code architecture

> *"I know I usually seem like a pretty lazy guy, but not today. Because now, I'm responsible for all the files too."*

<table align="center">
	<tr>
	<th align="center"><a href="https://github.com/baderelg/Push_swap/blob/main/mandatory/push_swap/push_swap.c">push_swap.c</a></th>
	</tr>
	<tr>
		<td>- Parse arguments<br>
		- If already sorted, exit quietly<br>
		- If size is 5 or under, use <code>ez_sort</code>, else use <code>turk_sort</code><br>
		- Free everything and exit</td>
	</tr>
</table>

<table align="center">
	<tr>
	<th align="center"><a href="https://github.com/baderelg/Push_swap/blob/main/mandatory/parsing/parsing.c">parsing.c</a></th>
	</tr>
	<tr>
		<td>		<code>parse_args</code> builds the initial stack with a call to <code>append_stack</code><br>
		<ins>Helper functions:</ins><br>
		- <code>is_space</code> handles whitespaces<br>
		- <code>parse_number</code> handles numbers and deals with overflow accordingly<br>
		- <code>parse_value</code> tokenizes values inside each argument<br>
		- <code>has_duplicate</code> handles duplicates (exit with error)<br>
		- Free everything and exit</td>
	</tr>
</table>

<table align="center">
	<tr>
	<th align="center"><a href="https://github.com/baderelg/Push_swap/blob/main/mandatory/utils/stack_utils.c">stack_utils.c</a></th>
	</tr>
	<tr>
		<td><code>stack_len</code> calculates the number of nodes<br>
		- <code>is_sorted</code> checks if the list is already sorted (for early exit)<br>
		- <code>append_stack</code> appends a new node at the end of the stack<br>
		- <code>free_stack</code> safely cleans up<br>
		</td>
	</tr>
</table>

<table align="center">
	<tr>
	<th align="center"><a href="https://github.com/baderelg/Push_swap/blob/main/mandatory/utils/utils.c">utils.c</a></th>
	</tr>
	<tr>
		<td><code>bubble_sort_array</code> sorts the array that we will use to determine positions<br>
		- <code>error_exit</code> prints the error message, frees the stacks and exits<br>
		</td>
	</tr>
</table>

<table align="center">
	<tr>
	<th align="center"><a href="https://github.com/baderelg/Push_swap/blob/main/mandatory/utils/operations.c">operations.c</a></th>
	</tr>
	<tr>
		<td>All the possible operations: <code>push_stack</code> <code>swap_stack</code> <code>rotate_stack</code> <code>reverse_rotate_stack</code>
		</td>
	</tr>
</table>

<table align="center">
	<tr>
	<th align="center"><a href="https://github.com/baderelg/Push_swap/blob/main/mandatory/wrappers/wrapper_a.c">wrapper_a.c</a> <a href="https://github.com/baderelg/Push_swap/blob/main/mandatory/wrappers/wrapper_b.c">wrapper_b.c</a> <a href="https://github.com/baderelg/Push_swap/blob/main/mandatory/wrappers/wrapper_both.c">wrapper_both.c</a></th>
	</tr>
	<tr>
		<td>Wrappers that call the operations and print the instructions ("pa\n", "sa\n" etc)<br>
		This is especially useful for the bonus part
		</td>
	</tr>
</table>

<table align="center">
	<tr>
	<th align="center"><a href="https://github.com/baderelg/Push_swap/blob/main/mandatory/sorting/ez_sort.c">ez_sort.c</a></th>
	</tr>
	<tr>
		<td><code>ez_sort(a, b, size)</code> deals accordingly with sizes from 2 to 5<br>
		<ins>Helper functions:</ins><br>
		- <code>sort_three</code> actions required to sort a 3-sized list<br>
		- <code>find_min</code> find the minimum number in the list<br>
		- <code>push_min_to_b</code> pushes the min to b in 4 or 5 sized lists<br>
	</tr>
</table>

<table align="center">
	<tr>
	<th align="center"><a href="https://github.com/baderelg/Push_swap/blob/main/mandatory/sorting/turk_sort.c">turk_sort.c</a></th>
	</tr>
	<tr>
		<td><code>turk_sort(a, b, size)</code> deals with everything else<br>
		<ins>Helper functions:</ins><br>
		- <code>find_pos</code> finds the position of the value in stack b<br>
		- <code>move_to_top</code> follows the shortest path to put the value at the top of b (<code>rb</code> or <code>rrb</code> accordingly)<br>
		- <code>create_sorted_array</code> copies the values in an array and then sort it with <code>bubble_sort_array</code><br>
		- <code>push_chunks_to_b</code> the window sweep<br>
	</tr>
</table>

## 🔎 Useful commands

First, to compile the programs:
<table align="center">
	<tr>
	<th align="center"><code>make</code></th>
	<td align="center">compile the push_swap program</td>
	</tr>
	<tr>
	<th align="center"><code>make bonus</code></th>
	<td align="center">compile the checker program</td>
	</tr>
	<tr>
	<th align="center"><code>make clean</code></th>
	<td align="center">remove all objects and dependency files</td>
	</tr>
	
</table>

Examples of medium stack testing commands:
<table align="center">
	<tr>
	<th align="center"><code>ARG=$(shuf -i 1-500 -n 10 | tr '\n' ' '); ./push_swap $ARG</code></th>
	<td align="center">Generate 10 random numbers between 1 and 500 and show the sequences of operations to sort them</td>
	</tr>
	<tr>
	<th align="center"><code>ARG=$(seq -1000 1000 | shuf -n 50 | tr '\n' ' '); ./push_swap $ARG | wc -l</code></th>
	<td align="center">Generate 50 numbers between -1000 and 1000, and calculate the number of lines (operations) it takes to sort them</td>
	</tr>
</table>

Examples of benchmark testing commands:
<table align="center">
	<tr>
	<th align="center"><code>ARG=$(shuf -i 1-10000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l</code></th>
	<td align="center">Generate 100 numbers between 1 and 10000 and calculate the number of operations it takes</td>
	</tr>
	<tr>
	<th align="center"><code>ARG=$(seq -50000 50000 | shuf -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l</code></th>
	<td align="center">Generate 500 numbers between -50000 and 50000, and calculate the number of operations it takes</td>
	</tr>
</table>

> [!NOTE]
> I pipe the commands to  `tr '\n' ' '` because based on how the checker provided by the school works, only spaces are handled.\
> Newlines between numbers should return an error.\
> The `seq` and `shuf` commands output the numbers on separate lines. Thus the need to transform newlines into spaces.

⚠️ <ins>Edge cases:</ins>
```c
./push_swap 					// No arguments, do nothing
./push_swap ""					// Error (empty argument)
./push_swap " "					// Error (whitespace only)
./push_swap "42 2 42"			// Error (duplicate)
./push_swap "1 9 4 2147483648"	// Error (overflow)
./push_swap "1 9 -2147483649 4"	// Error (underflow)
```

## 📚 Useful resources

<div align="center">To dive deeper into push_swap strategies, chunks and the origins of the Turk algorithm, here are some great reads:</div><br>

- <a href ="https://medium.com/@ayogun/push-swap-c1f5d2d41e97">Push Swap — A journey to find most efficient sorting algorithm</a> by A. Yigit Ogun, the article that, I believe, originated with the Turk algorithm idea
- <a href ="https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a">Push_Swap: The least amount of moves with two stacks</a> by Jamie Dawson, an article that depicts strategies for small vs large inputs (with chunk examples)
- <a href ="https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0">Push_Swap Turk algorithm explained in 6 steps</a> by Yutong Deng (pure-forest), as a clear breakdown of the turk method
- <a href ="https://42-cursus.gitbook.io/guide/2-rank-02/push_swap">push_swap (42 Cursus guide)</a> by Laura & Simon from Switzerland (42 Lausanne), to better grasp the project requirements and expectations

---

## 🍃 (BONUS) The checker

Bonus, huh? Man what a drag. This sounds troublesome to explain.\
Good thing that Temari insisted on handling this part.\
Guess I'll just step aside... She's already glaring at me.

<p align="center">
	<a href="https://github.com/baderelg/Push_swap/blob/main/CHECKER.md">
  <img src="https://i.imgur.com/F5tg1nq.png" alt="Kaze">
	</a>
</p>

<h3 align="center">
  <a href="https://github.com/baderelg/Push_swap/blob/main/CHECKER.md">Checker explained by Temari »</a>
</h3>

---

## Checkmate, Owari

> *"Sometimes I wish I was just a cloud, floating along."*

I like to think of Push_swap as shogi with integers.
- Split what is useful now.
- Stash what is annoying.
- Rebuild the victory stack with the fewest moves possible.
- Put the king on top.

After all, efficiency is just laziness with a plan.

<p align="center">
  <img src="https://i.imgur.com/ne4u35S.png" alt="Is it over yet?">
</p>

<hr>

<p align="center">
<sub><i>PUSH_SWAP badge © @Cadets for Cadets — used under MIT License.</i></sub>
<br>
<sub><a href="https://github.com/ayogun/42-project-badges/blob/main/LICENSE">See full license here</a></sub>
</p>
