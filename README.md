# pp6calculator - A Simple command line calculator

### Authors

- Rhys Owen

### also including `FileReader-1.0.0` by

- Andrew Bennieston
- Tom Latham
- Ben Morgan
- Mark Slater


### Installation

For Linux OS

	$ git clone https://github.com/rhyseowen/pp6calculator.git pp6calculator.git
	$ mkdir pp6calculator.build
	$ cd pp6calculator.build
	$ cmake ../pp6calculator.git
	$ make

If `doxygen` is installed documentation can be generated with

	$make doc

Run With

	$./pp6Calculator

## Usage


On running the program you are prompted to select a menu. Operations are sorted by the week they were featured in the [c++ course](http://www2.warwick.ac.uk/fac/sci/physics/research/epp/resources/teaching/software_development_2014/)

Currently Available menus are:

    1) weekone : week one (arithmatic)
    2) weektwo : week two (data operations)

### Week One: Arithmatic

Within the week one menu available operations are:

	1) + : Simple addition of two numbers
	2) - : Simple subtraction of two numbers
	3) / : Simple division of two numbers
	4) * : Simple multiplication of two numbers
	5) solveAxis : Find the x-intercept of a straigt line
	6) solveQuadratic : find the real roots of a quadratic equation
	7) 3VectorLength : find the length of a 3 vector
	8) 4VectorLength : find the length of a 4 vector
	9) invarientMass : find the invarient mass of a momentum 4 vector
	h) help : Show this message
	u) up : Go up one menu level
	q) quit : exit the calculator

### Week Two: Data Operations

Within the week two menu available operations are:

	1) swap : swap 2 numbers
	2) sort : sort 8 numbers
	3) vectorSort : sort 8 numbers (using a vector instead of an array)
	4) generateMuons : Generate 100 random muons
	5) readInMuons : Read in muons from file
	h) help : Print this Message
	u) up : Go up one menu level
	q) quit : exit the calculator

### Return Codes
If the program encounters an error and is subsequently quit it will return one of the following codes.

    0 - Success
    2 - Operator not recognised
    3 - Divide by 0
    4 - Input File contains too many muons
