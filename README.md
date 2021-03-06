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

## Provided Classes

The packages provides several classes for use

 - Particle
 - FourVector
 - ThreeVector

Detailed documentation can be found [here](http://rhyseowen.github.io/pp6calculator/)

## Usage


On running the program you are prompted to select a menu. Operations are sorted by the week they were featured in the [c++ course](http://www2.warwick.ac.uk/fac/sci/physics/research/epp/resources/teaching/software_development_2014/)

Currently Available menus are:

    1) weekone : week one (arithmatic)
    2) weektwo : week two (data operations)
    3) weekthree : week three (Four vector manipulation)
    4) weekfour : week four (Templates)

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

### Week Three: Object Orientation

Within the week three menu available operations are:

	1) interval : Calculate the interval of a 4 vector
	2) boost_z : boost a four vector along the z axis
	3) generateMuons: Generate Muons and use the particle class
	4) readInMuons: Read in muons from file, use particle class
	h) help : Print this Message
	u) up : Go up one menu level
	q) quit : exit the calculator

### Week Four: Templates and STL

Within the week four menu available operations are:

	1) pdg : print values from pdg database
	2) algo : use STL algorithms
	3) readinmuons : Read in muons from file and print out the 10 pairs with highest invarient mass
	h) help : Print this Message
	u) up : Go up one menu level
	q) quit : exit the calculator

### Return Codes
If the program encounters an error and is subsequently quit it will return one of the following codes.

    0 - Success
    2 - Operator not recognised
    3 - Divide by 0
    4 - Input File contains too many muons
