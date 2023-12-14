# Helper

Command line modified sort command.

![helper](https://skokotos.com/images/helper.png)

## Important

**Helper** has not produced any errors so far on UNIX systems. It has been designed and tested on Ubuntu Flavour version 23.10 x86_64.

If you face a situation full of errors, please contact the maintainers. 

## Table of Contents
<!-- vim-markdown-toc Marked -->

* [Features](#features)
* [Requirements](#requirements)
* [Installation](#installation)
* [Basic usage](#basic-usage)
* [Alternative usage (Optional)](#alternative-usage-optional)
* [Error codes](#error-codes)
* [Reporting bugs](#reporting-bugs)
* [License](#license)
* [Authors](#authors)

<!-- vim-markdown-toc -->

## Features

**Helper** provides the following features:

 -  Easy error detection.
 
## Requirements
* Unix based OS's

  - GCC Compiler
  - makefile

## Installation

Clone the above repository locally on your computer, open the src folder, run the command 'make' in the terminal, and finally, execute the command `./helper`.

## Basic usage

After a successful cloning and compiling, the command to execute it:

    ./helper

This will display the usage of helper program's window with a list of options.

![Usage](https://skokotos.com/images/usage2.png)

## Alternative usage (Optional)

If you prefer not to use the command via `./helper`, there is also an alternative usage:

  - You need to save the `src` folder to a specific location within your system where you believe it won't be altered.

  - Open the terminal within the directory `src` and issue the following command `pwd`, it will display the current working directory, showing the full path.

  - Copy the full path that the terminal displayed to you and open another terminal window.

  - Issue the command: `nano ~/.bashrc` to insert the path from the helper file.

  - Insert the following command at the end of the file (.bashrc): `export PATH=$PATH:/home/username/helper`

**Warning:** You need to replace the username with the name you are using!

  - After issuing the above command, press `CTRL + O` to save, then press `ENTER`, and finally, press `CTRL + X` to exit the .bashrc file.

  - Finally, execute the following command: `source ~/.bashrc` to update the .bashrc file so that you can run the `helper` command.

## Error codes

**Helper** has an integrated error system with numerical codes. Each code corresponds to a string explaining the error. Below, you will find the table of possible errors:

| Exit code | Description |
| :---------: |  :---------:  |
|     0     |   SUCCESS   |
|     1     ||
|     2     ||
|     3     ||
|     4     ||
|     5     ||
|     6     ||
|     7     ||
|     8     ||
|     9     ||

**Exit Code 0:** If your program returns exit code 0 after execution, it means that it ran without any issues. :D



## Reporting bugs


When a bug is found, please do report it by [opening an issue at github](https://github.com/Greekforce1821/helper/issues), as already stated above.

In your report you should, at the very least, state your **Linux version**, **GCC version**, **Kernel version** and **CPU version (x86 or x64)** of installation.

A simple screenshot of your terminal output would be preferable by issuing the following command: `neofetch`

![Neofetch output](https://skokotos.com/images/neofetch.png)

**Warning:** As you can see in the above screenshot, it does not include the correct information required because the program is running on a virtual machine and cannot display the real components of the computer.


## License

MIT License

Copyright (c) 2023 Spyridon Eftychios Kokotos & Christos Spyridon Karydis

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.


## Authors

The above program is a creation of Spyros Kokotos - inf2021098@ionio.gr & Christos Karydis - inf2022076@ionio.gr, and you can use it for your personal projects or further develop it as long as you always give credit to the creators.



