Goal: Make a pond simulation with fish that hunt for randomly placed food.
	The GA will create the best fish to survive the pond, and will be
	considered the best by winning multiple trials.  This project
	can also go into balancing the traits with an ideal split between 
	them all.

Chromosome: 60 attribute points are randomly spent on 6 characteristics.
	Speed: Max speed the fish can swim.
	Smell: How far away the fish can locate food.
	Size: Largeness of fish.  Larger fish can eat smaller ones.
	Curiosity: How close they are willing to get close to a bigger fish.
	Survivability: How long it can last without food and health.
	Aggresiveness: Willing to kill another fish.

	The Chromosome will have a string of 60 tokens representing these traits.
	For example, a fish might have 10 speed, 5 smell, 15 size, 20 curiosity, 
	5 survivability, and 5 aggressiveness

Fitness Function: Simply, whatever fish survives the longest.

Simulation: The screen is a 2D pond.  A fish is created in each corner.
	Each fish begins by moving towards the center while randomly moving up and down.
	Food is randomly created around the screen. Health goes down, and gains a boost
	when food is eaten.  If health reaches 0, the fish dies.
	Speed determines how fast the fish will move around.
		0, it cannot move, 60 it can diagnolly cross the screen in 1 second.
	Smell gives the radius it can sense food.
		0, it cannot sense, 60 the whole screen.
	Size determines if it can eat a live or dead fish
		Must be 1.5x the size of the living fish. 
		Must be equal or greater of the dead fish.
	Curiosity determines how close it will get close to a larger fish.
		Take difference in size.  Twice the difference is default radius.
		Curiosity decreases the radius a fish will avoid a larger fish.
	Survivability is its max and starting health.
	Aggresiveness is how likely it will attack another fish and damage it does.
		Increases radius it will chase fish and attack once in range.

	The characteristics present two archetypes of fish.
	A Fast, large smell, small, moderate curiosity, moderate survivability, and low aggro.
	A slower, small smell, larger, curious, tanky, aggressive predator.


		
	