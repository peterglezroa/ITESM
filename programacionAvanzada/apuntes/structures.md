Structures and Unions
====
Struct: A new type of object which can be used in your program. The whole thing is introduced by the _struct_ keyword, which is followed by an optional identifier know as the _tag_.
* The only operation permitted on whole structures is assignment.
* Takes the the amount of memory of the sum of all its variables.

Union: Its like a structure but you can only use one of the variables. But you can only use one of the variables.
* Used when something is going to change.
* Takes the amount of memory of its largest variable.
* It's like defining the posible variables but only using one.

### Syntax

#### Declaration
<pre><code>struct book{
  long id;
  char[20] name;
  short section;
}

union author{
  long id;
  char[20] name;
  char[20] country;
}
</code></pre>

To declare a variable with this structure:
<pre><code>struct book book;
book.id = 123456;
book.name = "Coso";
book.section = 3;

union author author;
author.id = 987654;
author.name = "Edgar Allan Poe";
author.country = "United States"
</code></pre>
This declares the variable _book_ of the struct _book_.


### Pointers to structures
* It is better to use pointers to structures than to use the structures directly.  
<pre><code>struct book *book;</code></pre>
* To access the attributes of the structure:
<pre><code>book->name = "Coso súper chingón";
</code></pre>
