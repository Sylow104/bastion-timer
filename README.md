# bastion-timer #

A fixed interval timer which 'ticks' at a given time interval (given in seconds).
Currently, the project compiles on Fedora 32 with the GCC, glibc, pthreads
already in place. See TODO regarding about porting to Windows or other platforms.

# Requirements #
- pthreads
- glibc and GCC

# Building #
Run:
```
mkdir build/ ;
cd build/ ;
cmake ../ ;
cmake --build ;
```
Optionally:
```
cmake --install ;
```

# Program flags #
```
Default, -n, -a		Interval = 10 seconds,
-e			Interval = 8 seconds,
-d <SECONDS>
--diff=<SECONDS>	Interval = <SECONDS> second(s)
			where <SECONDS> is a positive non-zero value
```

# TODO #
- Find correct Windows API and bind it appropriately for argument taking and
flags.
- Add threading solutions from Windows API in place of pthreads.