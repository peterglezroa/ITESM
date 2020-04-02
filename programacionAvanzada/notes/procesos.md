Procesos
====
C Program main prototype function:
```c
int main(int argc, char *argv[]);
```

### Recaps
* When the parent process ends and does not wait for the child, then the process child becomes a zombie.
* It's better to use `waitid`, because the moment in which `wait()` receives any signal of a child it ends (it does not matter the amount of childs it has).
