# bastion-timer #

A fixed interval timer which 'ticks' at a given time interval (given in seconds).

# Requirements #
- pthreads
- glibc and GCC

# Building #
Run:
```
mkdir build/ ;
cd build/ ;
cmake ;
cmake --build;
```
Optionally:
```
cmake --install ;
```

# Program flags #
```
Default, -n, -a		Interval = 10 seconds,
-e			Interval = 8 seconds,
-d/--diff <SECONDS>	Interval = <SECONDS>
```