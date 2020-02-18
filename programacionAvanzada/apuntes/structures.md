Structures
====
A new type of object which can be used in your program. The whole thing is introduced by the _struct_ keyword, which is followed by an optional identifier know as the _tag_.
* The only operation permitted on whole structures is assignment.

### Syntax

#### Declaration
<pre><code>struct book{
  long id;
  char[20] name;
  short section;
}</code></pre>

To declare a variable with this structure:
<pre><code>struct book book;
book.id = 123456;
book.name = "Coso";
book.section = 3;
</code></pre>
This declares the variable _book_ of the struct _book_.


### Pointers to structures
* It is better to use pointers to structures than to use the structures directly.  
<pre><code>struct book *book;</code></pre>
* To access the attributes of the structure:
<pre><code>book->name = "Coso súper chingón";

