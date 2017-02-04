# cppOS

## Overview
This is a simple operating system written in C/C++ and derived from the excellent video series at https://www.youtube.com/channel/UCQdZltW7bh1ta-_nCH7LWYw I highly recommend anyone interested in starting from scratch watch this video series.

## Background
I've written software for a long time, but more-so at the high-level (web apps, web forms, PHP, etc.) I finally got frustrated not understanding the low-level functions of an OS and wanted to be able to troubleshoot much more precisely. So what better way than to understand what happens under all the higher-level stuff you work in on a daily basis? This applies to all sorts of fields as well! (IoT, Mobile, Embedded Systems, Security, etc)

## Prerequisites
* Understanding of compiling software at a bare minimum
* Understanding of binary calculations and hi/low bits
* *nix Distribution that can run the gnu compiler and tools (I'm using Linux Mint 17)
* *nix Packages
** sudo apt-get install g++ binutils libc6-dev-i386 grub xorriso
* Most importantly...Patience. YOU are the OS, so it takes a lot of time to get things working correctly sometimes.

## How I work on this project
One of my goals while working on this project is to do as much as possible with free tools and my existing hardware / operating system. That said, my configuration might be a little strange to some, but it's what I feel like rolling with and is comfortable for me personally. I like the flexibility of having both Operating Systems and their corresponding tools and environments both readily available. Like a lot of people, I need to have Windows as my main OS for a lot of games I play.
* [Windows 10 Home/Professional](https://www.microsoft.com/en-us/windows/get-windows-10) - OS on my main machine
    * [Google Chrome](https://www.google.com/chrome/) - Main browser on my main machine
    * [Oracle VM Virtual Box](https://www.virtualbox.org/) - HyperVisor so we can run Linux for the dev machine
        * [Linux Mint 18.1](https://www.linuxmint.com/) - Guest OS where development and debugging tools live

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
    * `git --clone https://github.com/Tri4ce/cppOS.git ~/Development`
    
## TODO
* Figure out 64-bit native
* Add section for readelf and objdump
* Add section for gdb and remote debugging with qemu
* Add section for 

### For loader.s
* See: http://wiki.osdev.org/Multiboot
* See: https://www.gnu.org/software/grub/manual/multiboot/html_node/multiboot.h.html
* See: https://en.wikipedia.org/wiki/Hexspeak
* See: https://www.chemie.fu-berlin.de/chemnet/use/info/gas/gas_7.html*SEC116
* See: https://www.tutorialspoint.com/assembly_programming/assembly_basic_syntax.htm
* See: http://web.mit.edu/gnu/doc/html/as_7.html
* See: https://www.tutorialspoint.com/assembly_programming/
* See: 


// Define the Type "Constructor" which is a Pointer to a Function that takes zero-arguments.
/*

		# TODO: Why do we do this?
		#call callConstructors # Linked in from kernel.cpp


typedef void (*Constructor)();

extern "C" Constructor start_ctors;
extern "C" Constructor end_ctors;

extern "C" void callConstructors()
{
	for(Constructor* i = &start_ctors; i != &end_ctors; i++)
		(*i)();
}
*/