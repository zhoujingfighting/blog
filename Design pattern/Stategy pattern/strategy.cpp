/**
 * A class Human, have three action
 * eat, laugh, shout
 *
 * but action eat can have different action according to different human entity
 * same as laugh shout
 *
 */
#include <iostream>

/// @brief  base interface for eat
class Eat {
public:
  virtual void eat() = 0;
};

/// @brief base interface for laugh
class Laugh {
public:
  virtual void laugh() = 0;
};

/// @brief base interface for shout
class Shout {
public:
  virtual void shout() = 0;
};

/// @brief human class with three different actions
class Human {
  Eat *CustomizedEat;
  Laugh *CustomizedLaugh;
  Shout *CustomizedShout;
public:
  Human(Eat *Eat, Laugh *Laugh, Shout *Shout)
      : CustomizedEat(Eat), CustomizedLaugh(Laugh),CustomizedShout(Shout){}
public:
	void eat(){
		CustomizedEat->eat();
	}

	void laugh() {
		CustomizedLaugh->laugh();
	}

	void shout() {
		CustomizedShout->shout();
	}
};


/****************** Implementation of above abstract class *********************
 * 
*******************************************************************************/

class EatApple : public Eat {
public:
	void eat () {
		std::cout << "I'm eating apple!!" << std::endl;
	}
};

class EatBanana : public Eat {
public:
	void eat () {
		std::cout << "I'm eating banana!!" << std::endl;
	}
};

class LaughLightly : public Laugh {
public:
	void laugh() {
		std::cout << "I'm laughing slightly!!" << std::endl;
	}
};

class LaughLoudly : public Laugh {
public:
	void laugh() {
		std::cout << "I'm laughing Loudly!!" << std::endl;
	}
};

class ShoutLightly : public Shout {
public:
	void shout() {
				std::cout << "I'm shouting slightly!!" << std::endl;
	} 
};

class ShoutLoudly : public Shout {
public:
	void shout() {
				std::cout << "I'm shouting loudly!!" << std::endl;
	} 
};


/************************* testing the strategy pattern ************************
 * 
*******************************************************************************/

int main(){
	Human human1(new EatApple(), new LaughLightly(), new ShoutLightly());
	Human human2(new EatBanana(), new LaughLightly(), new ShoutLightly());
	human1.eat();
	human2.eat();
	//output
	//I'm eating apple!!
	// I'm eating banana!!
	return 0;
}