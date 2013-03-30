Cataclysm-DDA-I18N
==================

This is I18N version of "Cataclysm: Dark Days Ahead" - A rogue-like zombie game.
If you want to read official README.md of Cataclysm-DDA, please read Cataclysm-DDA.md.

## How to build

1. Install pre-requirements

    ```
    # Ubuntu
    sudo apt-get install git build-essential libncurses5-dev libncursesw5-dev gettext cmake

    # Windows (MinGW)
    # You need to install MinGW and CMake at first.
    mingw-get install gettext
    ```

1. Clone repository

    ```
    git clone https://github.com/palm3r/Cataclysm-DDA-I18N.git
    cd Cataclysm-DDA-I18N
    git submodule update --init
    ```

1. Build

    ```
    mkdir build
    cd build
    cmake -G "Unix Makefiles" ..
    make

    # if you want clean install files
    # files are installed at "Cataclysm-DDA-I18N/install"
    make install
    ```
