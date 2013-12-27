tsc_checker
===========

**tsc_checker** is a lightweight C module for checking TSC ( Time Stamp Counter ) value and comparing it with threshold value to avoid new 208.5 days problem.
  
Features
===========

* Display the tsc value of cpu and caluculate the current ns value based on TSC * SC
* Warn numeric overflow for threshold exceeded of the tsc value
  
Installation
===========

First, make sure you have GCC installed.
  
On Linux, for Red Hat Enterprise Linux based distributions like CentOS and Scientific Linux, type:

```
$ gcc
```
  
If the output looks something like this, you are in good shape:

```
gcc: no input files
```
  
If the output looks more like this, you need to install GCC:

```
gcc: command not found
```
 
To install GCC, type:

```
sudo yum install gcc
```

Once you have verified that GCC is installed, simply:

```
$ make
```

```
$ ./tsc_checker -h
Usage:
  -h                           show help
  -v                           show version
  -f FREQUENCY                 specify the frequency of CPU (KHz) [default: 2000000]
```

Usage
===========

tsc_checker is run from the command line. Please open your terminal and go to the directory of tsc_checker.

```bash
$ ./tsc_checker -f 2800000
```

```bash
TSC value        : 148885740411018
SC value         : 365
current value    : 54343295250021570
threashold value : 18446744073709551615
```

License
===========
GNU GPL [https://gnu.org/licenses/gpl.html](https://gnu.org/licenses/gpl.html)

