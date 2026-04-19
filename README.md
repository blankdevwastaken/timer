# Timer
A simple background timer app with desktop notifications.

## Build
cmake -B build && cmake --build build
sudo cmake --install build

## Usage
Add to your .zshrc / .bashrc:
```
timer() {
    (nohup ~/Projects/newtime/build/main "$1" "$2" &>/dev/null & disown) 2>/dev/null
    echo "\ueab2 You will be reminded to \"$1\" in $2"
}
```

Then just run:
timer "eat food" 10m
timer "laundry" 1h
timer "pasta" 8m

## Requirements
- zenity (sudo pacman -S zenity)
