# IDE Setup

For setup within Linux, there are a couple of options - Geany and Gedit. We'll go over both. I specifically work with Linux and so, I'll only cover options within it. But it'll be fairly straightforward to set the same in other platforms too.

## Gedit

1. First, install `gedit` with the following plugins 
```bash
$ sudo apt install gedit gedit-plugins gedit-developer-plugins
```
2. Enable the following plugins - 
2.1. Snippets
2.2. External Tools
2.3. Embedded Terminal
3. Create a snippet with [cpp.cpt](cpp/cpt.cpp) as snippet with a shortcut.
4. Go to "Manage External Tools" option and create a script with shortcut to compile and run the program you created like so -
```bash
#!/bin/sh

echo "Compiling $GEDIT_CURRENT_DOCUMENT_NAME source code"
GEDIT_CURRENT_DOCUMENT_WITHOUT_EXT=$(echo "$GEDIT_CURRENT_DOCUMENT_NAME" | sed 's/.cpp//g')
g++ -std=c++11 "$GEDIT_CURRENT_DOCUMENT_NAME" -Wshadow -Wall -o $GEDIT_CURRENT_DOCUMENT_WITHOUT_EXT -O2 -Wno-unused-result
./"$GEDIT_CURRENT_DOCUMENT_WITHOUT_EXT"
```
5. You should now have a fully complete setup to 

### Caveats

1. File type has to be set manually to "CPP" everytime you start a new file with template code. (No shortcut available AFAIK right now)
2. Switching between terminal and Editor is still an issue

## Geany

> Most of the content for Geany setup re-used from [Errichto](https://github.com/Errichto/youtube/wiki/Linux-setup).

1. Install `geany` like so -
```bash
$ sudo apt install geany
```
2. Configure Geany preferences:
2.1. Open preferences with `CTRL`+`ALT`+`P`.   
2.2. In Keybindings tab, set Switch to Editor as `F1` and confirm overriding, then Switch to VTE as `F2` (VTE is built-in terminal).   
2.3. In Terminal tab, mark `Follow path of the current file`. Terminal will now automatically change a path after you open a new file.   
2.4. (optional) In Editor tab, change Comment toggle marker to an empty string or a single space.   
2.4.1. Open any C++ file in Geany, go to Build -> Set Build Commands and copy my flags.    
2.4.2. Compile (F8): `g++ -std=c++11 -Wshadow -Wall -o "%e" "%f" -O2 -Wno-unused-result`   
2.4.3. Build (F9): `g++ -std=c++11 -Wshadow -Wall -o "%e" "%f" -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG`   
2.5. If your computer beeps after compilation, unmark Beep on errors in Preferences -> General -> Miscellaneous.   
2.6. Open a file ~/.bashrc and uncomment a line #force_color_prompt=yes in order to get colorful terminal in Geany. Restart geany or run source ~/.bashrc to trigger the change.   
3. Symlink template file from your repo to Geany templates directory within `~/.config/geany/templates/files/`   
```bash
$ pwd ~/.config/geany/templates/files/
$ ln -s /home/ANT.AMAZON.COM/dwarakam/projects/algorithms/cpp/cpt.cpp ./cpt.cpp
```

### Optional Steps

1. Hide Toolbar and Sidebar by unmarking them in View.
2. Install Guake and make it run on start-up:
```bash
$ sudo apt install guake
```
3. Activities (top-left corner) -> Startup Applications Preferences -> Add -> set name and command as guake
4. Open system settings (top-right corner of the screen) and mark Auto-hide the Dock in Dock tab.