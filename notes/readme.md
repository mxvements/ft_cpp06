# cpp d06

## introduction

## type conversion

```c++
int		a = 42;
double	b = a 			// Implicit cast: the compiler does if for us
double	c = (double)a 	// Explicit cast

/*
There is some hierarchy on types, int is the smallest, then double then float. Int is the smallest on memory, also the less precise
This is because of the representation of the numbers in memory, doubles and floats are represented on scientific notation
*/
double	d = a;			// Implicit promotion (int -> double)
int		e = d;			// Implicit demotion (double _> int), 
						// can be hazardous or just a programming mistake, we probable didn't noticed the type and we loss information
int		f = (int)d		// Explicit demotion (double -> int), but we're in charge
``` 
`-Wconversion -Werror=conversion` warns abouut implicit conversions on ggc/clang compilation, check if it's available on our version

## type reinterpretation (2nd cast action)

+ identity conversion o reinterpretation: type conversion that does not change the type of an object. Essentially, the type remains the same, and no actual conversion occurs. The value keeps the same bits after conversion in the same order, there is no actual conversion.

note: the float * is a higher type than void * (higher: more precision)

```c++
float	a = 420.042f;		// Reference value

void	*b = &a;			// Implicit reinterpretation cast
void	*c = (void *)&a;	// Explicit  reinterpretation cast

void	*d = &a;			// Implicit promotion -> ok
int		*e = d;				// Implicit demotion (reinterpret float* to int*, even though we use void*) -> hazardous
int		*f = (int *) d;		// Explicit demotion -> ok, i obey
```
if we print `a` and `f`, from the pointers, we get different outputs, the compiler reinterprets them directly, without conversion
`a` prints `420.041992`
`f` prints `1137837408`
we still get the notion of hierarchy through the pointers:
+ there's no problem to lose accuracy (float* -> void*)
+ we need to be very careful when regaigning precision (void* -> int*)

NOTE: avoid implicit syntax, always use explicit conversion to tell other users what you are doing

## type qualifier reinterpretation (3rd cast action)

+ type qualifier cast: like `const` or `volatile`

```c++
int		a = 42;

int const	*b = &a;				// Implicit type qualifier cast
int const	*c = (int const *)&a;	// Explicit type qualifier cast

int const	*d = &a;				// Implicit promotion -> Ok
int			*e = d;					// Implicit demotion -> Hell no
int			*f = (int *) d;			// Explicit demotion -> Ok, I obey
```
If you try to go from a const address from a non const one, it won't compile, you need to demote the type explicitely.
The compiler protects the const int, if you demote the pointer implicitely you would be able to write in a readonly variable.

It's very disadvised to change the type qualifier of a pointer.

## upcast and downcast (c++ context)

reinterpreation -> identity conversion

type hierarchy though inheritance

```c++
Class Parent					{};
Class Child1 : public Parent	{};
Class Child2 : public Parent	{};

Child1		a;					// Reference value

Parent		*b = &a;			// Implicit reinterpretaton cast
Parent		*c = (Parent *)&a;	// Explicit reinterpreation cast

Parent		*d = &a;			// Implicit upcast -> OK
Child1		*e = d;				// Implicit downcast -> hell NO -> does not compile!
Child2		*f = (Child2 *)d;	// Explicit downcast -> OK, but really?, wont't run properly
```
## c++ casts
+ static cast
+ dynamic cast
+ reinterpret cast
+ const cast

### static cast

the most visual cast in cpp

keyword: `static_cast<T>`

+ syntax: `static_cast<new_type>(expression)`


```c++
int		a = 42;						// Reference value

double 	b = a;						// Implicit promotion > ok
int		c = b;						// Implicit demotion -> Hell no!
int		d = static_cast<int>(b);	// Explicit demotion  -> Ok, I obey
```

```c++
Class Parent					{};
Class Child1 : public Parent	{};
Class Child2 : public Parent	{};
Class Unrelated					{};

Child1		a;									// Reference value

Parent		*d = &a;							// Implicit upcast -> OK
Child1		*e = d;								// Implicit downcast -> hell NO -> does not compile!
Child2		*f = static_cast<Child2 *>(d);		// Explicit downcast -> OK, I obey, can be a problem too

Unrelated	*e = static_cast<Unrelated *>(&a);	// Explicit conversion -> NO !
```

## dynamic cast

the most interesting
+ it's the only happening at runtime
+ it only works with polymorphic instances
+ syntax: `dynamic_cast<new_type>(expression)`

```c++
class Parent	{public: virtual ~Parent(void) {}};
class Child1: public Parent	{};
class Child2: publiic Parent {}

Child1	a;			//Reference value
Parent	*b = &a;	//Implicit upcast -> ok

//Explicit downcast with pointer -> suspens... -> it compiles and runs
Child1	*c = dynamic_cast<Chidl1 *>(b);
if (c == NULL){
	std::cout << "Conversion NOT ok" << st::endl;
} else {
	std::cout << "Conversion ok" << st::endl;
}

//Explicit downcast with reference -> suspens... -> it compiles when at runtime it throws and error
try {
	Child2	&c = dynamic_cast<Chidl2 &>(*b);
} catch ( std::bad_cast &bc) {
		std::cout << "Conversion NOT ok" << st::endl;
}

```

### reinterpret cast

+ allows converting one pointer type to another, even when the types are completely unrelated
+ reinterpret any address as any other address
+ it does not perform any runtime checks
+ syntax:  `reinterpret_cast<new_type>(expression)

```c++
float	a = 420.042f;
void	*b = &a;
int		*c = reinterpret_cast<int *>(b);
int		&d = reinterpret_cast<int &>(b);
```

### const cast

+ (the last cpp cast)
+ transform the type qualifyer
+ syntax: `const_cast<new_type>(expression)`

```c++
int		a = 42;	//reference value

int const 	*b = &a; 					// implicit promotion
int			*c = b;						// implicit demotion -> hell no!
int			*d = const_cast<int *>(b);	// explicit demotion -> ok, i obey
```

## cast operators

+ type cast operators, new syntax that allows to deine in our clases implicit casts to a type we're interested in
+ syntax:  `opertator type()`

```c++
class Foo {

	private:
		float	_v;

	public:
		Foo(float const v) : _v(v) { }
		float	getv(void) 	{return this->_v;}
		
		operator float()	{return this->_v;}
		operator int()		{return static_cast<int>(this->_v);}

}
```

## explicit keyword

+ `keyword<type>()` is pretty similar to a function call
+ constructor are conceptually closed to the cast, when we give some parameters we get an object of a different type
+ 

```c++
class A {};
class B {};

class C {
	public: 
					C(A const & _) {return ;}	// constructor, implicit conversion from A to C
		explicit	C(B const & _ ) {return ;}	// constructor, explicit conversion from B to C

};


void f(C const & _ ){
	return ;
}


int main(void){
	f( A() ); // implicit conversion OK
	f( B() ); // implicit conversion NOT OK, constructor is explicit
	f( C(B()) ); //explicit constructor -> OK
}
```

## conclusion
+ 