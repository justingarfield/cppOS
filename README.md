# cppOS

> CURRENT STATE

> I'm currently in the middle of finishing the proper implementation of interrupts and the IDT.

> At this point, the OS will simply just boot up, load its GDT, and that's it.

> Once I complete interrupts, much more will be available in a short-time after.

## Overview
This is a simple operating system written in Assembly and C/C++, derived from a combination of official manuals, reference web sites, YouTube videos, and online lectures.

My intent is to help break barriers down for developers coming from managed object-oriented languages and to also promote my own self-learning. 
My hope is that it will be helpful to others to at least learn bits and pieces about what happens down near the bare-metal and what's going on 
inside of our computers or anything with a microprocessor inside of it.

Please see the _Source and Reference Materials_ section for a boat-load of links to supporting materials and information. 
Whenever you're at a loss, sift through the links and you should find answers or starting points to find them.

## Background
Having written software for a long time, but more-so at the high-level (web apps, web forms, PHP, etc.) I finally got frustrated not understanding the low-level functions of an OS and wanted to be able to troubleshoot much more precisely. So what better way than to understand what happens under all the higher-level stuff you work in on a daily basis? This applies to all sorts of fields as well! (IoT, Mobile, Embedded Systems, Security, etc)

## Prerequisites
* Understanding of compiling software at a bare minimum
* Understanding of binary calculations and hi/low bits
* Understanding of Assembly and C/C++
* *nix Distribution that can run the gnu compiler and tools
* Most importantly...Patience. YOU are the OS, so it takes a lot of time to get things working correctly sometimes.

## How I work on this project
One of my goals while working on this project is to do as much as possible with free tools and my existing hardware / operating system. That said, my configuration might be a little strange to some, but it's what I feel like rolling with and is comfortable for me personally. I like the flexibility of having both Operating Systems and their corresponding tools and environments both readily available. Like a lot of people, I need to have Windows as my main OS for a lot of games I play.
* [Windows 10 Home/Professional](https://www.microsoft.com/en-us/windows/get-windows-10) - OS on my main machine
    * [Google Chrome](https://www.google.com/chrome/) - Main browser on my main machine
    * [Oracle VM Virtual Box](https://www.virtualbox.org/) - HyperVisor so we can run Linux for the dev machine
        * [Linux Mint 18.1](https://www.linuxmint.com/) - Guest OS where development and debugging tools live
            * [Visual Studio Code](https://code.visualstudio.com/) - Main IDE and development tools
            * Build tools, GRUB, and other dev-related libraries and programs

_Note: I tried getting this to work in Bash on Ubuntu on Windows - Beta, but due to a limitation accessing the network stack, I was unable to proceed. I will revisit this setup later on if they decide to expose more inside that feature._

## Setting up the Linux Mint 18.1 Guest OS
1. Download and install Oracle VM Virtual Box
2. Download the Linux Mint 18.1 ISO
3. Open up Oracle VM Virtual Box and create a new Ubuntu (64-bit) Linux Virtual Machine (VM) with a 20GB hard drive and whatever memory you feel like allocating
4. Go into the VM settings and under General - Advanced set the Shared Clipboard to Bidirectional
5. Go to the Storage area of the VM settings and set the CDROM to point to the Linux Mint 18.1 ISO file downloaded earlier
6. Start the VM and the Linux Mint ISO should boot up to a LIVE (in memory) version
7. When you get to the desktop, double-click on Install Linux Mint
8. Just install it using all the defaults, that will suffice for our purposes
9. Open a Terminal window up (Ctrl+Alt+T)
10. Run the following commands:
    * `sudo apt-get update`
    * `sudo apt-get --yes upgrade`
        * _Note: If the upgrade process gets hung-up, just restart the machine and re-open a Terminal, then run:_ `sudo dpkg --configure -a`
    * `sudo apt-get install git`
    * `sudo apt-get install g++ binutils libc6-dev-i386 grub xorriso`
    * `shutdown -r now` _(just for good measure)_
11. Open another Terminal after restart and run:
    * `sudo apt-get install --yes git g++ binutils libc6-dev-i386 grub xorriso qemu-system-x86-64`
    * `mkdir ~/Development`
    * `git clone https://github.com/Tri4ce/cppOS.git ~/Development/cppOS`
12. Download and install [Visual Studio Code](https://code.visualstudio.com/)
13. Open Visual Studio Code
14. Click _File_, click _Open Folder..._, pick the _/Development/cppOS_ folder we cloned into earlier.

## Makefile Targets ##
This project utilizes a Makefile to quickly compile, debug, run, and package the OS code and binaries.
This section is an overview of each target available in the Makefile.

### ```make``` ###
Runs the `g++` and `as` compilers against source to generate objects, followed by running `ld` to link them and create a _cppOS.bin_ file.

### ```make debug``` ###
Calls `qemu-system-x86_64 -kernel cppOS.bin -s -S &` to start cppOS in debug mode and then remotely attaches with gdb pointing to the working directory for symbols.

### ```make run``` ###
Calls `qemu-system-x86_64` with the _-kernel_ flag, passing it the _cppOS.bin_ file to use as the kernel.

### ```make cppOS.iso``` ###
Generates a bootable ISO image of cppOS by calling `grub-mkrescue` and providing the _cppOS.bin_ and _Multiboot v1_ entries for the _GRUB Bootloader_ to see the OS.

### ```make install``` ###
Copies the _cppOS.bin_ generated from the default make target to the /boot directory. Use this if you want to try rebooting and pointing to your own kernel when you hit GRUB.

### ```make clean``` ###
Removes all files generated by any of the make targets.

## Source and Reference Materials

* [OSDev Wiki - Multiboot](http://wiki.osdev.org/Multiboot)
* [Multiboot Specification - multiboot.h](https://www.gnu.org/software/grub/manual/multiboot/html_node/multiboot.h.html)
* [Hexspeak - Wikipedia](https://en.wikipedia.org/wiki/Hexspeak)
* [Assembly Basic Syntax](https://www.tutorialspoint.com/assembly_programming/assembly_basic_syntax.htm)
* [Using as - Assembler Directives](http://web.mit.edu/gnu/doc/html/as_7.html)
* [Assembly Programming Tutorial](https://www.tutorialspoint.com/assembly_programming/)
