# Fulcrum

![fulcrum](https://github.com/dschil138/Fulcrum/blob/main/photos/fulcrum-logo.png)

_This is a wired, QMK version of dschil138's [Fulcrum](https://github.com/dschil138/Fulcrum/blob/main/README.md), a wireless ergonomic keyboard that features 5-way switch joysticks, which are mounted horizontally to take advantage your thumb's natural range of motion._

-   Keyboard Maintainer: [Nick Mather](https://github.com/forcebe)
-   Hardware Supported: _Handwired, ATMega32U4_

Make example for this keyboard (after setting up your build environment):

    make fulcrun:default

Flashing example for this keyboard:

    make fulcrun:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

-   **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
-   **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
-   **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
