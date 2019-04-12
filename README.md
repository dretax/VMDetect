# VMDetect
Virtual Machine Detection based on a TSC register.

Every processor since pentium has a 64-bit register "Time Stamp Counter".
If the OS is being emulated the TSC will be much higher resulting in a detectable "flaw".
A non-virtualized OS has an average difference of 80-90 (but this value can be below as well)
The return value on a virtualized OS will be a lot more higher than that value.
