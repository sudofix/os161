# [OS Lab Assignment](https://github.com/sudofix/os161/)
# First Let's Create A Virtual Machine

- Set Name, Operating System & Memory Size

![](batch1/1.png)

- Go Through The Installation Process

## ![](batch1/3.png)

---

---

---

# Now Lets Run Our Virtual Machine

- First We Start Our Virtual Machine in The Background and Login to it

```
$ VBoxManage startvm lubuntu --type headless
$ ssh -p 3022 mohamed@localhost
```

![](batch1/5.png)

#### Why Are We Doing This ?

- So We Can Use Our Virtual Machine From Host Termnal

---

---

---

# Now Let's Install Required Packages

- Lets install Git so We Can Clone Repositories

```
$ sudo apt-get install git
```

![](batch1/7.png)

- and Let's Install Our C Compilers so we Can Use `make` and `bmake` Commands

```
$ sudo apt-get install build-essential
```

![](batch1/8.png)

- Now Let's Install os161-toolchain

```
$ sudo add-apt-repository ppa:ops-class/os161-toolchain
$ sudo apt-get update
$ sudo apt-get install os161-toolchain
```

![](batch1/9.png)

![](batch1/10.png)

- Ok, Now Lets Clone os161 Repository Into Our src Directory
  - _note : i forked os161 repository to my github account so i can push the edits i make_

```
$ git clone https://github.com/sudofix/os161 src
```

![](batch1/12.png)

---

---

---

# Now Let's Compile The Kernel

- First we Configure our src Directory

```
$ cd ~/os161/src
$ ./configure
```

![](batch2/12.png)

- Now we Navigate to conf Directory and Configure it

```
$ cd ~/os161/src/kern/conf
$ ./config DUMBVM
```

![](batch1/14.png)

- Now we go to DUMBVM folder and compile it

```
$ cd ~/os161/src/kern/compile/DUMBVM
$ bmake depend
$ bmake
$ bmake install
```

![](batch1/15.png)

![](batch1/16.png)

![](batch1/17.png)

---

---

# Now Lets Run The Kernel

- Navigate to root Folder and Download Configuration file for sys161

```
$ cd ~/os161/root
$ wget https://www.ops-class.org/files/sys161.conf
```

![](batch1/19.png)

- Now Let's Run The Kernel

```
$ sys161 kernel
```

![](batch1/20.png)

![](batch1/21.png)

---

---

---

# Editing sys161 conf File

- Lets Edit the conf File and Increase Ram and Decreaes CPUs

```
$ vim sys161.conf
```

![](batch1/23.png)

- As We Can See here 20MB is too large for memory

![](batch1/24.png)

- let's change it to 12MB

![](batch1/25.png)

---

---

---

# Making Edits

- lets navigate to kern folder and create folder for our custom functions then create a C file to use for functions

```
$ cd ~/os161/src/kern
$ mkdir edits
$ touch info.c
```

![](batch2/1.png)

- now lets edit our info.c file

```
$ vim info.c
```

![](batch2/2.png)

- now lets navigate to include folder and create a header file and edit it

```
$ cd ~/os161/src/kern/include
$ touch info.h
$ vim info.h
```

![](batch2/4.png)

- now lets navigate to conf folder and add our C file in conf.kern file

```
cd ~/os161/src/kern/conf
$ vim conf.kern
```

![](batch2/6.png)

- now lets navigate to main folder and edit main.c
  - so we first add oue header file, edit some info and call our function

```
$ cd ~/os161/src/kern/main
$ vim main.c
```

![](batch2/7.png)

![](batch2/8.png)

- and let's edit version file to add our version

```
$ cd ~/os161/src/kern/include
$ vim version.c
```

![](batch2/14.png)

- Now lets build the kernel again

```
$ cd ~/os161/src/kern/compile/DUMBVM
$ bmake clean
$ bmake depend
$ bmake
$ bmake install
```

![](batch2/16.png)

- let's run the kernel again to see our modifications

```
$ cd ~/os161/root
$ sys161 kernel
```

![](batch3/8.png)

---

---

---

# Extra Modifications

## Now i'm Going To Add To Functions two Our Kernel Menu. One is a Simple Calculator and The Other is an info one

---

- First Lets Create Our 2 Functions in `info.c` file we created earlier

![](batch3/1.png)

![](batch3/2.png)

- now we add our function prototypes in our header file `info.h`

![](batch3/3.png)

- now let's include our `info.c` in `menu.c`

![](batch3/4.png)

- we add auxiliary functions in the commands table

![](batch3/5.png)

- we implement the auxiliary functions

![](batch3/6.png)

- add options for our fucntion to menu

![](batch3/7.png)

- and now let's recompile the kernel and see our new functions in the menu

![](batch3/9.png)

- let's try our calculator

![](batch3/10.png)

- and let's try the other function

![](batch3/11.png)
