# timer
A simple background timer app with desktop notifications.

## Build
cmake -B build && cmake --build build

## Install
sudo cp build/timer /usr/local/bin/timer

## Usage
Add to your .zshrc / .bashrc:
timer() {
    (nohup timer "$1" "$2" &>/dev/null & disown) 2>/dev/null
    echo "▶ Timer: $1 for $2"
}

Then just run:
timer "eat food" 10m
timer "laundry" 1h
timer "pasta" 8m

## Requirements
- zenity (sudo pacman -S zenity)
