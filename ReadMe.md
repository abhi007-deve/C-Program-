# Inventory System (C + C++)

## Build
make

## Run
./app

## Features
- Add item
- View item
- Update item
- Delete item (soft delete)
- List all items

## Test Cases
- Add 3 items → restart → still present
- Update item → persists after restart
- Delete item → not shown
- Duplicate ID blocked
- Invalid input handled