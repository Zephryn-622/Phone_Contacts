# Phone Contacts

A small console-based address book written in C++. It's a beginner practice
project: one source file, one struct-based array, and a text menu.

Contacts live in memory while the program runs and are gone when you exit —
there is no file or database behind it.

## Features

The menu has six options:

| Option | What it does |
| ------ | ------------ |
| 1. Add contacts | Enter name, gender, age, phone number and email |
| 2. Show contacts | List every stored contact |
| 3. Delete contacts | Remove a contact by name |
| 4. Find contacts | Look up one contact by name and print it |
| 5. Edit contacts | Overwrite all fields of an existing contact |
| 6. Clear contacts | Ask for confirmation, then empty the whole book |
| 0. Exit | Quit |

Storage is capped at 1500 contacts (`#define MAX 1500` in `Contacts.cpp`).
Adding a 1501st contact prints "Contacts is FULL!" and returns to the menu.

## Requirements

- A C++ compiler with C++11 or later. `g++` or `clang++` both work.
- A terminal. The program clears the screen with `system("clear")`, which is
  a Unix command — on Windows this call does nothing useful and you'll get an
  error line between menus. Change it to `system("cls")` if you build on Windows.

## Build and run

macOS / Linux:

```bash
g++ -std=c++17 -o Contacts Contacts.cpp
./Contacts
```

Windows (MinGW):

```bash
g++ -std=c++17 -o Contacts.exe Contacts.cpp
Contacts.exe
```

The repository also contains a prebuilt macOS (arm64) `Contacts` binary, so on
that platform you can run `./Contacts` directly. Rebuild from source after
editing `Contacts.cpp` — the binary does not update itself.

## Example session

```
================================
1. Add contacts
2. Show contacts
3. Delete contacts
4. Find contacts
5. Edit contacts
6. Clear contacts
0. Exit
================================
1
Enter name: Alice
Enter gender (1 for male, 2 for female): 2
Enter age: 30
Enter phone number: 13800001111
Enter email: alice@example.com

Added successful

Press ENTER to continue...
```

Choosing `2` then prints:

```
Name: Alice
Gender: Female
Age: 30
Phone number: 13800001111
E-mail: alice@example.com
```

After most actions the program waits for you to press ENTER before redrawing
the menu.

## How it works

Everything is in `Contacts.cpp`.

Data is two structs:

```cpp
struct Person {
    string P_Name;
    int    P_Gender;  // 1 = male, 2 = female
    int    P_Age;     // must be 0 < age < 200
    string P_Phone;
    string P_Email;
};

struct AddressBook {
    struct Person personArray[MAX];  // fixed buffer, MAX = 1500
    int P_Size;                      // how many slots are in use
};
```

The book is a fixed-size array plus a count. `P_Size` is always the index of
the next free slot, so adding writes to `personArray[P_Size]` and increments it,
and showing loops from `0` to `P_Size - 1`.

Each menu option has one function that takes `AddressBook *`:

- `AddPerson` — validates gender (1 or 2) and age (1–199) in a loop until the
  input is acceptable, then stores the contact.
- `ShowPerson` — prints every contact in insertion order.
- `PersonExist` — the shared lookup helper. Scans by name and returns the array
  index, or `-1` if there is no match. `DeletePerson`, `FindPerson` and
  `EditPerson` all call it instead of repeating the search.
- `DeletePerson` — shifts every following element down one slot, then decrements
  `P_Size`, which closes the gap and keeps the array packed.
- `FindPerson` — prints the single matching contact.
- `EditPerson` — replaces name, gender, age, phone and email in place.
- `ClearPerson` — sets `P_Size = 0` after a Y/N confirmation. The old records
  stay in the array's memory but are no longer visible or reachable.
- `showMenu` / `pauseClear` — draw the menu, and wait for ENTER then clear the
  screen.

`main` is a `while (true)` loop: show the menu, read a number, `switch` to the
matching function, and `return 0` on `0`. Anything else hits `default` and
prints "Invalid selection."

## Things to be aware of

These are behaviours of the current code, not bugs to file — worth knowing so
your test input doesn't confuse you:

- **Nothing is saved.** Exit and your contacts are gone.
- **Names must match exactly.** Lookup is a plain `==` comparison, so `alice`
  will not find `Alice`, and there is no partial or fuzzy search.
- **Duplicate names are allowed.** `PersonExist` returns the first match, so
  deleting or editing a duplicated name only touches the earliest one.
- **Non-numeric input at a number prompt** (like typing `abc` at the menu)
  puts `cin` into a failed state and the menu starts misbehaving. The prompts
  that validate are gender and age; the menu itself just does `cin >> select`.
- **Phone and email are strings with no format checking** — the program never
  validates that a phone number is digits or that an email has an `@`.

## Ideas for extending it

Roughly in order of difficulty, if you want to keep building on this:

1. Save to and load from a text file so contacts survive a restart.
2. Case-insensitive name matching, and partial-match search.
3. A proper `cin` error-recovery helper so bad input never wedges the menu.
4. Replace the capped array with `std::vector<Person>` to drop the 1500 limit.
5. Sort the display by name, or group contacts alphabetically.
6. Multi-field input validation for phone and email formats.
