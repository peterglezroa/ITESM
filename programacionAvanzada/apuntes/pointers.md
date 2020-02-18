Pointers
===
A pointer is just the address of a piece of data in memory.

### Syntax
#### Declaring a pointer
<pre><code>int ar[4], *ip;  
ip = &ar[3]
</code></pre> 
In the example: we declare an array in which ar is a pointer to where the memory starts. We also declare the ip pointer and then give it the address for the third element of the array.

![pointer declariation][pointercode]  

#### Access what it is pointing
<pre><code>main(){
  int x, *p;
  p = &x; /* initialise pointer */
  *p = 0; /* set x to 0 */
  (*p)++; /* increment value of x */
  x++; /* increment value of x */
}
</code></pre>

To access the information of what it is being pointed at, we use the operand **\***.

### Qualified types 
#### Const
If it is prefixed with the keyword _const_:
* You must not attempt to modify it.
* This helps when using pointers because it protects them from accidentaly modifying them.
* If a variable declared outside of a function (as global variable) it is saved in the global part of the memory.  
<pre><code>int i                         /* i is an ordinary int */
const int ci = 1;             /* ci is a constant int */
int *pi;                      /* pi is a pointer to an int */
const int *pci;               /* pci is a pointer to a constant int */
int *const cpi = &i           /* cpi is a constant pointer to an int */
const int *const cpci = &ci;  /* cpci is a constant pointer to an constant int */
</code></pre>

#### Volatile
* If a variable is declared inside the main it is saved in the stack. To access the address of information we use the **_&_** operator.  
<br>
![memory structure][memory]  

### Void, null and dubious pointers
**¡¡¡ Pointers of different types are not the same! There are not implicit conversions from one to the other !!!!**

#### Void pointer
* It doesn't point to anything
* Can have the value of any other pointer assigned to and can be assigned to any other pointer.

#### Null pointer
<pre><code>int *p = 0;</code></pre>
* It is guaranteed not to point to any object.
* Good practice -> failure by a function (than returns a pointer) return this type of pointer.


[memory]: ../img/memorystruct.png
[pointercode]: ../img/pointerdeclaration.png
