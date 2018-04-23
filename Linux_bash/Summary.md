# Basic Knowledge

Linux Bash Commands: http://ss64.com/bash/

Variable Use:
- $# Stores the number of command-line arguments that were passed to the shell program.
- $? Stores the exit value of the last command that was executed.
- $0 Stores the first word of the entered command (the name of the shell program).
- $* Stores all the arguments that were entered on the command line ($1 $2 ...).
- $@ Stores all the arguments that were entered on the command line,
- individually quoted ("$1" "$2" ...).

guest-addition (in virtual box?) fix the resolution problem

## Access Management
- chmod
- chown
- su: substitute user identity
- sudo
- ulimit: user limit

## Commands and Execution
- alias: alias m="ssh -X zhuoyuan@172.19.32.131"
- bash and sh: execute .sh in a subshell
- source and .: run in current shell
- exec: execute a program
- type: describe a command
- !!: run the last command again
- ###: #comment

## Compile
- make

## Compression Tool
- bzip2: compress
- gzip: compress
- rar
- tar -xvf ...: extract(x) and display verbose(v) information from a
- [gzipped(z)] file(f). -xvzf
- unrar
- zip / unzip: # zip -r abc.zip file1 directory2
- unzip abc.zip
- unzip -v abc.zip (just see what’s inside without unzipping)

## Dependency Check
- ldconfig:Configure Dynamic Linker Run Time Bindings. e.g., ldconfig /usr/local/cuda/lib64
- ldd ./calcflow: check dependency to see if we miss any .so files

## Disk Management Tool
- Disk Utilize Analyzer: baobab
- df -Th: check mounting status
- du: Display folder size

## Display
- cat: three related functions with regard to text files: displaying them, combining copies of them and creating new ones.
- head: print first part; head -3 test.txt, print first 3 lines
- ln [OPTION] ... [-T] target link_name: make link
- ln -s /webroot/home/httpd/test.com/index.php /home/vivek/index.php
- ls -l (details) -t(in time order) -r(reverse)
- ls -f ./xxx/xx | wc -l (count how many files, -f: no sorting; wc -l: how many lines);
- ls -a (all files)
- ls -l | grep ’^{}-’ | wc -l (how many files)
- ll xxx: check pseudo link
- ls -l | grep ’^{}d’ | wc -l (how many folders)
- ls -lR | grep ’^{}-’ | wc -l (how many files recursively)
- ls /dev/disk/by-uuid [-l]: check uuid of disks:
- less: one screen at a time
- stat: display status of the file
- tail: tail -3 test.txt, print last 3 lines
- xargs
- xrandr -o right/normal/left/invert: rotate display

## File and Folder Operation
- cd
- cp
- diff -u old-file new file: compare files
- find: e.g., find / -name ’libptf77blas.so’; to find a file
- file: file type
- mkdir
- mv #rename or move file
- pwd; # Display current path
- rename
- rm
- rmdir
- touch

## Find and Replace
- awk:  Find and Replace text, database sort/validate/index
- grep -r ’rgb2whs’ ./abc/: Find content in files
- gawk: find and replaces within files

## Hardware
- sudo fdisk -l: show the details
- mount
- sudo mount -t ntfs /dev/sdb2 /media/DATA: actually mount the data
- vi /etc/fstab: edit the path and uuid

## Help
- help:
- man: man make/rm/... :see the manual of xxx

## Installation
To install a file (e.g. libpng): 
- ./configure (for settings); 
- make
- sudo make install.
- Things will be put in /usr/local/lib; /usr/local/include; /usr/local/bin;

## Linux
- lsb_release: check Linux release version
- passwd: change password
- reboot
- uname: print system information
- who: all logged in users
- whoami:

- .a files: static library
- .so files: shared/dynamic library copy to /usr/lib
- Can’t find library in execution? vi /home/Levin/.bashrc; then change LD_LIBRARY_PATH;
- Linux will not find .so files locally

## Monitor
- gnome-system-monitor # to see cpu usage:
- jobs: list active jobs
- kill: kill a process
- mpstat -P ALL; mpstat; #Process state
- pkill: kill a process
- ps -a: check all running processes
- top: check the status and usage of memory by processes

## Network Functions
- curl: curl -L google.com
- ifconfig: config network interface
- ping
- rcp: remote copy
- scp local_file remote_username@remote_ip:remote_folder
- ssh: secure shell client
- wget: retrieve web pages or files from http, https or ftp

## Output
- tee: redirect output to multiple files, tee command is used to store and view (both at the same time) the output of any other command. Example: Paddle use 2>&1 | tee log to print on both screen and an output file

## Package Management
- apt-get:  Search for and install software packages (Debian/Ubuntu)
- aptitude: Search for and install software packages (Debian/Ubuntu)
- dpkg: package management:
- dpkg -l : list all packages
- dpkg -l | grep opencv
- dpkg -S : search a package
- dpkg -i xxx.deb : install a deb file
- sudo dpkg -r zip : uninstall a package

## Session Management
- screen
- screen -r

## Time
- date

## To Study
- comm
- cut
- install
- join:
- more
- sed
- sort: sort -k 2,2 input.txt >output.txt
- tr: change format; tr -s ’\textbackslash n’ < input.txt > output.txt;
- uniq: uniq < input.txt >output.txt
