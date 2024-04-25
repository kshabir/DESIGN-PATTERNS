# DESIGN-PATTERNS

Key Design Patterns:

1. Singleton/ One Wife Pattern
2. Strategy Pattern
3. Facade Pattern
4. Observer Pattern
5. Bridge/Adapter Pattern
6. Decorator Pattern


Structural Design Patterns: are concerned with how classes and objects are composed to form larger structures.

1. Adapter("Act as a translator")-->Components: client code -->target interface -->adapter -->adaptee (legacy code/3rd party code/lib).
2. Bridge("It separates abstraction from it's implementation")--> Components: Abstraction (act as bridge), Refined Abstraction, Implementor, Concrete Implementor
3. Decorator("dynamic addition of new behaviors or responsibilities to individual objects without altering their underlying class structure") -->
Components: Component Interface--> Concrete Components, Decorator Interface(it also implement component interface) --> Concrete Decorators
3. Facade("provides a simplified and unified interface to a set of interfaces or subsystems") --> Components: subsystem1, subsystem2, Facade
Usage: Having a facade is handy when you need to integrate your app with a sophisticated library that has dozens of features, but you just need a tiny bit of its functionality.
4. Singleton("Only one instance [a global point of contact] of a class exist throughout the system")--> Components: Singelton Class (private constructor, destructor and static member variable), private static member variable(initialized [called lazzy initialization] two ways 1. nullptr or an instance of the class intself), public static Method (It ensures there is only one instance of the class. It gives an instance of the class), Deleted copy constructor and assignment operator.
5. Observer("defines a one-to-many dependency between objects, meaning that when one object (the subject) changes its state, all its dependents (observers) are notified and updated automatically") --> Components: Subject [contains list of observers], Observer, concrete Subject, Concrete Observer 



NOTES: Object Pool is a good alternative to singelton.
