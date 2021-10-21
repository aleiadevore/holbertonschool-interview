# Notes on the problem

## Output
*Oh the things that are unsaid*
- One correct configuration per line
- In each line, coordinates for each queen in the board listed, in order of row, 0-N.

## What a queen
- Can't be in the same row or column as another queen
- Can't be diagonal to another queen
- Size NxN board has N number of queens

## Backtracking
- Brute force that quits while it can
- Build a candidate, break it down when it's clear it doesn't work

## Scratchpad
- Will the queen ever be in a corner?
  - Yes
- **With queen at board[i, j], a new queen cannot be at:**
  - board[i + 1, j]
  - board[i + 1, j - 1]
  - board[i + 1, j + 1]
- **Once a queen has been placed, that i and j must not be used again**
- Simplest way to create a new configuration is to rotate a previous one so long as it is not the same once rotated.
  - This can also be done through mirroring
  - This idea saves time, but the logic would be messy. Send to a rotate helper function? Do I keep track of the previous dict to make sure it hasn't been done before?
- If I weren't on a time constraint, I would just print out the board. The output that they want seems to be the most frustrating, as I'll have to save coordinates rather than marking the queen in a matrix
  - May make sense to create a dictionary, since I'll know the number of queens each time.
    - Save location to dict
    - Print out dict values after each successful candidate built
    - When candidate not successful, reset dict values before returning
- **Issues**
  - This is going to be time-intensive with backtracking.
  - I'll need to make sure that I'm not duplicating it. Maybe save location of last solution's first queen and try all solutions beginning with j + 1?
  - If previous j didn't have an answer, need to keep track of that so it doesn't get stuck in a loop at first failing [0, j]

