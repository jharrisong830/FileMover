# FileMover
A program written in C that copies files from a source directory to a destination directory.

***WARNING*: This is a simple, unoptimized project and is not intended for actual use. Files may be permanently lost if you use this command. Behavior may be unpredictable.**

## How to Compile an Executable
1. Download the `fmove.c` and `Makefile` files from this repository
2. Open a command prompt (in the same working directory that you place the downloaded files in)
3. Enter the command `make` (**NOTE**: make sure you have `gcc` and `make` installed on your system)
4. You should now have an executable file called `fmove`!

## Using the fmove Command
Once you have the executable, open a command prompt in the same working directory. Then, type the following command:
> `./fmove <path1> <path2>`

where `path1` is the **source** path, and `path2` is the **destination** path. `fmove` will then *recursively* copy all files and subdirectories from `path1`, remove them, and copy them to `path2`.

---

### Background
I am making this project while taking a Systems Programming course, which covers programming in C for UNIX systems. We have covered the basics of file systems, and I decided to make this project to practice my skills and create a (semi) useful utility. While it is very simple, and is only a command line app, I'm proud of it, and I hope to expand it and make better projects in the future!