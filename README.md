# logi-lang
Logic language implementation

This is an implementation of logilang - logic language created by me as a part of internship training task.
## Syntax
Each command takes one line, and looks like this

`varName = operator(arg1,arg2,...,argN)`

Comment lines start with semicolon `;`

Operators for each variable are combined using logical OR

## Operators
There are three supported operators:
### true()
This operator defines given variable as true.
Example:

`alwaysTrueVar = true()`

### request()
This operator requests a value from user when evaluated for first time.
Example:

`requestedVar = request()`

### conditional(var1, var2,...,varN)
This operator evaluates to true if all variables given as arguments are true. In other words it computes logical AND between all given variables
If variable given to it does not exist, this variable is evaluated as false
Example:

`conditionalVar = conditional(alwaysTrueVar, requestedVar)`

## Additional info
* Nested operators are not supported e.g. `var = conditional(true(),var2)` is not a valid command
* There are cyclic definitions checks implemented e.g.
```
var1 = conditional(var2)
var2 = conditional(var1)
```
Would trigger a cyclic definition error
* Comments are only allowed starting from new line
